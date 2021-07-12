/* Given two Binary Search Trees(BST), print the elements of both BSTs in sorted form. 
The expected time complexity is O(m+n) where m is the number of nodes in the first tree and n is the number of nodes 
in the second tree. The maximum allowed auxiliary space is O(height of the first tree + height of the second tree).

Examples:

First BST 
       3
    /     \
   1       5

Second BST
       4
     /   \
   2       6
   
Output: 1 2 3 4 5 6

*/

#include <iostream>
#include <stack>

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

void merge(Node* root1, Node* root2)
{
    // st1 is stack to hold nodes of first BST
    std::stack<Node*> st1;
    Node* current1 = root1;

    // st2 is stack to hold nodes of second BST
    std::stack<Node*> st2;
    Node* current2 = root2;

    // If first BST is empty, then output is inorder traversal of second BST
    if (root1 == NULL)
    {
        printInOrder(root2);
        return;
    }
    // If second BST is empty, then output is inorder traversal of first BST
    if (root2 == NULL)
    {
        printInOrder(root1);
        return;
    }

    // Run the loop while there are nodes not yet printed.
    // The nodes may be in stack (explored, but not printed) or may be not yet explored
    while (current1 != NULL || !st1.empty() ||
           current2 != NULL || !st2.empty())
    {
        if (current1 != NULL || current2 != NULL)
        {
            // Reach the leftmost node of both BSTs and push ancestors of
            // leftmost nodes to stack s1 and s2 respectively
            if (current1 != NULL)
            {
                st1.push(current1);
                current1 = current1->left;
            }

            if (current2 != NULL)
            {
                st2.push(current2);
                current2 = current2->left;
            }
        }
        else
        {
            // If we reach a NULL node and either of the stacks is empty,
            // then one tree is exhausted, ptint the other tree
            if (st1.empty())
            {
                while (!st2.empty())
                {
                    current2 = st2.top();
                    st2.pop();
                    current2->left = NULL;
                    printInOrder(current2);
                }
                return;
            }
            if (st2.empty())
            {
                while (!st1.empty())
                {
                    current1 = st1.top();
                    st1.pop();
                    current1->left = NULL;
                    printInOrder(current1);
                }
                return;
            }

            // compare the top of both stacks
            current1 = st1.top();
            st1.pop();
            current2 = st2.top();
            st2.pop();

            // If element of first tree is smaller, then print it and push the right subtree.
            if (current1->data < current2->data)
            {
                std::cout << current1->data << " ";
                // we have visited the node and its left subtree. Now, it's right subtree turn
                current1 = current1->right;
                st2.push(current2);
                current2 = NULL;
            }
            else
            {
                std::cout << current2->data << " ";
                current2 = current2->right;
                st1.push(current1);
                current1 = NULL;
            }
        }
    }
}

int main()
{
    Node* root1 = NULL, * root2 = NULL;

    /* Create the following tree as first tree
         3
        / \
       1   5
    */
    root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    /* Create the following tree as second tree
         4
        / \
       2   6
    */
    root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    merge(root1, root2);

    return 0;
}

