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

// Method 1. Using Inorder Traversal.... Time complexity : O(n), Space : O(h)
/*
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
*/

// Method 2. Using Morris Traversal.... Time complexity : O(n), Space : O(1)
/*
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

Node* kthSmallest(Node* root, int k)
{
    if (root == NULL)
        return NULL;

    Node* kthSmallestNode = NULL;

    Node* current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            k--;
            if (k == 0)
                kthSmallestNode = current;
            current = current->right;
        }
        else
        {
            // find inorder predecessor of current
            Node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            // make current as right child of its inorder predecessor
            if (predecessor->right == NULL)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                // revert the changes, fix the right child of predecessor
                predecessor->right = NULL;
                k--;
                if (k == 0)
                    kthSmallestNode = current;
                current = current->right;
            }
        }
    }
    return kthSmallestNode;
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
*/

// Method 3. Using Modified Tree Data Structure.... Time complexity : O(h), Space : O(h)
class Node
{
public:
    int data;
    Node* left, * right;
    int leftCount;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
        leftCount = 0;
    }
};

Node* kthSmallest(Node* root, int k)
{
    if (root == NULL)
        return NULL;

    int count = root->leftCount + 1;
    if (count == k)
        return root;

    if (count > k)
        // search in left subtree
        return kthSmallest(root->left, k);

    // else search in right subtree
    return kthSmallest(root->right, k - count);
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
        // If a node is inserted in left subtree, then leftCount of this node is increased.
        root->leftCount++;
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


