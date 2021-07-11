/* Given the root of a binary search tree and K as input, find Kth smallest element in BST. 
For example, in the following BST, if k = 3, then the output should be 10, and if k = 5, then the output should be 14.

                    20
                  /   \
                 8     22
               /  \
              4   12
                 /  \
                10  14
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

Node* kthSmallest(Node* root, int& k)
{
    if (root == NULL)
        return NULL;

    // search in left subtree
    Node* left = kthSmallest(root->left, k);

    // if k'th smallest is found in left subtree, return it
    if (left != NULL)
        return left;

    // if current element is k'th smallest, return it
    k--;
    if (k == 0)
        return root;

    // else search in right subtree
    return kthSmallest(root->right, k);
}

// A utility function to insert a new node with given key in BST
Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        // Insert the first node, if root is NULL.
        return new Node(value);
    }

    if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        root->left = insert(root->left, value);
    }

    // Return root node, after insertion.
    return root;
}

int main()
{
    Node* root = NULL;

    /* creating the tree

                    20
                  /   \
                 8     22
               /  \
              4   12
                 /  \
                10  14
    */

    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    int k = 3;

    Node* result = kthSmallest(root, k);
    if (result == NULL)
        std::cout << "There are less than k nodes in the BST";
    else
        std::cout << "K-th Smallest Element is " << result->data;

    return 0;
}


