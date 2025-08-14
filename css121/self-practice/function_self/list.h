#include <utility>

namespace CP
{
    template <typename T>
    class list
    {
    protected:
        class node
        {
            friend class list;

        public:
            T data;
            node *prev, *next;

            node() : data(T()), prev(this), next(this) {}
            node(const T &a, node *prev, node *next) : data(T(a)),
                                                       prev(prev),
                                                       next(next)
            {
            }
        };

        class list_iterator
        {
            friend class list;

        public:
            node *ptr;

            list_iterator() : ptr(nullptr) {};
            list_iterator(node *a) : ptr(a) {};

            list_iterator &operator++()
            {
                ptr = ptr->next;
                return (*this);
            }

            list_iterator &operator--()
            {
                ptr = ptr->prev;
                return (*this);
            }

            list_iterator operator++(int)
            {
                list_iterator tmp(*this);
                operator++();
                return tmp;
            }

            list_iterator operator--(int)
            {
                list_iterator tmp(*this);
                operator--();
                return tmp;
            }

            T &operator*()
            {
                return ptr->data;
            }

            T &operator->()
            {
                return &(ptr->data);
            }

            bool operator==(const list_iterator &other)
            {
                return ptr == other.ptr;
            }

            bool operator!=(const list_iterator &other)
            {
                return ptr != other.ptr;
            }
        };

    protected:
        node *mHeader;
        size_t mSize;

    public:
        typedef list_iterator iterator;

        // constructor & destructor
        list() : mHeader(new node()), mSize(0) {};

        list(const list<T> &a) : mHeader(new node()),
                                 mSize(0)
        {
            for (iterator it = a.begin(); it != a.end(); it++)
            {
                push_back(*it);
            }
        }

        list<T> &operator==(list<T> other)
        {
            using std::swap;

            swap(mHeader, other.mHeader);
            swap(mSize, other.mSize);

            return (*this);
        }

        ~list()
        {
            clear();
            delete mHeader;
        }

        // capacity function
        bool empty() const { return mSize == 0; }
        size_t size() const { return mSize; }

        // access
        T &front() const { return mHeader->next->data; }
        T &back() const { return mHeader->prev->data; }

        // modifie
        iterator insert(iterator it, const T &element)
        {
            node *n = new node(element, it.ptr->prev, it.ptr);
            it.ptr->prev->next = n;
            it.ptr->prev = n;

            mSize++;
            return iterator(n);
        }

        iterator erase(iterator it)
        {
            iterator tmp(it.ptr->next);

            it.ptr->prev->next = it.ptr->next;
            it.ptr->next->prev = it.ptr->prev;

            delete it.ptr;
            mSize--;

            return tmp;
        }

        iterator begin()
        {
            return iterator(mHeader->next);
        }

        iterator end()
        {
            return iterator(mHeader);
        }

        void clear()
        {
            while (mSize > 0)
            {
                erase(begin());
            }
        }

        void push_back(const T &element)
        {
            insert(end(), element);
        }

        void push_front(const T &element)
        {
            insert(begin(), element);
        }

        void pop_back()
        {
            erase(iterator(mHeader->prev));
        }

        void pop_front()
        {
            erase(begin());
        }
    };

}