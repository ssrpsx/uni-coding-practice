#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct AVLNode{
    T key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(T k){
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

template<typename T>
class AVLTree{
    private:
        AVLNode<T>* root;

        int get_Height(AVLNode<T>* node){
            if(node == nullptr){
                return 0;
            }

            return node->height;
        }

        int get_Balance(AVLNode<T>* node){
            if(node == nullptr){
                return 0;
            }

            return get_Height(node->left) - get_Height(node->right);
        }

        AVLNode<T>* leftRotate(AVLNode<T>* x){
            AVLNode<T>* y = x->right;
            AVLNode<T>* T2 = y->left;

            y->left = x;
            x->right = T2;

            y->height = max(get_Height(y->left), get_Height(y->right)) + 1;
            x->height = max(get_Height(x->left), get_Height(x->right)) + 1;

            return y;
        }

        AVLNode<T>* rightRotate(AVLNode<T>* x){
            AVLNode<T>* y = x->left;
            AVLNode<T>* T2 = y->right;

            y->right = x;
            x->left = T2;

            y->height = max(get_Height(y->left), get_Height(y->right)) + 1;
            x->height = max(get_Height(x->left), get_Height(x->right)) + 1;

            return y;
        }

        AVLNode<T>* insert(AVLNode<T>*& node, T key){
            if(node == nullptr){
                return new AVLNode<T>(key);
            }
            
            if(key < node->key){
                node->left = insert(node->left, key);
            }
            else if(key > node->key){
                node->right = insert(node->right, key);
            }
            else{
                return node;
            }

            node->height = 1 + max(get_Height(node->left), get_Height(node->right));

            int balance = get_Balance(node);
            
            if(balance > 1 && key < node->left->height){
                return rightRotate(node);
            }

            if(balance < -1 && key > node->right->height){
                return leftRotate(node);
            }

            // left right
            if(balance > 1 && key > node->left->height){
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            // right left
            if(balance < -1 && key < node->right->height){
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            return node;
        }

        AVLNode<T>* minValueNode(AVLNode<T>* node)
    {
        AVLNode<T>* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode<T>* deleteNode(AVLNode<T>* root, T key)
    {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if ((root->left == nullptr)
                || (root->right == nullptr)) {
                AVLNode<T>* temp
                    = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else {

                AVLNode<T>* temp
                    = minValueNode(root->right);
                root->key = temp->key;
                root->right
                    = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(get_Height(root->left), get_Height(root->right));

        int balance = get_Balance(root);

        // Left Left Case
        if (balance > 1 && get_Balance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && get_Balance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && get_Balance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && get_Balance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

        void inorder(AVLNode<T>* root){
            if(root != nullptr){
                inorder(root->left);
                cout << root->key << " ";
                inorder(root->right);
            }
        }

        bool search(AVLNode<T>* root, T key){
            if(root == nullptr){
                return false;
            }
            else if(key == root->key){
                return true;
            }
            else if(key < root->key){
                return search(root->left, key);
            }

            return search(root->right, key);
        }
    public:
    AVLTree()
        : root(nullptr)
    {
    }

    void insert(T key) { root = insert(root, key); }

    void remove(T key) { root = deleteNode(root, key); }

    bool search(T key) { return search(root, key); }

    void printInorder()
    {
        inorder(root);
        cout << endl;
    }
};