/*
Level Order Traversal (Breadth-First Search)

Definition:
- Visits all nodes level by level from top to bottom.
- At each level, it visits nodes from left to right.
- Uses a queue data structure (FIFO).

Steps:
1. Push the root node into the queue.
2. While the queue is not empty:
   a. Pop the front node and print its data.
   b. Push its left child (if it exists).
   c. Push its right child (if it exists).

Example Tree:
        1
       / \
      2   3
     / \   \
    4   5   6

Level Order Output: 1 2 3 4 5 6

Use Cases:
- Printing tree level by level.
- Finding shortest path in a tree or graph.
- Used in BFS algorithms and solving many tree-based problems.

Pseudocode:

levelOrder(root):
    if root is NULL:
        return
    queue ← new Queue
    queue.push(root)

    while queue is not empty:
        node ← queue.pop()
        print node.data
        if node.left exists:
            queue.push(node.left)
        if node.right exists:
            queue.push(node.right)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data; // node value
    Node* left; // pointer to left child
    Node* right; // pointer to right child

    Node(int data) {
        this->data = data; // assign data to node
        left = right = NULL; // initialize both children as NULL
    }
};

static int i = -1; // global index for buildTree

Node* buildTree(vector<int> nodes) { // Time => O(n), Space => O(1)
    i++; // move to next index
    if (nodes[i] == -1) return NULL; // -1 means NULL node

    Node* currNode = new Node(nodes[i]); // create new node
    currNode->left = buildTree(nodes); // build left subtree
    currNode->right = buildTree(nodes); // build right subtree

    return currNode; // return current node
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

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}; // tree nodes
    queue<Node*> q; // create queue for level order

    Node* root = buildTree(nodes); // build the tree
    levelorder(root, q); // perform level order traversal

    return 0;
}