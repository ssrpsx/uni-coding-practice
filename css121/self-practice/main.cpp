#include <bits/stdc++.h>
#include "Tree/AVLTree.h"
using namespace std;

int main()
{
    AVLTree<int> avl;

    // Insert nodes into the AVL tree
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    // Print the inorder traversal of the AVL tree
    cout << "Inorder traversal of the AVL tree: ";
    avl.printInorder();

    // Remove a node from the AVL tree
    avl.remove(30);
    cout << "Inorder traversal after removing 30: ";
    avl.printInorder();

    // Search for nodes in the AVL tree
    cout << "Is 25 in the tree? "
         << (avl.search(25) ? "Yes" : "No") << endl;
    cout << "Is 30 in the tree? "
         << (avl.search(30) ? "Yes" : "No") << endl;

    return 0;
    return 0;
}