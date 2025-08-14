#include <functional>
#include <utility>
#include <iostream>

namespace CP
{
    template <typename T, typename comp = std::less<T>>
    class priority_queue
    {
    protected:
        T *mData;
        size_t mSize;
        size_t mCap;
        comp mLess;

        void expand(size_t capacity)
        {
            T *arr = new T[capacity]();
            for (size_t i = 0; i < mSize; i++)
            {
                arr[i] = mData[i];
            }

            delete [] mData;
            mData = arr;
            mCap = capacity;
        }

        void fixUp(size_t idx)
        {
            T tmp = mData[idx];

            while (idx > 0)
            {
                size_t p = (idx - 1) / 2;
                if(mLess(tmp, mData[p])) break;

                mData[idx] = mData[p];
                idx = p;
            }

            mData[idx] = tmp;
        }
        
        void fixDown(size_t idx)
        {
            T tmp = mData[idx];
            size_t check;

            while ((check = idx * 2 + 1) < mSize)
            {
                if(check + 1 < mSize && mLess(mData[check], mData[check + 1])) check++;
                if(mLess(mData[check], tmp)) break;

                mData[idx] = mData[check];
                idx = check;
            }

            mData[idx] = tmp;
        }

    public:
        priority_queue(const comp &c = comp()) : mData(new T[1]()),
                                                 mSize(0),
                                                 mCap(1),
                                                 mLess(c) {};

        priority_queue(priority_queue<T, comp> &q) : mData(new T[q.mCap]()),
                                                     mSize(q.mSize),
                                                     mCap(q.mCap),
                                                     mLess(q.mLess)
        {
            for (size_t i = 0; i < q.mSize; i++)
            {
                mData[i] = q.mData[i];
            }
        }

        priority_queue<T, comp> &operator=(priority_queue<T, comp> other)
        {
            using std::swap;

            swap(mData, other.mData);
            swap(mSize, other.mSize);
            swap(mCap, other.mCap);
            swap(mLess, other.mLess);

            return *this;
        }

        ~priority_queue()
        {
            delete[] mData;
        }

        bool empty() const
        {
            return mSize == 0;
        }

        size_t size() const
        {
            return mSize;
        }

        const T& top()
        {
            return mData[0];
        }

        void push(const T &element)
        {
            if(mSize + 1 > mCap)
            {
                expand(mCap * 2);
            }

            mData[mSize] = element;
            mSize++;

            fixUp(mSize - 1);
        }

        void pop()
        {
            mData[0] = mData[mSize - 1];
            mSize--;
            fixDown(0);
        }

        //for debug
        void show()
        {
            for(size_t i = 0; i < mSize; i++)
            {
                std::cout << mData[i] << std::endl;
            }
        }
    };
}