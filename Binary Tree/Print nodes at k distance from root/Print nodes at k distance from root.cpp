/* Given a root of a tree, and an integer k. Print all the nodes which are at k distance from root. 

For example, in the below tree, 4, 5 & 8 are at distance 2 from root. 

            1
          /   \
        2      3
      /  \    /
    4     5  8

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

void printKDistantNodes(Node* root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }

    if (k == 0)
        std::cout << root->data << " ";
    else if (k > 0)
    {
        printKDistantNodes(root->left, k - 1);
        printKDistantNodes(root->right, k - 1);
    }
}

int main()
{

    /* Constructed binary tree is
                    1
                  /   \
                2      3
              /  \    /
            4     5  8
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);

    printKDistantNodes(root, 2);
    return 0;
}

