#include <vector>
#include "basic_sort.h"

using namespace std;

class BucketSort
{
    BasicSort<float> bis_float;
    public :
        void ft_bucketSort(vector<float> &arr)
        {
            int n = arr.size(), i, index;
            float check;
            vector<vector<float>> bucket(5);

            for(i = 0; i < n; i++)
            {
                check = arr[i];

                if(check == 1.0) check = 0.99;
                index = (int)(check * 5) % 5;
                bucket[index].push_back(arr[i]);
            }

            arr.clear();
            for(i = 0; i < 5; i++)
            {
                bis_float.ft_insertionSort(bucket[i]);
                cout << "Bucket[" << i << "] = ";
                for(float num : bucket[i])
                {
                    cout << num << " ";
                    arr.push_back(num);
                }
                cout << endl;
            }
            cout << endl;
        }
};