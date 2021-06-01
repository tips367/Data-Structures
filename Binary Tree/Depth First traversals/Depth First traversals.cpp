/* Program for different tree traversals
                       1
                     /   \
                    2     3
                  /  \
                 4    5

Depth First Traversals:
(a) Inorder (Left, Root, Right) : 4 2 5 1 3
(b) Preorder (Root, Left, Right) : 1 2 4 5 3
(c) Postorder (Left, Right, Root) : 4 5 2 3 1
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

void printPostOrder(Node* node)
{
    if (node == NULL)
        return;

    // recur on left subtree
    printPostOrder(node->left);

    // then recur on right subtree
    printPostOrder(node->right);

    // print node data
    std::cout << node->data << " ";
}

void printPreOrder(Node* node)
{
    if (node == NULL)
        return;

    // print node data
    std::cout << node->data << " ";

    // recur on left subtree
    printPreOrder(node->left);

    // then recur on right subtree
    printPreOrder(node->right);
}

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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "\nPostorder traversal of binary tree is \n";
    printPostOrder(root);

    std::cout << "\nPreorder traversal of binary tree is \n";
    printPreOrder(root);

    std::cout << "\nInorder traversal of binary tree is \n";
    printInOrder(root);

    return 0;
}

