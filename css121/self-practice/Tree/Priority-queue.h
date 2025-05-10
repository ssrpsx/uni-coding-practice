// template<
//     class T,                              // ชนิดข้อมูล เช่น int
//     class Container = vector<T>,          // คอนเทนเนอร์ (ค่าเริ่มต้นคือ vector)
//     class Compare = less<typename Container::value_type> // ฟังก์ชันเปรียบเทียบ (ค่า default คือ Max Heap)
// > class priority_queue;

//Input ตัวที่ 3
// struct Compare {
//     bool operator()(int a, int b) {
//         return a > b;  // ผลลัพธ์เหมือน greater<int>
//     }
// };

// priority_queue<int, vector<int>, Compare> pq;

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class HowtoUse{
    public:
        void run(){
        // Max Heap (default)
        int arr[7] = {5, 1, 9, 3, 14, 7, 2};
        int n = sizeof(arr)/sizeof(arr[0]);
        int k = 5;

        priority_queue<int> maxPQ(arr, arr + n);
        cout << "Max Heap top: ";
        for(int i = 0; i < k; i++)
        {
            cout << maxPQ.top() << " ";
            maxPQ.pop();
        }
        cout << endl;

        // Min Heap
        priority_queue<int, vector<int>, greater<int>> minPQ;
        minPQ.push(5);
        minPQ.push(10);
        minPQ.push(1);
        cout << "Min Heap top: " << minPQ.top() << "\n"; // 1
    }
};