#include <bits/stdc++.h>
#include "Tree/Red-Black-Tree.h"
using namespace std;

int main()
{
    RedBlackTree rbt;

    // Inserting elements
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);

    // Inorder traversal
    cout << "Inorder traversal:" << endl;
    rbt.inorder(); // Output: 10 15 20 30

    // Search for a node
    cout << "\nSearch for 15: "
         << (rbt.search(15) != rbt.search(0))
         << endl; // Output: 1 (true)
    cout << "Search for 25: "
         << (rbt.search(25) != rbt.search(0))
         << endl; // Output: 0 (false)

    return 0;
}