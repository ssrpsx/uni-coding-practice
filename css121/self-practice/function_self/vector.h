namespace CP
{
    template <typename T>
    class vector
    {
    protected:
        T *mData;
        size_t mCap;
        size_t mSize;

        void rangeCheck(int n)
        {
            if (n < 0 || size_t(n) >= mSize)
            {
                throw std::out_of_range("index out of range");
            }
        }

        void expand(size_t capacity)
        {
            T *arr = new T[capacity]();
            for (size_t i = 0; i < mSize; i++)
            {
                arr[i] = mData[i];
            }
            delete[] mData;
            mData = arr;
            mCap = capacity;
        }

        void checkCapacity(size_t capacity)
        {
            if (capacity > mCap)
            {
                size_t s = (capacity > mCap * 2) ? capacity : mCap * 2;
                expand(s);
            }
        }

    public:
        typedef T *iterator;
        // constructor & copy operator
        vector()
        {
            int cap = 1;
            mCap = cap;
            mSize = 0;
            mData = new T[cap]();
        }

        vector(size_t cap)
        {
            mCap = cap;
            mSize = cap;
            mData = new T[cap]();
        }

        ~vector()
        {
            delete[] mData;
        }

        vector(const vector<T> &a)
        {
            mData = new T[a.capacity()]();
            mSize = a.size();
            mCap = a.capacity();
            for (size_t i = 0; i < a.size(); i++)
            {
                mData[i] = a[i];
            }
        }

        vector<T> &operator=(vector<T> &other)
        {
            if (this != &other)
            {
                delete[] mData;

                mData = new T[other.capacity()]();
                mCap = other.capacity();
                mSize = other.size();

                for (size_t i = 0; i < other.size(); i++)
                    mData[i] = other[i];
            }

            return *this;
        }

        // capacity
        size_t size() const
        {
            return mSize;
        }

        bool empty() const
        {
            return mSize == 0;
        }

        size_t capacity() const
        {
            return mCap;
        }

        void resize(size_t n)
        {
            if (n > mCap)
            {
                expand(n);
            }
            mSize = n;
        }

        // access
        T &at(int index)
        {
            rangeCheck(index);
            return mData[index];
        }
        T &operator[](int index)
        {
            return mData[index];
        }

        // modifier
        void push_back(const T &data)
        {
            checkCapacity(mSize + 1);
            mData[mSize++] = data;
        }

        void pop_back()
        {
            mSize--;
        }

        iterator insert(iterator it, const T &element)
        {
            size_t pos = it - begin();
            checkCapacity(mSize + 1);

            for (size_t i = mSize; i > pos; i--)
            {
                mData[i] = mData[i - 1];
            }

            mData[pos] = element;
            mSize++;

            return begin() + pos;
        }

        void erase(iterator it)
        {
            while ((it + 1) != end())
            {
                *it = *(it + 1);
                it++;
            }
            mSize--;
        }

        void clear()
        {
            delete[] mData;
            mData = nullptr;
            mSize = 0;
        }

        // iterator
        iterator begin()
        {
            return &mData[0];
        }

        iterator end()
        {
            return begin() + mSize;
        }
    };
}