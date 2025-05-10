#ifndef BASIC_SORT_H
#define BASIC_SORT_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T> class BasicSort
{
    public:
        void ft_swap(T& a, T& b)
        {
            T temp = a;
            a = b;
            b = temp;
        }

        void ft_bubbleSort(vector<T>& arr)
        {
            int n = arr.size();
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        ft_swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }

        void ft_selectionSort(vector<T>& arr)
        {
            int min_index, i, j, n = arr.size();
            for(i = 0; i < n - 1; i++)
            {
                min_index = i;
                for(j = i + 1; j < n; j++)
                {
                    if(arr[j] < arr[min_index])
                    {
                        min_index = j;
                    }
                }
                ft_swap(arr[i], arr[min_index]);
            }
        }

        void ft_insertionSort(vector<T>& arr)
        {
            int i, j, n = arr.size();
            for (i = 1; i < n; i++)
            {
                T key = arr[i];
                for(j = i - 1; j >= 0 && arr[j] > key; j--)
                {
                    arr[j + 1] = arr[j];
                }
                arr[j + 1] = key;
            }
        }

        void ft_printArray(const vector<T>& arr)
        {
            for (T i : arr)
                cout << i << " ";
            cout << endl;
        }
};

#endif