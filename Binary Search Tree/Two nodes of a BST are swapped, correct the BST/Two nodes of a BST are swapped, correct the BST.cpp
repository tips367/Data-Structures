/* Two of the nodes of a Binary Search Tree are swapped. Fix the BST. 

Input Tree:
         10
        /  \
       5    8
      / \
     2   20

In the above tree, nodes 20 and 8 must be swapped to fix the tree.  
Following is the output tree
         10
        /  \
       5    20
      / \
     2   8
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

// A utility function to swap two integers
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void correctBSTUtil(Node* root, Node*& firstStartPoint, Node*& lastEndPoint, Node*& prevNode)
{
    if (root == NULL)
        return;

    // Recur for the left subtree
    correctBSTUtil(root->left, firstStartPoint, lastEndPoint, prevNode);
    if (prevNode != NULL)
    {
        // If this node is smaller than the previous node, it's violating the BST rule.
        if (prevNode->data > root->data)
        {
            if (firstStartPoint == NULL)
                firstStartPoint = prevNode;
            lastEndPoint = root;
        }
    }
    prevNode = root;
    // Recur for the right subtree
    correctBSTUtil(root->right, firstStartPoint, lastEndPoint, prevNode);
}

void correctBST(Node* root)
{
    Node* firstStartPoint, * lastEndPoint, * prevNode;
    firstStartPoint = lastEndPoint = prevNode = NULL;
    correctBSTUtil(root, firstStartPoint, lastEndPoint, prevNode);

    // fix the BST
    swap(&(firstStartPoint->data), &(lastEndPoint->data));
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
    /* Create the following tree
    * 
          6
        /   \
       10     2
      / \    / \
     1   3  7  12

     10 and 2 are swapped

    */

    Node* root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);

    std::cout << "Inorder Traversal of the original tree \n";
    printInOrder(root);

    correctBST(root);

    std::cout << "\nInorder Traversal of the fixed tree \n";
    printInOrder(root);

    return 0;
}


