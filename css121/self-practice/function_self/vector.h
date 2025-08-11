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

        T& at(int index)
        {
            rangeCheck(index);
            return mData[index];
        }
        T& operator[](int index)
        {
            return mData[index];
        }

        void push_back(const T &data)
        {
            checkCapacity(mSize+1);
            mData[mSize++] = data;
        }

        void pop_back()
        {
            mSize--;
        }

        size_t size()
        {
          return mSize;  
        }

        bool empty()
        {
            return mSize == 0;
        }
    };
}