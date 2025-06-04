/*
Merging Two Binary Search Trees (BSTs) - Notes

- The goal is to merge two BSTs into a single balanced BST containing all elements from both trees.
- The merged BST should maintain the BST property.

Approach:
1. Perform inorder traversal on both BSTs to get two sorted arrays of their elements.
2. Merge the two sorted arrays into a single sorted array.
3. Build a balanced BST from the merged sorted array using the sorted array to balanced BST approach.

Why this works:
- Inorder traversal of a BST gives a sorted sequence.
- Merging two sorted arrays is efficient (O(n + m), where n and m are the sizes of the arrays).
- Building a balanced BST from a sorted array ensures minimal height.

Time Complexity:
- O(n + m) for traversals and merging, where n and m are the number of nodes in the two BSTs.
- O(n + m) for building the balanced BST.

Use Cases:
- Combining data from two BST-based sets or databases.
- Efficiently uniting two sorted collections while maintaining fast search capability.
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

void inorder(Node* root,vector<int>&vec){
    if (root == NULL) return;
    
    inorder(root->left,vec);
    vec.push_back(root->data);
    inorder(root->right,vec);
}

void merge(vector<int>nodes1, vector<int>nodes2, vector<int>& mergedNodes){
     int i = 0, j = 0;

    while (i < nodes1.size() && j < nodes2.size()){
        if (nodes1[i] < nodes2[j]){
            mergedNodes.push_back(nodes1[i++]);
        }else{
            mergedNodes.push_back(nodes2[j++]);
        }
    }

    while (i < nodes1.size()){
        mergedNodes.push_back(nodes1[i++]);
    }

    while (j < nodes2.size()){
        mergedNodes.push_back(nodes2[j++]);
    }
}

Node* helper(vector<int>mergedNodes, int st, int en){
    if (st > en) return NULL;

    int mid = st+(en - st)/2;

    Node* root = new Node(mergedNodes[mid]);

    root->left = helper(mergedNodes,st,mid-1);
    root->right = helper(mergedNodes,mid+1,en);

    return root;
}

Node* merge2BST(Node* root1, Node* root2){
    vector<int>nodes1;
    vector<int>nodes2;
    vector<int>mergedNodes;
    
    inorder(root1,nodes1);
    inorder(root2,nodes2);

    merge(nodes1,nodes2,mergedNodes);

    return helper(mergedNodes,0,mergedNodes.size()-1);
}

int main(){
    vector<int> bst1 = {10, 5, 15};
    vector<int> bst2 = {20, 17, 25};
    Node* root1 = buildBST(bst1);
    Node* root2 = buildBST(bst2);

    cout << merge2BST(root1,root2)->data << endl;
    return 0;
}