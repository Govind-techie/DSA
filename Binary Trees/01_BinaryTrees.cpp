/*
Binary Tree Data Structure

Definition:
A Binary Tree is a hierarchical data structure where each node has at most two children:
    - The left child
    - The right child

Types of Binary Trees:
    - Full Binary Tree: Every node has 0 or 2 children.
    - Perfect Binary Tree: All internal nodes have 2 children and all leaves are at the same level.
    - Complete Binary Tree: All levels are completely filled except possibly the last, which is filled left to right.
    - Skewed Binary Tree: All nodes are either only on the left or only on the right (like a linked list).
    - Binary Search Tree (BST): A binary tree where left < root < right (a special case of binary tree).

Key Operations:
    - Insertion: Add nodes to the tree.
    - Deletion: Remove nodes from the tree.
    - Search: Check if a value exists (not efficient in general binary tree unless it's a BST).
    - Traversal: Visit all nodes in the tree:
        - Inorder (LNR)
        - Preorder (NLR)
        - Postorder (LRN)
        - Level-order (BFS using queue)

Time Complexity (in general for n nodes):
    - Search: O(n)
    - Insert: O(n)
    - Delete: O(n)
    - Traversal: O(n)

Use Cases:
    - Used in hierarchical data representations (e.g., file systems, expression trees).
    - Basis for advanced trees (BST, AVL, Heaps, etc.).
    - Useful in recursion and divide & conquer algorithms.

BINARY TREE REPRESENTATION:

        1
       / \
      2   3
     / \
    4   5

Note:
    - A Binary Tree does not enforce any value ordering rules like BST.
    - It is the foundation for many other advanced tree data structures.
    - Each node has at max 2 children.
*/


#include <iostream>
using namespace std;

// Implementation of Binary Trees:

// Define the structure of a node in the binary tree
struct Node {
    int data;       // Value stored in the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child
};

int main() {
    // Create nodes dynamically using 'new'
    Node* root = new Node();        // Root node
    Node* leftChild = new Node();   // Left child of root
    Node* rightChild = new Node();  // Right child of root
    
    // Assign data values to each node
    root->data = 1;
    leftChild->data = 2;
    rightChild->data = 3;
    
    // Link the left and right children to the root node
    root->left = leftChild;
    root->right = rightChild;
    
    // Print the data of each node to verify the structure
    cout << "Root Node: " << root->data << endl;
    cout << "Left Child: " << root->left->data << endl;
    cout << "Right Child: " << root->right->data << endl;
    
    return 0;
}

/*
Binary Tree Representation:

1
/ \
2   3

This is a simple binary tree with:
- 1 as the root node
- 2 as the left child of root
- 3 as the right child of root
*/

/*
Important Binary Tree terms:

1. Node:
   - Basic unit of a binary tree containing data and pointers to left and right children.

2. Root:
   - The topmost node of the tree.

3. Parent:
   - A node that has one or more children.

4. Child:
   - A node that descends from another node (its parent).

5. Sibling:
   - Nodes that share the same parent.

6. Leaf Node:
   - A node with no children (both left and right are NULL).

7. Internal Node:
   - A node that has at least one child (not a leaf).

8. Subtree:
   - A tree formed by any node and all its descendants.

9. Level:
   - The depth of a node from the root. (Root is at level 0)

10. Height of Tree:
    - Number of edges on the longest path from root to a leaf.

11. Depth of Node:
    - Number of edges from root to that node.

12. Binary Tree:
    - A tree where each node has at most 2 children (left and right).

13. Full Binary Tree:
    - Every node has 0 or 2 children (no node has only one child).

14. Complete Binary Tree:
    - All levels are completely filled except possibly the last, 
      and all nodes are as far left as possible.

15. Perfect Binary Tree:
    - All internal nodes have 2 children and all leaf nodes are at the same level.

16. Balanced Binary Tree:
    - Height difference between left and right subtrees of any node is at most 1.

17. Traversals:
    - Ways to visit all nodes:
        a) Inorder (Left, Root, Right)
        b) Preorder (Root, Left, Right)
        c) Postorder (Left, Right, Root)
        d) Level Order (Breadth First Search)

18. Size of Tree:
    - Total number of nodes in the tree.

19. Null Tree / Empty Tree:
    - A binary tree with no nodes (root is NULL).

20. Ancestor:
    - Any node that lies on the path from the node to the root.

21. Descendant:
    - Any node that lies in the subtree of another node.
*/