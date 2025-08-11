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
            if(n < 0 || size_t(n) >= mSize)
            {
                throw std::out_of_range("index out of range");
            }
        }

        void expand(size_t capacity)
        {
            T *arr = new T[capacity]();
            for(size_t i = 0; i < mSize; i++)
            {
                arr[i] = mData[i];
            }
            delete [] mData;
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
            delete [] mData;
        }

        vector(const vector<T> &a)
        {
            mData = new T[a.capacity()]();
            mSize = a.size();
            mCap = a.capacity();
            for(size_t i = 0; i < a.size(); i++)
            {
                mData[i] = a[i];
            }
        }

        vector<T>& operator=(vector<T> &other)
        {
            if(mData != other.mData)
            {
                delete [] mData;

                mData = new T[other.capacity()]();
                mCap = other.capacity();
                mSize = other.size();

                for(size_t i = 0; i < other.size(); i++)
                    mData[i] = other[i];
            }

            return *this;
        }

        //capacity
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

        //access
        T& at(int index)
        {
            rangeCheck(index);
            return mData[index];
        }
        T& operator[](int index)
        {
            return mData[index];
        }

        //modifier
        void push_back(const T &data)
        {
            checkCapacity(mSize+1);
            mData[mSize++] = data;
        }

        void pop_back()
        {
            mSize--;
        }
    };
}