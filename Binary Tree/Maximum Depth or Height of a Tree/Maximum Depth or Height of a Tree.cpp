/* Given a binary tree, find it's maximum depth. Maximum depth of below tree is 3.

                       1
                     /   \
                    2     3
                  /  \
                 4    5
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

int getMaxDepth(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        // get the depth of each subtree
        int leftDepth = getMaxDepth(node->left);
        int rightDepth = getMaxDepth(node->right);

        // use the larger one
        return 1 + std::max(leftDepth, rightDepth);
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "Maximum depth of the tree is " << getMaxDepth(root);

    return 0;
}

