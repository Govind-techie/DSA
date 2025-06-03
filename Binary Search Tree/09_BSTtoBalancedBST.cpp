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

Node* buildBST(vector<int>nodes){
    Node* root = NULL;

    for (int i = 0 ; i < nodes.size() ; i++){
        root = insertNode(root,nodes[i]);
    }

    return root;
}

void helper(Node* root, vector<int>&BalancedBSTNodes){

    if (root == NULL) return;

    helper(root->left,BalancedBSTNodes);
    BalancedBSTNodes.push_back(root->data);
    helper(root->right,BalancedBSTNodes);
}

Node* BalancedBST(vector<int>nodes,int st, int en){
    if (st > en) return NULL;

    int mid = st + (en - st) / 2;
    Node* root = new Node(nodes[mid]);

    root->left = BalancedBST(nodes,st,mid-1);
    root->right = BalancedBST(nodes,mid+1,en);

    return root;
}

int main(){
    vector<int>nodes = {1, 2, 3, 4, 5, 6, 7};
    Node* root = buildBST(nodes);
    vector<int>BalancedBSTNodes;
    helper(root,BalancedBSTNodes);
    Node* BalancedRoot = BalancedBST(BalancedBSTNodes,0,BalancedBSTNodes.size()-1);
    cout << BalancedRoot->data << endl;
    return 0;
}