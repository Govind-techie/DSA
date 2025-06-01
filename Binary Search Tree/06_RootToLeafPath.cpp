/*
Root to Leaf Paths in a Binary Search Tree (BST)

- The goal is to print or collect all paths from the root node to every leaf node in the BST.
- A root-to-leaf path is a sequence of nodes starting from the root and ending at a leaf (a node with no children).

Approach:
1. Use recursion (DFS) to traverse the tree.
2. Maintain a path (vector or list) that stores the current path from root to the current node.
3. When a leaf node is reached, print or store the current path.
4. Backtrack after visiting each node to explore other paths.

Example:
    For BST:     10
                /  \
                5   15
               / \    \
              3   7    18

    Root-to-leaf paths:
        10 -> 5 -> 3
        10 -> 5 -> 7
        10 -> 15 -> 18

Time Complexity:
- O(n), where n is the number of nodes (since each node is visited once).

Use Cases:
- Useful for path-based queries, sum of paths, or printing all possible root-to-leaf sequences.
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

void rootToLeaf(Node* root,vector<int>&path){
    if (root == NULL) return;

    path.push_back(root->data);

    if (root->left == NULL && root->right == NULL){
        cout << root->data << endl;
        path.pop_back();
    } 
    
    rootToLeaf(root->left,path);

}


int main(){
    vector<int> nodes = {3, 5, 7, 10, 12, 15, 17};
    Node* root = buildBST(nodes);
    vector<int>path;
    rootToLeaf(root,path);
}