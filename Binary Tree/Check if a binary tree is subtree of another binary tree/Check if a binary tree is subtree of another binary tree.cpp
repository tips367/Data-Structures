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
#define MAX 500

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

// Method 1: Time complexity - O(mn) where m and n are number of nodes in given two trees
/*
bool isSameTree(Node* T, Node* S)
{
    if (T == NULL || S == NULL)
    {
        return (T == NULL && S == NULL);
    }

    // Check if the data of both roots is same and data of left and right subtrees are also same
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

    // Check the tree with root as current node
    if (isSameTree(T, S))
        return true;
    else
        // If the tree with root as current node doesn't match then try left and right subtrees one by one
        return (isSubtree(T->left, S) || isSubtree(T->right, S));
} */

// Method 2: Optimized....Time complexity - O(n)
void storeInOrder(Node* root, char arr[], int& i)
{
    if (root == NULL) 
    {
        // adding special character to handle cases where a tree is present in another tree, but not as a subtree
        arr[i++] = '$';
        return;
    }
    storeInOrder(root->left, arr, i);
    arr[i++] = root->data;
    storeInOrder(root->right, arr, i);
}

void storePreOrder(Node* root, char arr[], int& i)
{
    if (root == NULL) 
    {
        arr[i++] = '$';
        return;
    }
    arr[i++] = root->data;
    storePreOrder(root->left, arr, i);
    storePreOrder(root->right, arr, i);
}

bool isSubtree(Node* T, Node* S)
{
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;

    // Store inorder traversals of T and S in inOrderT[0..m-1] and inOrderS[0..n-1] respectively
    char inOrderT[MAX], inOrderS[MAX];
    int m = 0, n = 0;
    storeInOrder(T, inOrderT, m);
    storeInOrder(S, inOrderS, n);
    inOrderT[m] = '\0';
    inOrderS[n] = '\0';

    // If inOrderS[] is not a substring of inOrderT[], return false
    if (strstr(inOrderT, inOrderS) == NULL)
        return false;

    // Store preorder traversals of T and S in preOrderT[0..m-1] and preOrderS[0..n-1] respectively
    char preOrderT[MAX], preOrderS[MAX];
    m = 0, n = 0;
    storePreOrder(T, preOrderT, m);
    storePreOrder(S, preOrderS, n);
    preOrderT[m] = '\0';
    preOrderS[n] = '\0';

    return (strstr(preOrderT, preOrderS) != NULL);
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
