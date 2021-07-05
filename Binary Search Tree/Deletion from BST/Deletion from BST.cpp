// Deletion from BST

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

Node* minValueNode(Node* root)
{
    Node* current = root;

    // loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's data,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's data,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // if key is same as root's data, then this is the node to be deleted
    else
    {
        // Case 1. No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // Case 2. One child
        else if (root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3. Two children
        else
        {
            // Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);
            // Copy the inorder successor's data to this node
            root->data = temp->data;
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Utility function for inorder traversal of BST
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
    /* Create following BST
    
            50
         /     \
        30      70
       /  \     /  \
      20  40   60  80 

    */

    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    std::cout << "Inorder traversal of the given tree \n";
    printInOrder(root);

    std::cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    std::cout << "Inorder traversal of the modified tree \n";
    printInOrder(root);

    std::cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    std::cout << "Inorder traversal of the modified tree \n";
    printInOrder(root);

    std::cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    std::cout << "Inorder traversal of the modified tree \n";
    printInOrder(root);

    return 0;
}


