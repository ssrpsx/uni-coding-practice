#include <functional>

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
            node *copy(node *n)
            {
                if (n == nullptr)
                    return nullptr;
                node *left = copy(n->left);
                node *right = copy(n->right);
                node *result = new node(n->data, left, right, nullptr);
            }

            void clear(node *n)
            {
                if (n == nullptr)
                    return;

                clear(n->left);
                clear(n->right);

                delete n;
            }
        };

        class iterator_tree
        {
        protected:
            iterator_tree ptr;

        public:
        };

        node *mRoot;
        CompareT mLess;
        size_t mSize;

    public:
        typedef iterator_tree iterator;

        map_bst(const CompareT &c = CompareT) : mRoot(nullptr), mLess(c), mSize(0) {};
        map_bst(const map_bst<k, m, c> &other) : mLess(other.mLess), mSize(other.msize)
        {
            mRoot = copy(other.mRoot);
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

        iterator find(const keyT& data)
        {
            node *parent;
            node *ptr = find_node(data, mRoot, parent);
            return ptr == nullptr ? end() : iterator(ptr);
        }

        node *find_node(const keyT& data, node* root, node* parent)
        {
            node* ptr = root;
            while (ptr != nullptr)
            {
                int cmp = compare(data, ptr->data.first);
                if(cmp == 0) return ptr;

                parent = ptr;
                ptr = cmp > 0 ? ptr->right : ptr->left;
            }
            
            return nullptr;
        }

        int compare(const keyT& k1, const keyT& k2)
        {
            if(mLess(k1, k2)) return -1;
            if(mLess(k2, k1)) return +1;

            return 0;
        }
    };
}