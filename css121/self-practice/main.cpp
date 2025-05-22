#include <bits/stdc++.h>
#include "Tree/Binary-search-tree.h"
using namespace std;


int main() {
    binarySearch_class tree;
    int data[] = {10, 8, 2, 4, 3, 15, 26, 30, 17, 6};
    int size = sizeof(data) / sizeof(data[0]);

    Node* root = nullptr;
    for (int i = 0; i < size; i++) {
        tree.insert(root, data[i], i); // ส่ง index ไปด้วย (ถ้าจำเป็น)
    }

    cout << "Pre-order: ";
    tree.preorder(root);
    cout << "\n";

    cout << "In-order: ";
    tree.inorder(root);
    cout << "\n";

    cout << "Post-order: ";
    tree.postorder(root);
    cout << "\n";

    return 0;
}