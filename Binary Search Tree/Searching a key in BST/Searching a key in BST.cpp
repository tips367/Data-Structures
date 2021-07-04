// Searching a key in BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

Node* search(Node* root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

int main()
{
    /* Constructed binary search tree is
                    8
                  /   \
                3      10
              /  \       \
            1     6       14
                 / \      /
                4   7    13
    */

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    if (search(root, 6) != NULL)
        std::cout << "Key is found";
    else
        std::cout << "Key Not found";
    return 0;
}
