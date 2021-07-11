// Inorder Successor in Binary Search Tree

#include <iostream>


// Method 1: Uses parent pointer
/*
class Node
{
public:
    int data;
    Node* left, * right, * parent;
    Node(int data)
    {
        this->data = data;
        left = right = parent = NULL;
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

Node* inOrderSuccessor(Node* root, int key)
{
    // search the node - O(h)
    Node* current = search(root, key);

    if (current == NULL)
        return NULL;

    if (current->right != NULL)
    {  
        // Case 1: Node has right subtree
        return minValueNode(current->right); 
    }
    else
    {
        // Case 2: No right subtree 
        Node* p = current->parent;
        while (p != NULL && current == p->right)
        {
            current = p;
            p = p->parent;
        }
        return p;
    }
}

// A utility function to insert a new node with given key in BST
Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        // Insert the first node, if root is NULL.
        return new Node(value);
    }

    Node* temp;
    if (value > root->data)
    {
        temp = insert(root->right, value);
        root->right = temp;
        temp->parent = root;
    }
    else
    {
        temp = insert(root->left, value);
        root->left = temp;
        temp->parent = root;
    }

    // Return root node, after insertion.
    return root;
} */

// Method 2. Search from root
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

Node* inOrderSuccessor(Node* root, int key)
{
    // search the node - O(h)
    Node* current = search(root, key);

    if (current == NULL)
        return NULL;

    if (current->right != NULL)
    {  
        // Case 1: Node has right subtree
        return minValueNode(current->right); 
    }
    else 
    {   // Case 2: No right subtree
        Node* successor = NULL;
        Node* ancestor = root;

        while (ancestor != current) 
        {
            if (current->data < ancestor->data) 
            {
                successor = ancestor; // so far this is the deepest node for which current node is in left
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
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
    Node* root = NULL, * succ;

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

    int key = 14;
    succ = inOrderSuccessor(root, key);

    if (succ != NULL)
        std::cout << "Inorder Successor of " << key << " is " << succ->data;
    else
        std::cout << "\n Inorder Successor doesn't exit";

    return 0;
}


