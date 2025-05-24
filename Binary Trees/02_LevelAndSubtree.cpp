/*
Binary Trees: Level and Subtree

1. Level of a Node:
- The level of a node is the number of edges from the root to that node.
- The root node is at level 0.
- Example:
      1         // Level 0
     / \
    2   3       // Level 1
   / \
  4   5         // Level 2

2. Subtree:
- A subtree is any node and all its descendants in the tree.
- Every node is the root of its own subtree.
- Example:
      1
     / \
    2   3
   / \
  4   5
  Subtree rooted at 2:
    2
   / \
  4   5

3. Applications:
- Level is used in level order traversal (BFS).
- Subtree concepts are used in problems like finding subtree sums, checking subtree properties, etc.
*/

#include <iostream>
using namespace std;

// Structure for a node in the binary tree
struct Node {
    int data;         // Value stored in the node
    Node* left;       // Pointer to the left child
    Node* right;      // Pointer to the right child

    // Constructor to initialize node with a value
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

int main() {
    // Create the root node with value 1
    Node* root = new Node(1);

    // Create left and right children of root
    root->left = new Node(2);
    root->right = new Node(3);

    // Create children for the left child of root
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // The tree now looks like:
    /*
            1        <- Level 0 (root)
           / \
          2   3      <- Level 1
         / \
        4   5        <- Level 2 
    */

    // Print the data of each node to show the structure
    cout << "Root Node: " << root->data << endl; // Output => 1
    cout << "Left Subtree Root: " << root->left->data << endl; // Output => 2
    cout << "Right Subtree Root: " << root->right->data << endl; // Output => 3
    cout << "Left Subtree's Left Child: " << root->left->left->data << endl; // Output => 4
    cout << "Left Subtree's Right Child: " << root->left->right->data << endl; // Output => 5

    return 0;
}