/*
Transform to Sum Tree

- A Sum Tree is a binary tree where each node's value is replaced by the sum of the values of its left and right subtrees in the original tree.
- For leaf nodes, their value becomes 0 (since they have no children).

How to transform a tree into a sum tree?
- Use postorder traversal (Left → Right → Root).
- For each node:
    1. Recursively transform left and right subtrees.
    2. Store the original value of the node.
    3. Update the node's value to (sum of left subtree) + (sum of right subtree).
    4. Return the sum of the node's original value and its left and right subtree sums to the parent.

Example:
        10
       /  \
      -2   6
     / \  / \
    8 -4 7  5

After transformation:
        20
       /  \
      4    12
     / \  / \
    0  0 0  0

Applications:
- Used in tree-based queries and transformations.
- Useful for problems involving subtree sums and modifications.
*/

#include<iostream>
#include<vector>
#include<queue>
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

void levelorder(Node* root, queue<Node*>& q) { // Time => O(n), Space => O(n)
    if (root == NULL) return; // if tree empty or no node to process, return immediately

    q.push(root); // push root node into queue
    q.push(NULL); // push NULL as marker for end of current level

    while (!q.empty()) { // process until queue is empty
        Node* curr = q.front(); // get front node from queue
        q.pop(); // remove that node from queue

        if (curr == NULL){ // if NULL marker found → means level ended
            cout << endl; // print newline to separate levels
            if (q.empty()){ // if queue is empty after popping NULL, all levels processed
                break; // exit loop
            }
            q.push(NULL); // push NULL again to mark next level's end
        }else{
            cout << curr->data << " "; // print current node's data

            if (curr->left != NULL) q.push(curr->left); // if left child exists, enqueue it
            if (curr->right != NULL) q.push(curr->right); // if right child exists, enqueue it
        }
    }
}

int sumTree(Node* &root) {
    // Base Case: If the node is NULL, it contributes 0 to the sum
    if (root == NULL) return 0;

    // Recursively convert the left and right subtrees into sum trees
    // and collect their original values (before transformation)
    int leftOld = sumTree(root->left);
    int rightOld = sumTree(root->right);

    // Save the current node's original value before modifying it
    int currOld = root->data;

    // Initially set current node's value to the sum of original values
    // returned from the left and right subtrees
    root->data = leftOld + rightOld;

    // Additionally, if left child exists, add its current value
    // (which is already updated to a sum tree node value)
    if (root->left != NULL) root->data += root->left->data;

    // Similarly, if right child exists, add its sum tree value
    if (root->right != NULL) root->data += root->right->data;

    // Return the original value of this node to be used in parent's computation
    return currOld;
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root = buildTree(nodes);
    queue<Node*>q;
    sumTree(root);

    levelorder(root,q);
    return 0;
}