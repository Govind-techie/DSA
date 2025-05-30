/*
Inorder Traversal (Left → Root → Right)

1. Traverse left subtree recursively
2. Visit the root node (print data)
3. Traverse right subtree recursively

Example Tree:
      1
     / \
    2   3
   / \
  4   5

Output: 4 2 5 1 3

Use cases:
- In binary search trees, inorder traversal gives sorted order of elements
- Useful for evaluating expression trees (infix expression)

Pseudocode:

inorder(node):
    if node is NULL:
        return
    inorder(node.left)   // visit left subtree
    print node.data      // visit root
    inorder(node.right)  // visit right subtree
*/

#include<iostream>
#include<vector>
using namespace std;

// Node class represents each node in the binary tree
class Node{
public:
    int data;         // Value stored in the node
    Node* left;       // Pointer to left child
    Node* right;      // Pointer to right child

    // Constructor to initialize node with a value
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int i = -1; // Global index to keep track of position in input vector

// Function to build a binary tree from a vector (preorder input with -1 as NULL)
Node* buildTree(vector<int> nodes){ // Time => O(n), Space => O(1)
    i++; // Move to the next index

    if (nodes[i] == -1) return NULL; // Base case: if value is -1, return NULL

    Node* currNode = new Node(nodes[i]); // Create a new node with the current value

    // Recursively build the left and right subtrees
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode; // => root of final tree build
}


// Function for inorder traversal of the binary tree
void inorder(Node* root){ // Time => O(n), Space => O(1)
    
    if (root == NULL) return; // Base case: if the node is NULL, return
    
    inorder(root->left); // Recursively traverse the left subtree
    
    cout << root->data << " "; // Visit the root node
    
    inorder(root->right); // Recursively traverse the right subtree
}


int main(){
    vector<int>nodes = {10, 5, 2, -1, -1, 7, -1, -1, 15, 12, -1, -1, 20, -1, -1};

    Node* root = buildTree(nodes); // Build the tree from the given vector

    inorder(root); // Perform inorder traversal
    cout << endl;
    return 0;
}