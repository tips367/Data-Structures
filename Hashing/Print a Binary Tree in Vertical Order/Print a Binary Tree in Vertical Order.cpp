/* Given a binary tree, print it vertically. The following example illustrates vertical order traversal.
* 
           1
        /    \
       2       3
     /   \   /   \
    4     5 6     7
              \     \
               8     9 
                        
The output of print this tree vertically will be:

4
2
1 5 6
3 8
7
9 
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

// Method 1: Time complexity : O(w*n), where w is the width of binary tree having n nodes
void findMinMax(Node* node, int& min, int& max, int horizontalDistance)
{
    if (node == NULL)
        return;

    // Update min and max
    min = std::min(min, horizontalDistance);
    max = std::max(max, horizontalDistance);

    // Recur for left and right subtrees
    findMinMax(node->left, min, max, horizontalDistance - 1);
    findMinMax(node->right, min, max, horizontalDistance + 1);
}

void printVerticalLine(Node* node, int verticalLine, int horizontalDistance)
{
    if (node == NULL)
        return;

    if (verticalLine == horizontalDistance)
        std::cout << node->data << " ";

    printVerticalLine(node->left, verticalLine, horizontalDistance - 1);
    printVerticalLine(node->right, verticalLine, horizontalDistance + 1);
}

void verticalOrder(Node* root)
{
    // Find min and max distances with resepect to root
    int min = 0, max = 0;
    findMinMax(root, min, max, 0);

    // Iterate through all possible vertical lines starting
    // from the leftmost line and print nodes line by line
    for (int verticalLine = min; verticalLine <= max; verticalLine++)
    {
        printVerticalLine(root, verticalLine, 0);
        std::cout << "\n";
    }
}

int main()
{
    // Create binary tree shown in above figure
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    std::cout << "Vertical order traversal is \n";
    verticalOrder(root);

    return 0;
}


