/*
Height of a Tree

- Height is the number of edges on the longest path from root to a leaf node.
- Sometimes defined as number of nodes in longest path - 1.
- Height of an empty tree (NULL) is -1 or 0 based on definition (commonly -1).
- Height of a leaf node is 0.

Why height matters?
- Helps understand tree depth
- Used in problems like balanced tree, diameter, AVL rotations, etc.

How to find height? (Recursively)
- Height of a node = 1 + max(height of left subtree, height of right subtree)
- Base case: height of NULL node is -1

Example:

        1               height = 2
       / \
      2   3             height = 1 for node 2, 3
     / \
    4   5               height = 0 for node 4, 5 (leaf nodes)
*/

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data; // node value
    Node* left; // pointer to left child
    Node* right; // pointer to right child

    Node(int data) {
        this->data = data; // assign data to node
        left = right = NULL; // initialize both children as NULL
    }
};

static int i = -1; // global index for buildTree

Node* buildTree(vector<int> nodes) { // Time => O(n), Space => O(1)
    i++; // move to next index
    if (nodes[i] == -1) return NULL; // -1 means NULL node

    Node* currNode = new Node(nodes[i]); // create new node
    currNode->left = buildTree(nodes); // build left subtree
    currNode->right = buildTree(nodes); // build right subtree

    return currNode; // return current node
}

int height(Node* root){ // Time => O(n), Space => O(1) (excluding recursion stack)
    if (root == NULL) return 0; // base case: empty node has height 0

    int leftHeight = height(root->left); // get height of left subtree
    int rightHeight = height(root->right); // get height of right subtree

    int currHeight = max(leftHeight, rightHeight) + 1; // current node height = 1 + max(left, right)

    return currHeight; // return the computed height
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1, 3, -1, -1};
    
    Node* root = buildTree(nodes); // build tree from given vector
    cout << "Height of Tree = " << height(root) << endl; // print the height of the tree
    return 0;
}