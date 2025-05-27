/*
Subtree of Another Tree

- A subtree is a part of a binary tree that forms a valid tree by itself.
- Tree A is a subtree of Tree B if:
    → There exists a node in Tree B such that the subtree rooted at that node
      is exactly the same (structure + values) as Tree A.

Example:
      Tree B:             Tree A:
          3                  4
         / \                / \
        4   5              1   2
       / \
      1   2

- Tree A is a subtree of Tree B (matches the left subtree of node 3).

Key Ideas:
- A subtree must match both in **structure** and **node values**.
- Matching means:
    → Root values are the same
    → Left subtrees are same
    → Right subtrees are same

How to check if A is a subtree of B?
1. Traverse tree B node by node.
2. At each node, check if the subtree starting from there is **identical** to tree A.
3. Use a helper function to compare two trees.

Applications:
- Tree comparison in compilers, XML/HTML structure checking, data deduplication.
- Useful in pattern detection within hierarchical data (e.g., filesystems, DOM trees).
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

static int i = -1;
Node* buildTree(vector<int>nodes){
    i++;
    if (nodes[i] == -1) return NULL;

    Node* currNode = new Node(nodes[i]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

bool sameTree(Node* root, Node* subRoot){
    // Edge Case
    if (root == NULL && subRoot == NULL) return true;

    if (root != NULL && subRoot != NULL){
        if (root->data == subRoot->data){
            return (sameTree(root->left,subRoot->left) && sameTree(root->right,subRoot->right));
        }
    }
    return false;
}

bool isSubtree(Node* root , Node* subRoot){
    if (subRoot == NULL) return true;
    if (root == NULL) return false;

    if (sameTree(root,subRoot)) return true;

    return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
}

int main() {
    vector<int> rootNodes = {3, 4, 1, -1, -1, 2, -1, -1, 5, -1, -1};      // Tree: 3 -> 4 -> 1,2 and 5
    vector<int> subRootNodes = {4, 1, -1, -1, 2, -1, -1};                 // Subtree: 4 -> 1,2

    // Reset static index before each build
    i = -1;
    Node* root = buildTree(rootNodes);

    i = -1;
    Node* subRoot = buildTree(subRootNodes);

    if (isSubtree(root, subRoot)) {
        cout << "subRoot is a subtree of root" << endl;
    } else {
        cout << "subRoot is NOT a subtree of root" << endl;
    }

    return 0;
}
