// Node with minimum value in a BST

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

int minValueNode(Node* root)
{
    if (root == NULL)
    {
        std::cout << "Empty Binary Search tree ";
        return -1;
    }

    Node* current = root;

    // loop down to find the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current->data;
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
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);

    std::cout << "\n Minimum value in BST is " << minValueNode(root);

    return 0;
}

