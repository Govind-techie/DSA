/*
Preorder Traversal (Root → Left → Right)

1. Visit the root node (print data)
2. Traverse left subtree recursively
3. Traverse right subtree recursively

Example Tree:
      1
     / \
    2   3
   / \
  4   5

Output: 1 2 4 5 3

Use cases:
- Copying the tree
- Getting prefix expressions in expression trees
- Serializing/deserializing binary trees

Pseudocode:

preorder(node):
    if node is NULL:
        return
    print node.data      // visit root
    preorder(node.left)  // visit left subtree
    preorder(node.right) // visit right subtree
*/

#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;  // Initially, both children are NULL
    }
};

static int i = -1; // Global index to traverse the input vector step by step

// Function to build tree from given vector of integers (preorder with -1 as NULL)
Node* buildTree(vector<int> nodes) {
    i++;  // Move to next element in vector
    
    // Base case: If current value is -1, no node here, return NULL
    if (nodes[i] == -1) {
        return NULL;
    }

    // Create a new node with current value
    Node* currNode = new Node(nodes[i]);

    // Recursively build the left subtree
    currNode->left = buildTree(nodes);

    // Recursively build the right subtree
    currNode->right = buildTree(nodes);

    // Return the current node (with left and right children set)
    return currNode;
}

// Function to print tree nodes in preorder (root-left-right)
void preorder(Node* root) {
    // Base case: if node is NULL, just return
    if (root == NULL) return;
    
    // Print current node's data
    cout << root->data << " ";
    
    // Recursively print left subtree
    preorder(root->left);

    
    // Recursively print right subtree
    preorder(root->right);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    // Build the tree from vector
    Node* root = buildTree(nodes);

    // Print the tree nodes in preorder
    preorder(root);
    cout << endl;

    return 0;
}