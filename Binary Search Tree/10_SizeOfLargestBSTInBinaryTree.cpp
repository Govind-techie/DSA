/*
Largest BST in a Binary Tree - Notes

- The goal is to find the size (number of nodes) of the largest subtree in a given binary tree that is also a Binary Search Tree (BST).
- The largest BST may not include the root of the binary tree.

Approach:
1. Use postorder traversal (left, right, root) to process each node.
2. For each node, gather information from its left and right subtrees:
   - Whether the subtree is a BST.
   - The size of the largest BST in the subtree.
   - The minimum and maximum values in the subtree.
3. A subtree rooted at the current node is a BST if:
   - Both left and right subtrees are BSTs.
   - The current node's value is greater than the max value in the left subtree and less than the min value in the right subtree.
4. Track and update the size of the largest BST found so far.

Why this works:
- By collecting min/max and BST status from children, we can efficiently check BST property at each node.

Time Complexity:
- O(n), where n is the number of nodes in the binary tree (each node is visited once).

Use Cases:
- Finding the largest sorted subtree in an arbitrary binary tree.
- Useful in tree-based interview questions and applications.

Example:
    For a binary tree:
            5
           / \
          2   4
         / \
        1   3

    The largest BST is the left subtree (2, 1, 3) with size 3.
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
    
    Node* root = new Node(nodes[i]);

    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}

// Class to hold information about a subtree
class Info {
public:
    bool isBST; // Whether the current subtree is a BST
    int min, max; // Minimum and maximum values in the current subtree
    int size; // Size (number of nodes) in the current subtree

    Info(bool isBST, int min, int max, int size) {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

// Global variable to track the maximum size of any BST found
static int maxSize;

// Recursive function to find the largest BST in a binary tree
Info* largestBST(Node* root) {
    // Base case: An empty tree is a BST of size 0
    // Set min as INT_MAX and max as INT_MIN so comparisons work correctly
    if (root == NULL) return new Info(true, INT_MAX, INT_MIN, 0);

    // Recursively get info from left and right subtrees
    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    // Current subtree's min and max values
    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));

    // Current size is sum of left and right subtree sizes plus 1 (current node)
    int currSize = leftInfo->size + rightInfo->size + 1;

    // Check if current subtree is a BST:
    // - Left and right subtrees must be BSTs
    // - All nodes in the left subtree must be less than root->data
    // - All nodes in the right subtree must be greater than root->data
    if (leftInfo->isBST && rightInfo->isBST &&
        leftInfo->max < root->data &&
        root->data < rightInfo->min) {
        
        // Update the global max size of BST found
        maxSize = max(maxSize, currSize);

        // Return current subtree as valid BST
        return new Info(true, currMin, currMax, currSize);
    }

    // If current subtree is not BST, return false with correct min/max and size
    return new Info(false, currMin, currMax, currSize);
}

int main() {
    // Input vector in preorder format with -1 representing NULL to build a BT which contain BST.
    vector<int> nodes = {20, 10, 5, -1, -1, 15, -1, -1, 30, 25, 22, -1, -1, 28, -1, -1, 40, -1, -1};

    Node* root = buildTree(nodes);

    largestBST(root);

    cout << "max size of BST : " << maxSize << endl;

    return 0;
}