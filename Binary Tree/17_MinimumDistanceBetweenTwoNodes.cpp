/*
Minimum Distance Between Two Nodes in a Binary Tree (in terms of edges)

- The minimum distance between two nodes is the number of edges in the shortest path connecting them.
- This is also called the "distance" between two nodes.

How to find the minimum distance?
1. Find the Lowest Common Ancestor (LCA) of the two nodes.
2. Calculate the distance from the LCA to each node (number of edges).
3. The minimum distance = (distance from LCA to node1) + (distance from LCA to node2)

Example:
        1
       / \
      2   3
     / \
    4   5

- Minimum distance between 4 and 5:
    - LCA of 4 and 5 is 2.
    - Distance from 2 to 4 = 1 edge.
    - Distance from 2 to 5 = 1 edge.
    - Total minimum distance = 1 + 1 = 2

Applications:
- Useful in tree queries, network routing, and hierarchical data analysis.
*/

#include<iostream>
#include<vector>
using namespace std;

// Definition of a binary tree node
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

// Global index for building the tree from a vector
static int i = -1;

// Function to build a binary tree from a vector representation
Node* buildTree(vector<int> nodes){
    i++;
    if (nodes[i] == -1) return NULL; // -1 represents a NULL node
    Node* currNode = new Node(nodes[i]);
    
    // Recursively build the left and right subtrees
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

// Function to find the Lowest Common Ancestor (LCA) of two nodes in the binary tree
Node* LCA(Node* root, int n1 , int n2){
    if (root == NULL) return NULL; // Base case: if tree is empty, return NULL

    // If current node matches either n1 or n2, return current node as LCA candidate
    if (root->data == n1 || root->data == n2){
        return root;
    }

    // Recursively search for LCA in left and right subtrees
    Node* leftPath = LCA(root->left, n1, n2);
    Node* rightPath = LCA(root->right, n1, n2);

    // If both left and right subtrees return non-NULL, current node is the LCA
    if (leftPath != NULL && rightPath != NULL){
        return root;
    }
    
    // Otherwise, return the non-NULL child (if any)
    return leftPath ? leftPath : rightPath;
}

// Function to find the distance from root to a given target node
int findDist(Node* root, int target, int dist){
    if (root == NULL) return -1; // Base case: not found in this path

    if (root->data == target) return dist; // Target found, return current distance

    // Search in left subtree, incrementing distance
    int left = findDist(root->left, target, dist + 1);
    if (left != -1) return left; // If found in left, return distance

    // Otherwise, search in right subtree
    return findDist(root->right, target, dist + 1);
}

// Function to find the minimum distance between two nodes in the binary tree
int minDist(Node* root, int n1, int n2){
    Node* lca = LCA(root, n1, n2); // Find the Lowest Common Ancestor

    if (lca == NULL) return -1; // If LCA doesn't exist, nodes are not present

    // Find distance from LCA to n1 and n2
    int leftDist = findDist(lca, n1, 0);
    int rightDist = findDist(lca, n2, 0);

    // Minimum distance is the sum of both distances
    return leftDist + rightDist;
}

int main(){
    // Vector representation of the binary tree
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root = buildTree(nodes);

    int n1 = 4;
    int n2 = 3;

    int minDistBetweenNodes = minDist(root,n1,n2);

    cout << "Minimum distance between nodes " << n1 << " and " << n2 << " is " << minDistBetweenNodes << endl;
    return 0;
}