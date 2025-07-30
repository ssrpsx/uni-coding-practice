#include <bits/stdc++.h>

using namespace std;

template <typename T>
class HeapSort
{
    private:
        void ft_swap(T &a, T &b) {
            T temp = a;
            a = b;
            b = temp;
        }

        void heapify(vector<T> &arr, int n, int i) {
            int current = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if(l < n && arr[current] < arr[l])
                current = l;
            
            if(r < n && arr[current] < arr[r])
                current = r;
            
            if(current != i) {
                ft_swap(arr[i], arr[current]);

                heapify(arr, n, current);
            }
        }
    public:
        void ft_heap_sort(vector<T> &arr) {
            int n = arr.size();

            for (int i = n / 2 - 1; i >= 0; i--)
                heapify(arr, n, i);

            for (int i = n - 1; i > 0; i--) {
                ft_swap(arr[0], arr[i]);

                heapify(arr, i, 0);
            }
        }
};