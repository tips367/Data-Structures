/* Find the inorder successor and predecessor of a given key. In case the given key is not found in BST,
then return the two values within which this key will lie.
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

Node* minValueNode(Node* root)
{
    Node* current = root;

    // loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* maxValueNode(Node* root)
{
    Node* current = root;

    // loop down to find the rightmost leaf
    while (current && current->right != NULL)
        current = current->right;

    return current;
}

void findPredecessorAndSuccessor(Node* root, Node** predecessor, Node** successor, int key)
{
    if (root == NULL)
        return;

    // If key is present at root
    if (root->data == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            *predecessor = maxValueNode(root->left);
        }

        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            *successor = minValueNode(root->right);
        }
        return;
    }

    // If key is smaller than root's data, go to left subtree
    if (root->data > key)
    {
        *successor = root;
        findPredecessorAndSuccessor(root->left, predecessor, successor, key);
    }
    else // go to right subtree
    {
        *predecessor = root;
        findPredecessorAndSuccessor(root->right, predecessor, successor, key);
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
    int key = 65;    //Key to be searched in BST

   /* Create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 
       
   */

    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);


    Node* pre = NULL, *suc = NULL;

    findPredecessorAndSuccessor(root, &pre, &suc, key);

    if (pre != NULL)
        std::cout << "Predecessor is " << pre->data << std::endl;
    else
        std::cout << "No Predecessor";

    if (suc != NULL)
        std::cout << "Successor is " << suc->data;
    else
        std::cout << "No Successor";

    return 0;
}


