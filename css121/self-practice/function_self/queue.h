#include <utility>

namespace CP
{
    template <typename T>
    class queue
    {
    protected:
        T *mData;
        size_t mSize;
        size_t mCap;
        size_t mFront;

        void expand(size_t capacity)
        {
            T* arr = new T[capacity]();
            for(size_t i = 0; i < mSize; i++)
            {
                arr[i] = mData[(mFront + i) % mCap];
            }

            delete [] mData;
            mData = arr;
            mCap = capacity;
            mFront = 0;
        }

        void ensureCapacity(size_t capacity)
        {
            if (capacity > mCap)
            {
                size_t s = (capacity > mCap * 2) ? capacity : mCap * 2;
                expand(s);
            }
        }

    public:
        queue() : mData(new T[1]()),
                  mSize(0), mCap(1), mFront(0) {};
        queue(const queue<T> &a) : mData(new T[a.mCap]()),
                                   mSize(a.mSize), mCap(a.mCap), mFront(a.mFront)
        {
            for (size_t i = 0; i < a.mSize; i++)
                mData[i] = a.mData[i];
        }
        ~queue() { delete [] mData; }

        queue<T>& operator=(queue<T> other)
        {
            using std::swap;

            swap(mData, other.mData);
            swap(mSize, other.mSize);
            swap(mCap, other.mCap);
            swap(mFront, other.mFront);

            return *this;
        }
        
        bool empty() const 
        {
            return mSize == 0;
        }

        size_t size() const
        {
            return mSize;
        }

        const T& front() const
        {
            return mData[mFront];
        }

        const T& back() const
        {
            return mData[(mFront + mSize - 1) % mCap];
        }

        void push(const T& element)
        {
            ensureCapacity(mSize + 1);
            mData[(mFront + mSize) % mCap] = element;
            mSize++;
        }
        
        void pop()
        {
            mFront = (mFront + 1) % mCap;
            mSize--;
        }
    };
}