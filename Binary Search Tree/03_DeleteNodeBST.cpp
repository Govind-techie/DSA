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

// Function to find the inorder successor (leftmost node in right subtree)
Node* inorderSuccessor(Node* root){
    // If root is NULL or has no left child, it is the successor
    if (root == NULL || root->left == NULL) return root;
    // Otherwise, keep going left to find the minimum node
    return inorderSuccessor(root->left);
}

// Function to delete a node with value 'val' from BST
Node* deleteNodeBST(Node* root, int val){
    if (root == NULL) return NULL; // Base case: node not found

    // Traverse the tree to find the node to delete
    if (val < root->data){
        root->left = deleteNodeBST(root->left, val); // Go left if val is smaller
    } else if (val > root->data){
        root->right = deleteNodeBST(root->right, val); // Go right if val is larger
    } else {
        // Node found

        // Case 1: Node is a leaf (no children)
        if (root->left == NULL && root->right == NULL){
            delete root; // Free memory
            return NULL; // Remove link from parent
        }

        // Case 2: Node has only one child
        if (root->right == NULL || root->left == NULL){
            // Return the non-NULL child to be linked with parent
            // (No need to delete root here, but ideally should free memory)
            return root->left == NULL ? root->right : root->left;
        }

        // Case 3: Node has two children
        // Find inorder successor (smallest in right subtree)
        Node* succ = inorderSuccessor(root->right);
        // Copy successor's value to current node
        root->data = succ->data;
        // Delete the inorder successor node recursively
        root->right = deleteNodeBST(root->right, succ->data);
    }

    return root; // Return the (possibly updated) root pointer
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