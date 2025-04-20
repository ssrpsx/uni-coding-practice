#include <iostream>
#include <vector>
#include "Sort/basic_sort.h"
#include "Sort/BucketSorting.h"
#include "Sort/MergeSort.h"
#include "Sort/QuickSort.h"
#include "Sort/RadixSort.h"

using namespace std;

int main()
{
    vector<int> arr = {
        12, 30, 70, 20, 40, 60, 80, 55, 65, 75, 85, 24,
        35, 45, 57, 67, 77, 87, 50, 38, 27, 43, 3, 9,
        82, 10, 21, 231, 2, 3, 0, 141, 41, 86, 53, 486, 35, 46, 93, 24};

    vector<float> f_arr = {
        0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68,
        0.01, 0.15, 0.35, 0.49, 0.51, 0.60, 0.89, 0.99, 0.05, 0.45,
        0.30, 0.10, 0.55, 0.65, 0.75, 0.85, 0.95, 0.92, 0.02, 0.40,
        0.20, 0.00, 0.40, 0.60, 0.80, 1.00
    };

    BasicSort<int> bis_int;
    BasicSort<float> bis_float;
    BucketSort bs;
    MergeSort ms;
    QuickSort qs;
    RadixSort rs;

    cout << "before : ";
    bis_int.ft_printArray(arr);
    
    rs.radixSort(arr);

    cout << "after : ";
    bis_int.ft_printArray(arr);
    return 0;
}