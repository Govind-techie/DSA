/*
Count Nodes in a Binary Tree

- Node count means total number of nodes present in the tree.
- Counting nodes helps understand tree size and is useful in many problems.
- An empty tree has 0 nodes.

How to count nodes? (Recursively)
- Count of nodes = 1 (current node) + count of nodes in left subtree + count of nodes in right subtree
- Base case: count of NULL node is 0

Example:

        1               total nodes = 5
       / \
      2   3             nodes under 2 = 2, under 3 = 1
     / \
    4   5               leaf nodes count as 1 each (4 and 5)
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


int countNodes(Node* root){ // Time => O(n), Space => O(1) excluding recursion stack
    if (root == NULL) return 0; // base case: if node is NULL, count is 0

    int leftCount = countNodes(root->left); // recursively count nodes in left subtree
    int rightCount = countNodes(root->right); // recursively count nodes in right subtree

    return (leftCount + rightCount) + 1; // total count = left + right + current node (1)
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1, 3, -1, -1};

    Node* root = buildTree(nodes); 
    cout << "Count of Nodes = " << countNodes(root) << endl;
    return 0;
}