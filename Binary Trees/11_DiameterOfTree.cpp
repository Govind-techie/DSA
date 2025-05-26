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
Finds the diameter of the binary tree and updates it by reference.
Diameter = number of nodes on the longest path between any two nodes.
Returns the height of the current subtree to help parent calls.
*/

int diameterTree(Node* root, int &diameter) { // Time: O(n), Space: O(1) (excluding recursion stack)
    if (root == NULL) return 0;  // If tree is empty, height is 0

    // Get height of left subtree
    int leftHt = diameterTree(root->left, diameter);
    // Get height of right subtree
    int rightHt = diameterTree(root->right, diameter);

    // Diameter at current node = left height + right height + 1 (for current node)
    int currDiameter = leftHt + rightHt + 1;

    // Update max diameter if current one is bigger
    diameter = max(diameter, currDiameter);

    // Return height of current subtree
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