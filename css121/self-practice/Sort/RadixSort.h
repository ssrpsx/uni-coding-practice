#include <vector>
#include <iostream>

using namespace std;

class RadixSort
{
    public:
        void radixSort(vector<int> &arr)
        {
            int maxVal = ft_maxval(arr);

            for(int exp = 1; maxVal / exp > 0; exp *= 10)
            {
                countSort(arr, exp);
            }
        }

    private:
        int ft_maxval(vector<int> &arr)
        {
            int pivot = 0;
            for(int num : arr)
            {
                if(pivot < num)
                {
                    pivot = num;
                }
            }
            return pivot;
        }
        
        void countSort(vector<int> &arr, int exp)
        {
            int i, index, count[10] = {0}, n = arr.size();
            vector<int> output(n);

            for(i = 0; i < n; i++)
            {
                count[(arr[i] / exp) % 10]++;
            }

            for(i = 1; i < 10; i++)
            {
                count[i] += count[i - 1];
            }

            for(i = n - 1; i >= 0; i--)
            {
                index = (arr[i] / exp) % 10;
                output[--count[index]] = arr[i];
            }

            for(i = 0; i < n; i++)
            {
                arr[i] = output[i];
            }
        }
};