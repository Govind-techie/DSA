/*
Searching in a Binary Search Tree (BST) - Notes

- Searching in a BST uses the property that for any node:
    * All values in the left subtree are smaller.
    * All values in the right subtree are larger.

- Search Steps:
    1. Start at the root node.
    2. If the key matches the root's value, return the node (found).
    3. If the key is less than the root's value, search the left subtree.
    4. If the key is greater than the root's value, search the right subtree.
    5. If the subtree is NULL, the key is not present.

- Time Complexity:
    * Average case: O(log n) (for balanced BST)
    * Worst case: O(n) (for skewed BST)

- Search can be implemented recursively or iteratively.
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

// Insert a node into the BST
Node* insertNode(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    if (val < root->data) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);

    return root;
}

// Build BST from a list of values
Node* buildBST(vector<int> nodes) {
    Node* root = NULL;

    for (int i = 0; i < nodes.size(); i++) {
        root = insertNode(root, nodes[i]);
    }

    return root;
}

// Search for a value in the BST
// Returns true if found, false otherwise
bool searchBST(Node* root, int target) { // General => O(height) , Average => O(n)
    if (root == NULL) return false; // If node is null, target is not in tree

    if (root->data == target) return true; // Target found

    if (root->data > target)
        return searchBST(root->left, target);  // Search left subtree if target is smaller
    else
        return searchBST(root->right, target); // Search right subtree if target is larger
}

int main(){
    vector<int>nodes = {5,1,3,4,2,7};

    Node* root = buildBST(nodes);

    int target = 7;

    cout << searchBST(root,target) << endl;
    return 0;
}