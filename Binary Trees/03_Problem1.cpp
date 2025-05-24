/*
Problem: Build Binary Tree from Preorder Traversal

You are given the preorder traversal of a binary tree.
- The value -1 represents a NULL (no child).

Preorder means: 
Visit nodes in this order → Root → Left → Right

Task:
Build the binary tree and return its root.

Input Example:
[1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1]

Output Tree:
        1
       / \
      2   3
     / \
    4   5
*/

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> nodes) {
    idx++;

    // Base case: if the current value is -1, return NULL
    if (nodes[idx] == -1) {
        return NULL;
    }

    // Create a new node with current value
    Node* currNode = new Node(nodes[idx]);

    // Recursively build the left and right subtrees
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}
 
int main(){
    vector<int>nodes = {1, 2, 4, -1, - 1, 5, - 1, - 1, 3, - 1, 6, - 1, -1};

    Node* root = buildTree(nodes);
    cout << "root = " << root->data << endl;

    return 0;
}

/*
DETAIL EXPLANATION

Input (Preorder with -1 as NULL):
{1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}

Preorder format = Root → Left → Right

Each value represents:
- A node value (positive integer) → a valid node.
- -1 → a NULL child (no node at this position).

DECODE:

1.  1 → Root
2.  2 → Left of 1
3.  4 → Left of 2
4. -1 → Left of 4 is NULL
5. -1 → Right of 4 is NULL (→ 4 is a leaf node)
6.  5 → Right of 2
7. -1 → Left of 5 is NULL
8. -1 → Right of 5 is NULL (→ 5 is a leaf node)
   → Done building subtree rooted at 2
9.  3 → Right of 1
10. -1 → Left of 3 is NULL
11.  6 → Right of 3
12. -1 → Left of 6 is NULL
13. -1 → Right of 6 is NULL (→ 6 is a leaf node)
    → Done building right subtree of 1

Tree structure built from above:

            1
           / \
          2   3
         / \   \
        4   5   6

Explanation:
- Node 1 is root.
- 1 → left is 2, right is 3
- 2 → has two children: 4 and 5
- 3 → has only a right child: 6
- Nodes 4, 5, and 6 are leaf nodes (no children)
*/

