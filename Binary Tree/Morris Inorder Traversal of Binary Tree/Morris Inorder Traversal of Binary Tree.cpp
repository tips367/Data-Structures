/* Inorder Tree Traversal without Recursion and without stack (Morris Inorder Traversal).

                       1
                     /   \
                    2     3
                  /  \
                 4    5

Inorder (Left, Root, Right) : 4 2 5 1 3

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

// Time complexity : O(n), Space : O(1)
void morrisInOrderTraversal(Node* root)
{
    if (root == NULL)
        return;

    Node* current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            std::cout << current->data << " ";
            current = current->right;
        }
        else
        {
            // find inorder predecessor of current
            Node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            // make current as right child of its inorder predecessor
            if (predecessor->right == NULL)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                // revert the changes, fix the right child of predecessor
                predecessor->right = NULL;
                std::cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "Inorder traversal of binary tree is \n";
    morrisInOrderTraversal(root);

    return 0;
}