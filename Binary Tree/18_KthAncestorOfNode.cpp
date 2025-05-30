/*
Kth Ancestor of a Node in a Binary Tree

- The Kth ancestor of a node is the node that appears K levels above the given node in the path from the node to the root.
- For example, the 1st ancestor is the parent, the 2nd ancestor is the grandparent, and so on.

How to find the Kth ancestor?
- Use recursion to traverse the tree and search for the target node.
- As you backtrack from the target node, decrement K.
- When K becomes 0, the current node is the Kth ancestor.

Example:
        1
       / \
      2   3
     / \
    4   5

- 2nd ancestor of 4 is 1 (path: 4 → 2 → 1)

Applications:
- Useful in genealogy queries, tree-based data structures, and hierarchical relationships.
*/

#include<iostream>
#include<vector>
using namespace std;

// Definition of a binary tree node
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

// Global index for building the tree from a vector
static int i = -1;

// Function to build a binary tree from a vector representation
Node* buildTree(vector<int> nodes){
    i++;
    if (nodes[i] == -1) return NULL; // -1 represents a NULL node
    Node* currNode = new Node(nodes[i]);
    
    // Recursively build the left and right subtrees
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}


Node* KthAncestorNode(Node* root , int &k, int n){
    // Base Case
    if (root == NULL) return NULL;
    if (root->data == n) return root;

    // Recursion
    Node* left = KthAncestorNode(root->left,k,n);
    Node* right = KthAncestorNode(root->right,k,n);


    // Backtrack
    if (left != NULL || right != NULL){
        if (--k == 0) return root;

        return left ? left : right; 
    }

    return NULL;

}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1}; // Example input
    Node* root = buildTree(nodes);
    
    int k = 1;
    int n = 4;

    Node* KthAncestor = KthAncestorNode(root,k,n);

    cout << KthAncestor << endl;
    return 0;
}