#include <bits/stdc++.h>
#include "../Sort/basic_sort.h"
using namespace std;

class Node {
public:
    int data;
    int index;
    Node *left;
    Node *right;

    Node(int value, int idx) {
        data = value;
        index = idx;
        left = nullptr;
        right = nullptr;
    }
};

class binarySerachTree_class{
    public:
        void insert(Node *&root, int value, int index) {
            if (root == nullptr) {
                root = new Node(value, index);
            } 
            else if (value < root->data) {
                insert(root->left, value, index);
            } 
            else {
                insert(root->right, value, index);
            }
        };

        Node *minValueNode(Node *node) {
            Node* current = node;
            while (current && current->left != nullptr) {
                current = current->left;
            }
            return current;
        };

        void delete_node_value(Node *&root, int value) {
            if (root == nullptr) {
                return;
            } 
            else if (value < root->data) {
                delete_node_value(root->left, value);
            } 
            else if (value > root->data) {
                delete_node_value(root->right, value);
            } 
            else {
                if (root->left == nullptr) {
                    Node* temp = root->right;
                    delete root;
                    root = temp;
                } 
                else if (root->right == nullptr) {
                    Node* temp = root->left;
                    delete root;
                    root = temp;
                } 
                else {
                    Node* temp = minValueNode(root->right);
                    root->data = temp->data;
                    delete_node_value(root->right, temp->data);
                }
            }
        };

        void inorder(Node *root) {
            if (root != nullptr) {
                inorder(root->left);
                cout << root->data << " ";
                inorder(root->right);
            }
        };

        void clear(Node *&root){
            if(root != nullptr){
                clear(root->left);
                clear(root->right);
                delete root;
                root = nullptr;
            }
        }

        void minimum(Node *root) {
            if (root == nullptr) {
                cout << "Tree is empty\n";
                return;
            }
            Node* current = root;
            while (current->left != nullptr) {
                current = current->left;
            }
            cout << "Minimum value: " << current->data << endl;
        };

        void maximum(Node *root) {
            if (root == nullptr) {
                cout << "Tree is empty\n";
                return;
            }
            Node* current = root;
            while (current->right != nullptr) {
                current = current->right;
            }
            cout << "Maximum value: " << current->data << endl;
        };

        void find(Node *root, int value) {
            if (root == nullptr) {
                cout << "Value not found\n";
                return;
            } 
            else if (value < root->data) {
                find(root->left, value);
            } 
            else if (value > root->data) {
                find(root->right, value);
            } 
            else {
                cout << "Value found: " << root->data << " " <<  "Index in array : " << root->index << endl;
            }
        };
};

class binarySearch_class {
    public:
        void binarySearch(vector<int> &arr, int target) {
            int left = 0;
            int right = arr.size() - 1;

            while (left <= right) 
            {
                int mid = (left + right) / 2;
                if (arr[mid] == target) {
                    cout << "Element "<< target << " " << "found at index: " << mid << endl;
                    return;
                } 
                else if (arr[mid] < target) {
                    left = mid + 1;
                } 
                else {
                    right = mid - 1;
                }
            }
            cout << "Element " << target << " not found in the array." << endl;
        };

        void insertion_sort(vector<int> &arr){
            int i, j, key, n = arr.size();
            for (i = 1; i < n; i++){
                key = arr[i];
                for(j = i - 1; j >= 0 && arr[j] > key; j--){
                    arr[j + 1] = arr[j];
                }
                arr[j + 1] = key;
            }
        };
};