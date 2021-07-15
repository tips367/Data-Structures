/* Given a binary tree and a key(node) value, find the floor and ceil value for that particular key value.

Floor Value Node: Node with the greatest data lesser than or equal to the key value. 
Ceil Value Node: Node with the smallest data larger than or equal to the key value.

For example, Let’s consider the Binary Tree below – 

          8
        /   \    
      4      12
    /  \    /  \
   2    6  10   14

Key: 11  Floor: 10  Ceil: 12
Key: 1   Floor: -1  Ceil: 2
Key: 6   Floor: 6   Ceil: 6
Key: 15  Floor: 14  Ceil: -1
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

// Method 1: Recursive
/*
int getCeil(Node* root, int value)
{
    if (root == NULL)
        return -1;

    // We found equal key
    if (root->data == value)
        return value;

    // If root's data is smaller, ceil must be in right subtree
    if (value > root->data)
    {
        return getCeil(root->right, value);
    }

    // Else, either left subtree or root has the ceil value
    int ceil = getCeil(root->left, value);
    return ceil >= value ? ceil : root->data;
}

int getFloor(Node* root, int value)
{
    if (root == NULL)
        return INT_MAX;

    // We found equal key
    if (root->data == value)
        return value;

    // If root's data is greater, floor must be in left subtree
    if (value < root->data)
    {
        return getFloor(root->left, value);
    }

    // Else, either right subtree or root has the floor value
    int floor = getFloor(root->right, value);
    return floor <= value ? floor : root->data;
} */

// Method 2: Iterative
void floorCeilBST(Node* root, int key)
{
    int floor = -1, ceil = -1;

    while (root) 
    {
        if (root->data == key) 
        {
            ceil = floor = root->data;
            break;
        }
        else if (key > root->data) 
        {
            floor = root->data;
            root = root->right;
        }
        else 
        {
            ceil = root->data;
            root = root->left;
        }
    }

    std::cout << "key: " << key << " Floor: " << floor << " Ceil: " << ceil << std::endl;
}

int main()
{
    /* Create the following tree
    *
          8
        /   \
       4     12
      / \    / \
     2   6  10  14

     */

    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    for (int i = 0; i < 16; i++)
        //  std::cout << "key: " << i << " Floor: " << getFloor(root, i)  << " Ceil: "  << getCeil(root, i) << std::endl; // for method 1
        floorCeilBST(root, i);

    return 0;
}


