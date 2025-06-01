/*
Deleting a Node in a Binary Search Tree (BST) - Notes

- Deletion in BST must maintain the BST property after removing a node.
- There are three main cases to handle:

1. Node to be deleted is a **leaf** (no children):
    - Simply remove the node.

2. Node to be deleted has **one child**:
    - Remove the node and connect its parent directly to its child.

3. Node to be deleted has **two children**:
    - Find the node's inorder successor (smallest value in the right subtree) or inorder predecessor (largest value in the left subtree).
    - Replace the node's value with the successor/predecessor's value.
    - Delete the successor/predecessor node (which will have at most one child).

- Time Complexity:
    * Average case: O(log n) (for balanced BST)
    * Worst case: O(n) (for skewed BST)

- Deletion can be implemented recursively.

Example Steps:
    1. Search for the node to delete.
    2. Handle one of the three cases above.
    3. Return the new root after deletion.
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

Node* inorderSuccessor(Node* root){
    if (root == NULL || root->left == NULL) return root;
    return inorderSuccessor(root->left);
}

Node* deleteNodeBST(Node* root, int val){
    if (root == NULL) return NULL;

    // Find Node

    if (val < root->data){
        root->left = deleteNodeBST(root->left,val);
    }else if (val > root->data){
        root->right = deleteNodeBST(root->right,val);
    }else{
        // For leaf nodes
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // for 1 child node
        if(root->right == NULL || root->left == NULL){
            return root->left == NULL ? root->right : root->left;
        }

        // for 2 children
        Node* succ = inorderSuccessor(root->right);
        root->data = succ->data;
        root->right = deleteNodeBST(root->right, succ->data);
    }

    return root;
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

    deleteNodeBST(root,5);

    inorderTraversal(root);
    cout << endl;

    return 0;
}