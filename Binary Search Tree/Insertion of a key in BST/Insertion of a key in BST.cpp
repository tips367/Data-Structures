// Insertion of a key in BST

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
} */

// Method 2: Iterative
Node* insert(Node* root, int value)
{
    Node* node = new Node(value);
    if (root == NULL)
    {
        return node;
    }
    Node* prev = NULL;
    while (root != NULL)
    {
        if (root->data > value)
        {
            prev = root;
            root = root->left;
        }
        else if (root->data < value)
        {
            prev = root;
            root = root->right;
        }
    }
    if (prev->data > value)
        prev->left = node;
    else
        prev->right = node;
}

// Utility function to test built tree
void printInOrder(Node* node)
{
    if (node == NULL)
        return;

    // recur on left subtree
    printInOrder(node->left);

    // print node data
    std::cout << node->data << " ";

    // then recur on right subtree
    printInOrder(node->right);
}

int main()
{
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    std::cout << "Inorder traversal of the constructed BST is \n";
    printInOrder(root);

    return 0;
}

