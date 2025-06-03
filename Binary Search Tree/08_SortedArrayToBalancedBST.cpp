/*
Creating a Balanced BST from a Sorted Array - Notes

- The goal is to convert a sorted (increasing order) array into a height-balanced Binary Search Tree (BST).
- A balanced BST ensures minimal height, which gives optimal search, insert, and delete times (O(log n)).

Approach (Divide and Conquer):
1. Find the middle element of the array/subarray. This becomes the root of the current subtree.
2. Recursively repeat the process for the left half (to build the left subtree).
3. Recursively repeat the process for the right half (to build the right subtree).
4. Base case: If the subarray is empty, return NULL.

Why this works:
- Choosing the middle element as root at each step ensures the tree is as balanced as possible.
- All elements to the left of the middle go to the left subtree, and all elements to the right go to the right subtree.

Time Complexity:
- O(n), where n is the number of elements in the array (each element is visited once).

Example:
    Input:  [1, 2, 3, 4, 5, 6, 7]
    Output: 
              4
            /   \
           2     6
          / \   / \
         1   3 5   7
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

Node* insertNode(Node* root, int val){
    if (root == NULL){
        root = new Node(val);
        return root;
    }

    if (val < root->data){
        root->left = insertNode(root->left,val);
    }else{
        root->right = insertNode(root->right,val);
    }

    return root;
}

// Helper function to build balanced BST from sorted array
Node* helper(vector<int>nodes, int st, int en){
    if (st > en) return NULL; // base case - invalid range

    int mid = st+(en-st)/2; // find mid index
    Node* root = new Node(nodes[mid]); // make mid element root

    // build left subtree from left half
    root->left = helper(nodes, st, mid - 1);
    // build right subtree from right half
    root->right = helper(nodes, mid + 1, en);

    return root; // return root of current subtree
}

// Main function to convert sorted array to balanced BST
Node* sortedArrayToBalancedBST(vector<int>nodes){
    return helper(nodes, 0, nodes.size() - 1); // call helper with full range
}

int main(){
    vector<int>nodes = {3,4,5,6,7,8,9}; // input sorted array
    Node* root = sortedArrayToBalancedBST(nodes); // build BST
    cout << root->data << endl; // print root (should be mid element = balanced tree)
    return 0;
}

/*
MY INTUTION:
We choose the middle element as the root because in a BST, the inorder
traversal gives a sorted array — so placing the mid as root ensures 
balanced structure while preserving BST properties.
*/