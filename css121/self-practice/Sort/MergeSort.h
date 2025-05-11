#include <bits/stdc++.h>
using namespace std;

class MergeSort{
    public:
        void ft_mergeSort(vector<int> &arr, int left, int right)
        {
            if(left < right)
            {
                int mid = left + (right - left) / 2;

                ft_mergeSort(arr, left, mid);
                ft_mergeSort(arr, mid + 1, right);

                ft_mergeMain(arr, left, mid, right);
            }
        }
    private:
        void ft_mergeMain(vector<int> &arr, int left, int mid, int right)
        {
            int i, j, k;
            int size_left = mid - left + 1;
            int size_right = right - mid;

            vector<int> L(size_left);
            vector<int> R(size_right);

            for(i = 0; i < size_left; i++)
                L[i] = arr[left + i];
            for(i = 0; i < size_right; i++)
                R[i] = arr[mid + i + 1];

            for(i = 0, j = 0, k = left; i < size_left && j < size_right;)
            {
                if(L[i] < R[j]) 
                    arr[k++] = L[i++];
                else 
                    arr[k++] = R[j++];
            }

            for(;i < size_left;)
                arr[k++] = L[i++];
            for(;j < size_right;)
                arr[k++] = R[j++];
        }
};