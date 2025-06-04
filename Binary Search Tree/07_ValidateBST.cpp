/*
Validating a Binary Search Tree (BST) - Notes

- The goal is to check whether a given binary tree is a valid BST.
- A valid BST must satisfy:
    1. For every node, all values in the left subtree are less than the node's value.
    2. For every node, all values in the right subtree are greater than the node's value.
    3. Both left and right subtrees must also be BSTs.

Approach:
1. Recursive Range Check:
    - Pass down the allowed value range (min, max) for each node.
    - For each node, check if its value is within the allowed range.
    - Recursively validate left and right subtrees with updated ranges.
    - Time Complexity: O(n)

Use Cases:
- Ensuring correctness of BST operations.
- Validating input trees in coding interviews or real-world applications.
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

static int idx = -1;
Node* buildTree(vector<int>nodes){
    idx++;
    if (nodes[idx] == -1) return NULL;

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

bool validateBST(Node* root, Node* min, Node* max){
    if (root == NULL) return true;

    if (min != NULL && root->data < min->data) return false;
    if (max != NULL && root->data > max->data) return false;

    return (validateBST(root->left,min,root) && validateBST(root->right,root,max) );
}

int main(){
    vector<int> nonBstNodes = {10, 5, 3, -1, -1, 12, -1, -1, 15, -1, -1};
    vector<int> BstNodes = {10, 5, 3, -1, -1, 7, 6, -1, -1, -1, 15, 12, -1, -1, -1};
    Node* root1 = buildTree(nonBstNodes);
    Node* root2 = buildTree(BstNodes);
    Node* min = NULL;
    Node* max = NULL;
    
    if(validateBST(root1,min,max)){ // invalid BST
        cout << "its a valid BST" << endl;
    }else{
        cout << "NOT a valid BST" << endl;
    }

    if(validateBST(root2,min,max)){ // valid BST
        cout << "its a valid BST" << endl;
    }else{
        cout << "NOT a valid BST" << endl;
    }

    return 0;
}

