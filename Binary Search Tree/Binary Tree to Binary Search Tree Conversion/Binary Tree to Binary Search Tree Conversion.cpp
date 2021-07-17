/* Given a Binary Tree, convert it to a Binary Search Tree. The conversion must be done in such a way that 
keeps the original structure of Binary Tree. 

Example 1

Input:
          10
         /  \
        2    7
       / \
      8   4
Output:
          8
         /  \
        4    10
       / \
      2   7


Example 2

Input:
          10
         /  \
        30   15
       /      \
      20       5
Output:
          15
         /  \
       10    20
       /      \
      5        30
*/

#include <iostream>
#include <vector>
#include <algorithm>

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

void convertTreeToVector(Node* node, std::vector<int>& v)
{
    if (node == NULL)
        return;
    convertTreeToVector(node->left, v);
    v.push_back(node->data);
    convertTreeToVector(node->right, v);
}

void vectorToBST(Node* node, std::vector<int>& vec, int* indexPtr)
{
    if (node == NULL)
        return;
    vectorToBST(node->left, vec, indexPtr);
    node->data = vec[*indexPtr];
    (*indexPtr)++;
    vectorToBST(node->right, vec, indexPtr);
}

void binaryTreeToBST(Node* root)
{
    if (root == NULL)
        return;

    // Create a vector and store inorder traversal of tree in vec
    std::vector<int> vec;
    convertTreeToVector(root, vec);

    // Sort the vector in ascending order
    std::sort(vec.begin(), vec.end());

    // copy sorted elements back to Binary tree
    int i = 0;
    vectorToBST(root, vec, &i);
}

// A utility function to print Inoder traversal of a Binary Tree
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
    Node* root = NULL;

    /* Construct the following binary tree
            10
           /  \
         30    15
        /       \
       20        5 
    */

    root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);

    std::cout << "Inorder Traversal of the given tree: \n";
    printInOrder(root);

    binaryTreeToBST(root);

    std::cout << "\nInorder Traversal of the converted BST: \n";
    printInOrder(root);

    return 0;
}

