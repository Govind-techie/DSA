/*
Binary Search Tree (BST) - Simplified Notes

A Binary Search Tree is a type of binary tree with these rules:
1. Each node has a key (a value).
2. All keys in the left subtree are smaller than the node’s key.
3. All keys in the right subtree are larger than the node’s key.
4. No duplicate keys (in standard BSTs).

Common Operations:
- Insert: Add a new value in the correct position.
- Delete: Remove a value and keep the tree in order.
- Search: Find if a value exists in the tree.
- Traverse: Go through all nodes (inorder, preorder, postorder).

Time Complexity of Binary Search Tree (BST) Operations:

On Average (Balanced Tree):
- Search: O(log n)
- Insert: O(log n)
- Delete: O(log n)

Worst Case (Skewed Tree — like a linked list):
- Search: O(n)
- Insert: O(n)
- Delete: O(n)

General Case:
- Time complexity is O(h), where 'h' is the height of the tree.

Note:
- In a balanced BST, h ≈ log n
- In a skewed BST, h ≈ n

Uses of BST:
- Fast searching and sorting
- Building sets and lookup tables
- Range-based queries

NOTE: To avoid the worst case, use self-balancing trees (like AVL or Red-Black Trees) which always keep operations at O(log n).

SPECIAL PROPERTY (BST): Inorder traversal of BST gives sorted sequence.
*/

#include <iostream>
#include <vector>
using namespace std;

// Node class to represent each node of the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor initializes node with data and sets children to NULL
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Function to insert a value into the BST
Node* insertBST(Node* root, int val) {
    // Base case: If tree is empty, create a new node
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    // If the value is less than current node's data, insert in left subtree
    if (val < root->data) 
        root->left = insertBST(root->left, val);
    // Otherwise, insert in right subtree
    else 
        root->right = insertBST(root->right, val);

    return root; // Return unchanged root pointer
}

// Function to build a BST from a list of values
Node* buildBST(vector<int> nodes) {
    Node* root = NULL;

    // Insert each element into the BST one by one
    for (int i = 0; i < nodes.size(); i++) {
        root = insertBST(root, nodes[i]);
    }

    return root; // Return the root of the constructed BST
}

// Inorder traversal (Left, Root, Right)
// Used to verify if the BST is built correctly
// If the BST is valid, its inorder traversal will produce sorted values
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left); // Visit left subtree
    cout << root->data << " "; // Print root data
    inorder(root->right); // Visit right subtree
}

int main() {
    vector<int> nodes = {5, 1, 3, 4, 2, 7};
    Node* root = buildBST(nodes);

    // Print inorder traversal of the BST (should be sorted)
    inorder(root);
    cout << endl;

    return 0;
}