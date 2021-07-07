// Check if a binary tree is BST or not

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

// Method 1. Inefficient.....Time complexity : O(n^2)
/*
bool isSubtreeLesser(Node* root, int key)
{
    if (root == NULL)
        return true;

    if (root->data < key &&
        isSubtreeLesser(root->left, key) && isSubtreeLesser(root->right, key))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSubtreeGreater(Node* root, int key)
{
    if (root == NULL)
        return true;

    if (root->data > key &&
        isSubtreeGreater(root->left, key) && isSubtreeGreater(root->right, key))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isBinarySearchTree(Node* root)
{
    if (root == NULL)
        return true;

    if (isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data)
        && isBinarySearchTree(root->left) && isBinarySearchTree(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
} */

// Method 2: Efficient.....Time complexity : O(n)
bool isBinarySearchTreeUtil(Node* root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;

    if(root->data > minValue && root->data < maxValue
        && isBinarySearchTreeUtil(root->left, minValue, root->data)
        && isBinarySearchTreeUtil(root->right, root->data, maxValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isBinarySearchTree(Node* root)
{
    return isBinarySearchTreeUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    if (isBinarySearchTree(root))
        std::cout << "Is BST";
    else
        std::cout << "Not a BST";

    return 0;
}


