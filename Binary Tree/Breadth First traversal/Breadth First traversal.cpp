/* Level order traversal of a tree is breadth first traversal for the tree. 

                       1
                     /   \
                    2     3
                  /  \
                 4    5

Level order traversal of the above tree is 1 2 3 4 5

*/

#include <iostream>
#include <queue>

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

// Method 1. Time compleity : O(n^2) in worst case, Space : O(n)
/*
int getHeight(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        // get the height of each subtree
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        // use the larger one
        if (leftHeight > rightHeight)
            return(leftHeight + 1);
        else
            return(rightHeight + 1);
    }
}

void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
    {
        std::cout << root->data << " ";
    }
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(Node* root)
{
    int height = getHeight(root);
    for (int i = 1; i <= height; i++)
    {
        printCurrentLevel(root, i);
    }
}
*/

// Method 2. Using Queue.......Time compleity : O(n) , Space : O(n)
void printLevelOrder(Node* root)
{
    if (root == NULL)
        return;

    std::queue<Node*> q;
    // Enqueue root
    q.push(root);

    while (!q.empty())
    {
        // Print front of queue and remove it from queue
        Node* node = q.front();
        std::cout << node->data << " ";
        q.pop();

        // Enqueue left child
        if (node->left != NULL)
            q.push(node->left);

        // Enqueue right child
        if (node->right != NULL)
            q.push(node->right);
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "\nLevel order traversal of binary tree is \n";
    printLevelOrder(root);

    return 0;
}
