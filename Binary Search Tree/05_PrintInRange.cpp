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

void printRangeBST(Node* root, int st, int en){
    // Base case: If the current node is NULL, just return
    if (root == NULL) return;

    /*
    If current node's data is within the range [st, en]
    First, recursively print all values in the left subtree within range
    Then, print the current node's data
    Finally, recursively print all values in the right subtree within range
    This is essentially an inorder traversal, which prints values in sorted order for BST
    */
    if (st <= root->data && root->data <= en){
        printRangeBST(root->left, st, en);
        cout << root->data << " ";
        printRangeBST(root->right, st, en);
    }
    // If current node's data is less than the lower bound,
    // then only the right subtree can have values in range
    else if(root->data < st){
        printRangeBST(root->right, st, en);
    }
    // If current node's data is greater than the upper bound,
    // then only the left subtree can have values in range
    else{
        printRangeBST(root->left, st, en);
    }
}

int main(){
    vector<int> nodes = {3, 5, 7, 10, 12, 15, 17};
    Node* root = buildBST(nodes);

    int st = 7, en = 15;

    cout << "Range of elements lie between " << st << " and " << en << " in BST are : "; 
    printRangeBST(root,st,en);
    cout << endl;

    return 0;
}