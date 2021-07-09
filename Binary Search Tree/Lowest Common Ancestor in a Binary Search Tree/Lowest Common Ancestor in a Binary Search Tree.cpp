/* Given values of two nodes n1 and n2 in a Binary Search Tree, find the Lowest Common Ancestor (LCA). 
You may assume that both the values exist in the tree. 

                20
            /        \
           8          22
        /     \
       4       12
             /    \
            10    14

Examples:

Input: LCA of 10 and 14
Output:  12
Explanation: 12 is the closest node to both 10 and 14
which is a ancestor of both the nodes.

Input: LCA of 8 and 14
Output:  8
Explanation: 8 is the closest node to both 8 and 14
which is a ancestor of both the nodes.

Input: LCA of 10 and 22
Output:  20
Explanation: 20 is the closest node to both 10 and 22
which is a ancestor of both the nodes.
*/

#include <iostream>

class Node
{
public:
    int data;
    Node* left, * right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Method 1. Recursive
/*
Node* lca(Node* root, int n1, int n2)
{
    if (root == NULL) 
        return NULL;

    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);

    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);

    return root;
} */

//Method 2. Iterative
Node* lca(Node* root, int n1, int n2)
{
    while (root)
    {
        // If both n1 and n2 are smaller than root, then LCA lies in left
        if (root->data > n1 && root->data > n2)
            root = root->left;

        // If both n1 and n2 are greater than root, then LCA lies in right
        else if (root->data < n1 && root->data < n2)
            root = root->right;
        else
            break;
    }

    return root;
}

int main()
{
    /* Let us construct the BST
                20
            /        \
           8          22
        /     \
       4       12
             /    \
            10    14
    */

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int n1 = 10, n2 = 14;
    std::cout << "LCA of " << n1 << " and " << n2 << " is " << lca(root, n1, n2)->data << std::endl;

    n1 = 14, n2 = 8;
    std::cout << "LCA of " << n1 << " and " << n2 << " is " << lca(root, n1, n2)->data << std::endl;

    n1 = 10, n2 = 22;
    std::cout << "LCA of " << n1 << " and " << n2 << " is " << lca(root, n1, n2)->data << std::endl;
    return 0;
}


