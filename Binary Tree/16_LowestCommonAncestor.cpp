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

Node* findLCA(Node* root, int n1 , int n2){ 
    // Time Complexity: O(N), where N is the number of nodes in the tree
    // Space Complexity: O(H), where H is the height of the tree (due to recursion stack)
    
    if (root == NULL) 
        return NULL; // Base case: if the current node is NULL, return NULL (no LCA found here)

    // If the current node matches either n1 or n2, then this node could be the LCA
    if (root->data == n1 || root->data == n2){
        return root;
    }

    // Recursively search for LCA in the left subtree
    Node* leftLCA = findLCA(root->left, n1, n2);

    // Recursively search for LCA in the right subtree
    Node* rightLCA = findLCA(root->right, n1, n2);

    // If both leftLCA and rightLCA are not NULL, it means n1 and n2 are found in 
    // different subtrees, so current node is their lowest common ancestor
    if (leftLCA != NULL && rightLCA != NULL) 
        return root;

    // Otherwise, if one side returns a non-NULL node, return that side's result
    // This means both n1 and n2 are located in that subtree or that subtree itself is n1 or n2
    return leftLCA ? leftLCA : rightLCA;
}



int main(){

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root = buildTree(nodes);

    int n1 = 4, n2 = 5; // Nodes to find LCA for

    Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}