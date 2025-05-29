/*
Top View of a Binary Tree

- The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
- For each vertical line (horizontal distance from root), only the first node encountered from top to bottom is included in the top view.

How to find the top view?
- Assign a horizontal distance (HD) to each node:
    - Root has HD = 0.
    - Left child has HD = parent's HD - 1.
    - Right child has HD = parent's HD + 1.
- Use level order traversal (BFS) to visit nodes.
- For each HD, store the first node encountered.
- The top view is the collection of these first nodes for all HDs, sorted by HD.

Example:
        1
       / \
      2   3
       \   \
        4   5

Top view: 2 1 3 5

Applications:
- Useful for visualizing tree structure.
- Used in tree-based graphics and layout algorithms.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void topView(Node* root){
    queue<Node*,int>q; // => (node,HD)
    map<int,int>m; // => (key: HD , val: node->data)

    q.push(make_pair(root,0));
    while (!q.empty()){
        pair<Node*,int> curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if (!m.count(currHD)){
            m[currHD] = currNode->data;
        }

        if (currNode->left != NULL){
            pair<Node*,int>left = make_pair(currNode->left,currHD-1);
            q.push(left);
        }
        if (currNode->right != NULL){
            pair<Node*,int>right = make_pair(currNode->right,currHD+1);
            q.push(right);
        }
    }

    for (auto it : m){
        cout << it.second << " ";
    }
}

int main(){
    
    return 0;
}