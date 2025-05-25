/*
Diameter of a Binary Tree

- The diameter (or width) of a binary tree is the number of nodes on the longest path between any two nodes in the tree.
- The path may or may not pass through the root.
- The length is measured in number of nodes (not edges).

Example:
        1
       / \
      2   3
     / \
    4   5

- The longest path is: 4 → 2 → 1 → 3 (number of nodes = 4)
- So, diameter = 4

How to find diameter?
- For each node, calculate:
    1. Height of left subtree
    2. Height of right subtree
    3. Diameter passing through that node = left height + right height + 1 (for current node)
- The answer is the maximum diameter found at any node.

Applications:
- Measures how "wide" a tree is in terms of nodes.
- Useful in network design, tree balancing, etc.
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node with a given value
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Static variable to track current index while building tree from preorder vector
static int i = -1;

// Function to build binary tree from preorder traversal vector with -1 as NULL marker
Node* buildTree(vector<int> nodes) {
    i++;  // Move to the next index in vector

    // If current value is -1, this node is NULL (no child)
    if (nodes[i] == -1) return NULL;

    // Create current node with value nodes[i]
    Node* currNode = new Node(nodes[i]);
    
    // Recursively build left subtree
    currNode->left = buildTree(nodes);
    // Recursively build right subtree
    currNode->right = buildTree(nodes);

    // Return current node (root of subtree)
    return currNode;
}

/*
Function to compute diameter of binary tree and update max diameter by reference
Diameter is number of nodes on longest path between any two nodes in the tree
Returns height of current subtree for parent computations
*/
int diameterTree(Node* root, int &diameter) {
    if (root == NULL) return 0;  // Base case: empty tree has height 0

    // Recursively get height of left subtree
    int leftHt = diameterTree(root->left, diameter);
    // Recursively get height of right subtree
    int rightHt = diameterTree(root->right, diameter);

    // Current diameter through this node is sum of left and right heights + 1 (current node)
    int currDiameter = leftHt + rightHt + 1;

    // Update global max diameter if current is larger then previous diameter
    diameter = max(diameter, currDiameter);

    // Return height of subtree rooted at current node (max of left/right subtree + 1)
    return max(leftHt, rightHt) + 1;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root = buildTree(nodes);

    int diameter = 0; 

    diameterTree(root, diameter);

    cout << "Diameter of tree = " << diameter << endl;

    return 0;
}