/*
Inorder Successor in a Binary Search Tree (BST) - Notes

- The inorder successor of a node in BST is the node with the smallest key greater than the given node.
- Inorder successor is useful in deletion and various BST operations.

How to find the inorder successor of a node:
1. If the node has a right subtree:
    - The successor is the leftmost (minimum) node in the right subtree.
2. If the node does NOT have a right subtree:
    - Move up using parent pointers until you find a node which is the left child of its parent.
    - The parent of that node is the successor.
    - (If parent pointers are not available, you can search from the root and keep track of the potential successor.)

Example:
    - Inorder traversal of BST: 1 2 3 4 5 6 7
    - Inorder successor of 4 is 5.

Time Complexity:
    - O(h), where h is the height of the tree (O(log n) for balanced BST, O(n) for skewed BST).

NOTE:
• The inorder successor of a node in a Binary Search Tree (BST) always has at most one child.
• Specifically, the inorder successor never has a left child.
• This is because the inorder successor is the leftmost node in a subtree.
• By definition, the leftmost node does not have a left child.


*/
#include<iostream>
#include<vector>
using namespace std;

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

Node* insertNodeBST(Node* root, int val){
    if (root == NULL){
        root = new Node(val);
        return root;
    }

    if (val < root->data) root->left = insertNodeBST(root->left, val);
    else root->right = insertNodeBST(root->right, val);

    return root;
}

Node* buildBST(vector<int>nodes){
    Node* root = NULL;

    for (int i = 0 ; i < nodes.size() ; i++){
        root = insertNodeBST(root,nodes[i]);
    }

    return root;
}

// Function to find the leftmost (smallest) node in a binary search tree (BST)
// Typically used to find the inorder successor when a node has a right child
Node* inorderSuccessor(Node* root) {
    // Base case: if the subtree is empty or we've reached the leftmost node
    if (root == NULL || root->left == NULL) return root;

    // Recursive case: keep moving to the left child
    return inorderSuccessor(root->left);
}

void inorderTraversal(Node* root){
    if (root == NULL) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main(){
    vector<int>nodes = {8,5,3,1,4,6,9,11,14};
    Node* root = buildBST(nodes);

    inorderTraversal(root);
    cout << endl;

    cout << "Inorder successor : " << (inorderSuccessor(root->right))->data << endl;
    return 0;
}