namespace CP
{
    template <typename T>
    class stack
    {
    protected:
        T *mData;
        size_t mSize;
        size_t mCap;

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
            size_t s = (capacity > mCap * 2) ? capacity : mCap * 2;
            expand(s);
        }

    public:
        stack()
        {
            int cap = 1;
            mCap = cap;
            mSize = 0;
            mData = new T[cap]();
        }

        ~stack()
        {
            delete[] mData;
        }

        bool empty() const
        {
            return mSize == 0;
        };

        size_t size() const
        {
            return mSize;
        }

        //modifier

        void push(const T& element)
        {
            checkCapacity(mSize + 1);
            mData[mSize++] = element;
        }

        void pop()
        {
            mSize--;
        }

        const T& top() const
        {
            return mData[mSize - 1];
        }
    };
}