
// class Node{
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int data){
//         this->data = data;
//         left = right = NULL;
//     }
// };

// Node* insertNode(Node* root, int val){
//     if (root == NULL){
//         root = new Node(val);
//         return root;
//     }

//     if (val < root->data){
//         root->left = insertNode(root->left,val);
//     }else{
//         root->right = insertNode(root->right,val);
//     }

//     return root;
// }

// Node* buildBST(vector<int>nodes){
//     Node* root = NULL;

//     for (int i = 0 ; i < nodes.size() ; i++){
//         root = insertNode(root,nodes[i]);
//     }

//     return root;
// }

// void rootToLeaf(Node* root,vector<int>&path){
//     if (root == NULL) return;

//     path.push_back(root->data);

//     if (root->left == NULL && root->right == NULL){
//         cout << root->data << endl;
//         path.pop_back();
//     } 
    
//     rootToLeaf(root->left,path);

// }