/*
Postorder Traversal (Left → Right → Root)

1. Traverse left subtree recursively
2. Traverse right subtree recursively
3. Visit the root node (print data)

Example Tree:
      1
     / \
    2   3
   / \
  4   5

Output: 4 5 2 3 1

Use cases:
- Used for deleting or freeing nodes (bottom-up approach)
- Helpful for evaluating **postfix expressions** in expression trees
- Often used in file systems to delete directories after their contents

Pseudocode:

postorder(node):
    if node is NULL:
        return
    postorder(node.left)   // visit left subtree
    postorder(node.right)  // visit right subtree
    print node.data        // visit root
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

static int idx = -1; // Global index to keep track of position in input vector

// Function to build a binary tree from a vector (preorder input with -1 as NULL)
Node* buildTree(vector<int> nodes){ // Time => O(n), Space => O(1)
    idx++; // Move to next element in vector

    // If current value is -1, this position is NULL (no node)
    if (nodes[idx] == -1) return NULL;

    // Create a new node with current value
    Node* currNode = new Node(nodes[idx]);

    // Recursively build the left and right subtrees
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    // Return the constructed node (root of this subtree)
    return currNode;
}

// Function to perform postorder traversal (Left → Right → Root)
void postorder(Node* root){ // Time => O(n), Space => O(1)
    // Base case: if node is NULL, return
    if (root == NULL) return;

    // Traverse left subtree
    postorder(root->left);

    // Traverse right subtree
    postorder(root->right);

    // Visit (print) the root node
    cout << root->data << " ";
}

int main(){
    // Input vector representing tree in preorder with -1 as NULL
    vector<int> nodes = {10, 5, 3, -1, -1, 7, -1, -1, 15, 12, -1, -1, 20, -1, -1};

    // Build the binary tree from the vector
    Node* root = buildTree(nodes);

    // Print the postorder traversal of the tree
    postorder(root);
    cout << endl;
    return 0;
}