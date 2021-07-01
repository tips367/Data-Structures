/* Given two binary trees, check if the first tree is subtree of the second one. A subtree of a tree T is a 
tree S consisting of a node in T and all of its descendants in T. The subtree corresponding to the root node 
is the entire tree; the subtree corresponding to any other node is called a proper subtree.
For example, in the following case, tree S is a subtree of tree T.

        Tree S

          10
        /    \
      4       6
       \
        30


        Tree T

              26
            /   \
          10     3
        /    \     \
      4       6      3
       \
        30

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

bool isSameTree(Node* T, Node* S)
{
    if (T == NULL || S == NULL)
    {
        return (T == NULL && S == NULL);
    }

    if (T->data == S->data)
    {
        return isSameTree(T->left, S->left) && isSameTree(T->right, S->right);
    }
    else
    {
        return false;
    }
}

bool isSubtree(Node* T, Node* S)
{
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;
    if (isSameTree(T, S))
        return true;
    else
        return (isSubtree(T->left, S) || isSubtree(T->right, S));
}

int main()
{
    // TREE T
    /* Construct the following tree

              26
            /   \
          10     3
        /    \     \
      4       6      3
       \
        30
    */

    Node* T = new Node(26);

    T->right = new Node(3);
    T->right->right = new Node(3);
    T->left = new Node(10);
    T->left->left = new Node(4);
    T->left->left->right = new Node(30);
    T->left->right = new Node(6);

    // TREE S
    /* Construct the following tree
    
          10
        /    \
      4       6
       \
        30
    */

    Node* S = new Node(10);
    S->right = new Node(6);
    S->left = new Node(4);
    S->left->right = new Node(30);

    if (isSubtree(T, S))
        std::cout << "Tree S is a subtree of Tree T";
    else
        std::cout << "Tree S is not a subtree of Tree T";

    return 0;
}
