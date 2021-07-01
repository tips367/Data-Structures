/* Given a Binary Tree and a key, write a function that prints all the ancestors of the key in the given binary tree.

For example, if the given tree is following Binary Tree and key is 7, then your function should print 4, 2 and 1.

              1
            /   \
           2     3
         /  \
        4    5
       /
      7

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

bool printAncestors(Node* root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;

    // If target is present in either left or right subtree of this node, then print this node
    if (printAncestors(root->left, key) || printAncestors(root->right, key))
    {
        std::cout << root->data << " ";
        return true;
    }
    return false;
}

int main()
{

    /* Construct the following binary tree
                1
              /   \
             2     3
           /  \
          4    5
         /
        7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(7);

    printAncestors(root, 7);

    return 0;
}


