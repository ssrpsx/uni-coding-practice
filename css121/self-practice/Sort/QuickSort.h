#include <bits/stdc++.h>
#include "basic-sort.h"

using namespace std;
BasicSort<int> bis;

class QuickSort
{
    public :
        void ft_Quicksort(vector<int> &arr, int left, int right)
        {
            if(left < right)
            {
                int part = partition(arr, left, right);
                ft_Quicksort(arr, left, part - 1);
                ft_Quicksort(arr, part + 1, right);
            }
        }
    private :
        int partition(vector<int> &arr, int left, int right)
        {
            int pivot = arr[right];
            int i = left - 1;

            for(int j = left; j < right; j++)
            {
                if(arr[j] < pivot)
                {
                    bis.ft_swap(arr[++i], arr[j]);
                }
            }

            bis.ft_swap(arr[++i], arr[right]);
            return i;
        }
};