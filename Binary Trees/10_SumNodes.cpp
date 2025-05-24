/*
Sum of Nodes in a Binary Tree

- Sum of nodes is the total value obtained by adding all node values in the tree.
- For an empty tree (NULL), sum is 0.
- Sum of a leaf node is its own value.

Why sum matters?
- Useful in problems involving subtree sums, path sums, or checking tree properties.
- Helps in calculations like average node value, checking for balanced sums, etc.

How to find sum? (Recursively)
- Sum at a node = node’s own value + sum of left subtree + sum of right subtree
- Base case: sum of NULL node is 0

Example:

        1                   sum = 15
       / \
      2   3                 sum at node 2 = 11 (2 + 4 + 5)
     / \
    4   5                   sum at node 3 = 3 (leaf node)

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

int sumNodes(Node* root){ 
    if (root == NULL) return 0; // base case: if node is NULL, sum is 0

    int leftSum = sumNodes(root->left);   // recursively get sum of left subtree
    int rightSum = sumNodes(root->right); // recursively get sum of right subtree

    return (leftSum + rightSum) + root->data; // total sum = left subtree sum + right subtree sum + current node's value
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1, 3, -1, -1}; // input tree nodes in preorder with -1 as NULL

    Node* root = buildTree(nodes); // build tree from vector representation

    cout << "Sum of Nodes = " << sumNodes(root) << endl; // print the total sum of all nodes in the tree

    return 0;
}