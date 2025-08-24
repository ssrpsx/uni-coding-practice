#include <vector>
#include <functional>

namespace CP
{
    template <typename KeyT, typename MappedT, typename HasherT = std::hash<KeyT>, typename EqualT = std::equal_to<KeyT>>
    class unorder_map
    {
    protected:
        typedef std::pair<KeyT, MappedT> ValueT;
        typedef std::vector<ValueT> BucketT;

        std::vector<BucketT> mBuckets;
        size_t mSize;
        HasherT mHasher;
        EqualT mEqual;
        float mMaxLoadFactor;

    public:
        unorder_map() : mBuckets(std::vector<BucketT>(11)), mSize(0), mHasher(HasherT()), mEqual(EqualT()), mMaxLoadFactor(1.0) {};

        unorder_map(const unorder_map<KeyT, MappedT, HasherT, EqualT> &other) : mBuckets(other.mBuckets), mSize(other.mSize), mHasher(other.mHasher), mMaxLoadFactor(other.mMaxLoadFactor) {};

        unorder_map<KeyT, MappedT, HasherT, EqualT> &operator=(unorder_map<KeyT, MappedT, HasherT, EqualT> other)
        {
            using std::swap;
            swap(this->mBuckets, other.mBuckets);
            swap(this->mEqual, other.mEqual);
            swap(this->mSize, other.mSize);
            swap(this->mHasher, other.mHasher);
            swap(this->mMaxLoadFactor, other.mMaxLoadFactor);

            return *this;
        }
        // not yet is done
    };
}