/*
Kth Level of a Binary Tree

- The Kth level of a binary tree contains all nodes that are exactly K edges away from the root.
- The root node is at level 1 (sometimes level 0, depending on convention).

How to find all nodes at the Kth level?
- Use recursion:
    - If current level is K, print the node.
    - Otherwise, recursively check left and right subtrees with level incremented by 1.
- Alternatively, use level order traversal (BFS) and print nodes at the Kth level.

Example:
        1
       / \
      2   3
     / \
    4   5

- Nodes at level 2: 2, 3
- Nodes at level 3: 4, 5

Applications:
- Useful for printing nodes at a specific depth.
- Used in level order traversal, tree queries, and tree algorithms.
*/

#include<iostream>
#include<vector>
#include<queue>
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

void KthLevel(Node* root, int k) {
    if (root == NULL) return; // If tree is empty, nothing to print

    queue<Node*> q; // Queue for level order traversal (BFS)
    q.push(root); // Start with the root node

    int level = 0; // Track the current level (root is level 0)

    while (!q.empty()) {
        int size = q.size(); // Number of nodes at the current level
        
        // Process all nodes at the current level
        for (int i = 0; i < size; i++) {
            Node* currNode = q.front();
            q.pop();

            // If current level is the desired level, print the node's data
            if (level == k - 1) {
                cout << currNode->data << " ";
            }

            // Add left child to queue if it exists
            if (currNode->left != NULL) q.push(currNode->left);
            // Add right child to queue if it exists
            if (currNode->right != NULL) q.push(currNode->right); 
        }

        // If we've reached the desired level, stop processing further levels
        if (level == k) break;

        level++; // Move to the next level
    }

    cout << endl; // Print newline after printing all nodes at kth level
}


int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int n = 2;
    Node* root = buildTree(nodes);
    KthLevel(root,n);

    return 0;
}