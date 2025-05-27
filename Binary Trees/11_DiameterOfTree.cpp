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

// Function to return a pair containing:
// first  -> diameter of the subtree
// second -> height of the subtree
pair<int,int> diameterTree(Node* root){

    // Base case: if tree is empty, diameter and height are 0
    if (root == NULL) return make_pair(0, 0);

    // Recursively get diameter and height of left subtree
    pair<int,int> leftInfo = diameterTree(root->left);

    // Recursively get diameter and height of right subtree
    pair<int,int> rightInfo = diameterTree(root->right);

    // Diameter through current node = height of left + height of right + 1 (count current node)
    int currDiam = leftInfo.second + rightInfo.second + 1;

    // Max diameter so far = max of current diameter, left subtree diameter, right subtree diameter
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));

    // Height of current node = max of left and right heights + 1
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    // Return pair of (max diameter, height)
    return make_pair(finalDiam, finalHt);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root = buildTree(nodes);

    cout << "Diameter of tree = " << diameterTree(root).first << endl;

    return 0;
}