/* Write a function to connect all the adjacent nodes at the same level in a binary tree. 
Structure of the given Binary Tree node is like following.

class Node {
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
}

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers 
to point next right for each node.

Example:


Input Tree

       A
      / \
     B   C
    / \   \
   D   E   F


Output Tree

       A--->NULL
      / \
     B-->C-->NULL
    / \   \
   D-->E-->F-->NULL

*/

#include <iostream>
#include <queue>

class Node
{
public:
    int data;
    Node* left, * right, * nextRight;
    Node(int data)
    {
        this->data = data;
        left = right = nextRight = NULL;
    }
};

void connectNodesAtSameLevel(Node* root)
{
    if (root == NULL)
        return;

    std::queue<Node*> q;
    // Enqueue root
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        Node* previousNode = NULL;

        // Iterate for all the nodes in the queue currently
        while (count--)
        {
            Node* node = q.front();
            q.pop();

            if (previousNode != NULL)
                previousNode->nextRight = node;
            previousNode = node;

            // Enqueue left child
            if (node->left != NULL)
                q.push(node->left);

            // Enqueue right child
            if (node->right != NULL)
                q.push(node->right);
        }
    }
}

int main()
{
    /* Constructed binary tree is
                  10 
                /    \
              8       2
             / \       \
            3   5       90
    */

    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(90);

    // Populates nextRight pointer in all nodes
    connectNodesAtSameLevel(root);

    // check the values of nextRight pointers
    printf("Following are populated nextRight pointers in \n"
        "the tree (-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
        root->nextRight ? root->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->data,
        root->left->nextRight ? root->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->data,
        root->right->nextRight ? root->right->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
        root->left->left->nextRight ? root->left->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->right->data,
        root->left->right->nextRight ? root->left->right->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
        root->right->right->nextRight ? root->right->right->nextRight->data : -1);

    return 0;
}

