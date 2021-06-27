/* Given a binary tree, write a function to get the maximum width of the given tree. Width of a tree is 
maximum of widths of all levels. 

         1
        /  \
       2    3
     /  \     \
    4    5     8
              /  \
             6    7

For the above tree,
width of level 1 is 1,
width of level 2 is 2,
width of level 3 is 3
width of level 4 is 2.
So the maximum width of the tree is 3.

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

// Method 1. Using Level Order Traversal......Time compleity : O(n^2) in worst case, Space : O(n)
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

int getCurrentLevelWidth(Node* root, int level)
{
    if (root == NULL)
        return 0;

    if (level == 1)
        return 1;

    else if (level > 1)
    {
        return getCurrentLevelWidth(root->left, level - 1) + getCurrentLevelWidth(root->right, level - 1);
    }
}

int getMaxWidth(Node* root)
{
    int maxWidth = 0;
    int height = getHeight(root);
    for (int i = 1; i <= height; i++)
    {
        int currentLevelWidth = getCurrentLevelWidth(root, i);
        if (currentLevelWidth > maxWidth)
            maxWidth = currentLevelWidth;
    }
    return maxWidth;
} */

// Method 2. Using Level Order Traversal with Queue...Time compleity : O(n) , Space : O(w), w is the max width of the tree
int getMaxWidth(Node* root)
{
    if (root == NULL)
        return 0;

    int maxWidth = 0;

    std::queue<Node*> q;
    // Enqueue root
    q.push(root);

    // Do Level order traversal keeping track of number of nodes at every level
    while (!q.empty())
    {
        int count = q.size();
        if (count > maxWidth)
        {
            maxWidth = count;
        }

        // Iterate for all the nodes in the queue currently
        while (count--)
        {
            // Dequeue an node from queue
            Node* node = q.front();
            q.pop();

            // Enqueue left child
            if (node->left != NULL)
                q.push(node->left);

            // Enqueue right child
            if (node->right != NULL)
                q.push(node->right);
        }
    }
    return maxWidth;
}


int main()
{

    /* Construct bunary tree as:
              1
             /  \
            2    3
          /  \     \
         4    5     8
                   /  \
                  6    7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);

    std::cout << "Maximum width is " << getMaxWidth(root) << std::endl;
    return 0;
}

