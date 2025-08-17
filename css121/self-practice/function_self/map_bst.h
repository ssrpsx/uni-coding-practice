#include <functional>
#include <iostream>

namespace CP
{
    template <typename keyT, typename mapT, typename CompareT = std::less<keyT>>
    class map_bst
    {
    protected:
        typedef std::pair<keyT, mapT> ValueT;
        class node
        {
            friend class map_bst;

        protected:
            ValueT data;
            node *left;
            node *right;
            node *parent;

            node() : data(ValueT()), left(nullptr), right(nullptr), parent(nullptr) {};
            node(const ValueT &a, node *left, node *right, node *parent) : data(a), left(left), right(right), parent(parent) {};

        public:
        };

        class iterator_tree
        {
        protected:
            node *ptr;

        public:
            iterator_tree() : ptr(nullptr) {}
            iterator_tree(node *p) : ptr(p) {}

            iterator_tree operator++()
            {
                if(ptr->right == nullptr)
                {
                    node *parent = ptr->parent;
                    while (parent != nullptr && parent->right == ptr)
                    {
                        ptr = parent;
                        parent = ptr->parent;
                    }
                    ptr = parent;
                }
                else
                {
                    ptr = ptr->right;
                    while (ptr->left != nullptr)
                    {
                        ptr = ptr->left;
                    }
                }

                return (*this);
            }

            iterator_tree operator--()
            {
                if(ptr->left == nullptr)
                {
                    node *parent = ptr->parent;
                    while (parent != nullptr && parent->left == ptr)
                    {
                        ptr = parent;
                        parent = ptr->parent;
                    }
                    ptr = parent;
                }
                else
                {
                    ptr = ptr->left;
                    while (ptr->right != nullptr)
                    {
                        ptr = ptr->right;
                    }
                }

                return (*this);
            }

            iterator_tree operator++(int)
            {
                iterator_tree tmp(*this);
                operator++();
                return tmp;
            }

            iterator_tree operator--(int)
            {
                iterator_tree tmp(*this);
                operator--();
                return tmp;
            }

            node *operator->()
            {
                return &(ptr->data);
            }

            ValueT &operator*()
            {
                return ptr->data;
            }

            bool operator==(const iterator_tree &other)
            {
                return ptr == other.ptr;
            }

            bool operator!=(const iterator_tree &other)
            {
                return ptr != other.ptr;
            }
        };

        node *mRoot;
        CompareT mLess;
        size_t mSize;

    private:
        node *copy(node *n, node *parent = nullptr)
        {
            if (n == nullptr)
                return nullptr;
            node *left = copy(n->left, nullptr);
            node *right = copy(n->right, nullptr);
            node *result = new node(n->data, left, right, parent);
            if (left)
                left->parent = result;
            if (right)
                right->parent = result;

            return result;
        }
        void clear(node *n)
        {
            if (n == nullptr)
                return;

            clear(n->left);
            clear(n->right);

            delete n;
        }

        void clear()
        {
            clear(mRoot);
            mRoot = nullptr;
            mSize = 0;
        }

        void print(node *n)
        {
            if (n == nullptr)
                return;

            print(n->left);
            std::cout << n->data.first << ":"
                      << n->data.second << " " << std::endl;
            print(n->right);
        }

        node *find_node(const keyT &data, node *root, node *&parent)
        {
            node *ptr = root;
            while (ptr != nullptr)
            {
                int cmp = compare(data, ptr->data.first);
                if (cmp == 0)
                    return ptr;

                parent = ptr;
                ptr = cmp > 0 ? ptr->right : ptr->left;
            }

            return nullptr;
        }

        int compare(const keyT &k1, const keyT &k2)
        {
            if (mLess(k1, k2))
                return -1;
            if (mLess(k2, k1))
                return +1;

            return 0;
        }

        node *&child_link(node *parent, const keyT &data)
        {
            if (parent == nullptr)
                return mRoot;
            return mLess(data, parent->data.first)
                       ? parent->left
                       : parent->right;
        }

        node *find_min_node(node *r)
        {
            node *cur = r;
            while (cur && cur->left != nullptr)
            {
                cur = cur->left;
            }

            return cur;
        }

    public:
        typedef iterator_tree iterator;

        map_bst(const CompareT &c = CompareT()) : mRoot(nullptr), mLess(c), mSize(0) {};
        map_bst(const map_bst<keyT, mapT, CompareT> &other) : mLess(other.mLess), mSize(other.msize)
        {
            mRoot = copy(other.mRoot, nullptr);
        }

        map_bst<keyT, mapT, CompareT> &operator=(map_bst<keyT, mapT, CompareT> other)
        {
            using std::swap;

            swap(mRoot, other.mRoot);
            swap(mLess, other.mLess);
            swap(mSize, other.mSize);

            return *this;
        }

        ~map_bst()
        {
            clear();
        }

        iterator find(const keyT &data)
        {
            node *parent;
            node *ptr = find_node(data, mRoot, parent);
            // return ptr == nullptr ? end() : iterator(ptr); will use later
            return ptr == nullptr ? iterator(0) : iterator(ptr);
        }

        std::pair<iterator, bool> insert(const ValueT &val)
        {
            node *parent = nullptr;
            node *ptr = find_node(val.first, mRoot, parent);

            bool not_found = (ptr == nullptr);
            if (not_found)
            {
                ptr = new node(val, nullptr, nullptr, parent);
                child_link(parent, val.first) = ptr;
                mSize++;
            }

            return std::make_pair(iterator(ptr), not_found);
        }

        // for debug
        void print()
        {
            print(mRoot);
        }

        size_t erase(const keyT &key)
        {
            if (mRoot == nullptr)
                return 0;
            node *parent = nullptr;
            node *ptr = find_node(key, mRoot, parent);
            if (ptr == nullptr)
                return 0;

            if (ptr->left != nullptr && ptr->right != nullptr)
            {
                node *min = find_min_node(ptr->right);
                node *&link = child_link(min->parent, min->data.first);
                link = (min->left == nullptr) ? min->right : min->left;
                if (link != nullptr)
                    link->parent = min->parent;

                std::swap(ptr->data.first, min->data.first);
                std::swap(ptr->data.second, min->data.second);
                ptr = min;
            }
            else
            {
                node *&link = child_link(ptr->parent, key);
                link = (ptr->left == nullptr) ? ptr->right : ptr->left;
                if (link != nullptr) link->parent = ptr->parent;
            }

            delete ptr;
            mSize--;
            return 1;
        }
        
        mapT &operator[](const keyT &key)
        {
            node *parent = nullptr;
            node *ptr = find_node(key, mRoot, parent);

            if (ptr == nullptr)
            {
                ptr = new node(std::make_pair(key, mapT()), nullptr, nullptr, parent);
                child_link(parent, key) = ptr;
                mSize++;
            }

            return ptr->data.second;
        }
    };
}