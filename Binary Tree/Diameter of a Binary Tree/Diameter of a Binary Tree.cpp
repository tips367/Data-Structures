/* The diameter of a tree(sometimes called the width) is the number of nodes on the longest path between two end nodes.
The diagram below shows tree with diameter nine, the leaves that form the ends of the longest path are shaded (note that 
there is more than one path in tree of length nine, but no path longer than nine nodes).

                O
              /   \
            O      O
           / \       \
         O    O       O
             / \        \
            O   0        O
                       /   \
                      O     O
                       \
                        0
*/

#include <iostream>
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

// Method 1. Time complexity : O(n^2) 
/*
int getHeight(Node* node)
{
    if (node == NULL)
        return 0;

    // If tree is not empty then height = 1 + max of left height and right heights
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

int diameter(Node* node)
{
    if (node == NULL)
        return 0;

    // get the height of left and right sub-trees
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    // get the diameter of left and right sub-trees
    int leftDiameter = diameter(node->left);
    int rightDiameter = diameter(node->right);

    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1
    return std::max(leftHeight + rightHeight + 1, std::max(leftDiameter, rightDiameter));
} */

// Method 2. Optimized......Time complexity : O(n)
int getHeight(Node* node, int& result)
{
    if (node == NULL)
        return 0;

    int leftHeight = getHeight(node->left, result);
    int rightHeight = getHeight(node->right, result);

    // update the answer, because diameter of a tree is nothing but maximum value of
    // (left_height + right_height + 1) for each node
    result = std::max(result, 1 + leftHeight + rightHeight);

    return 1 + std::max(leftHeight, rightHeight);
}

int diameter(Node* root)
{
    if (root == NULL)
        return 0;
    int result = INT_MIN; 
    getHeight(root, result);
    return result;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "Diameter of the given binary tree is " << diameter(root);

    return 0;
}

