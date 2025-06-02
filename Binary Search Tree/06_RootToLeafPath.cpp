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

// Prints the current path from root to a leaf node
void printPath(vector<int>path){
    cout << "path : ";
    for (int i = 0 ; i < path.size() ; i++){
        cout << path[i] << " ";
    } 
    cout << endl;
}

// Recursive helper to find all root-to-leaf paths
void helper(Node* root, vector<int>& path){
    if (root == NULL) return;  // Base case: reached beyond leaf

    path.push_back(root->data);  // Add current node to path

    // If leaf node, print the path
    if (root->left == NULL && root->right == NULL){
        printPath(path);
        path.pop_back();  // Backtrack to explore other paths
        return;
    }

    // Explore left subtree
    helper(root->left, path);
    // Explore right subtree
    helper(root->right, path);

    path.pop_back();  // Backtrack after exploring both subtrees
}

// Initiates path finding from root to all leaf nodes
void rootToLeaf(Node* root){
    vector<int> path;
    helper(root, path);
}

int main(){
    // Create BST from given nodes
    vector<int> nodes = {10, 5, 3, 7, 15, 12, 17};
    Node* root = buildBST(nodes);

    // Print all root-to-leaf paths in the BST
    rootToLeaf(root);
}