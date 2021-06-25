/* Given a Binary Tree where every node has following structure. 

struct node {  
    int key; 
    struct node *left,*right,*random;
} 

The random pointer points to any random node of the binary tree and can even point to NULL, clone the given binary tree.
*/

#include <iostream>
#include <unordered_map>

class Node
{
public:
    int data;
    Node* left, * right, * random;
};

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->random = temp->right = temp->left = NULL;
    return temp;
}

Node* copyLeftRightNode(Node* treeNode, std::unordered_map<Node*, Node*>& map)
{
    if (treeNode == NULL)
        return NULL;
    Node* cloneNode = newNode(treeNode->data);
    map[treeNode] = cloneNode;
    cloneNode->left = copyLeftRightNode(treeNode->left, map);
    cloneNode->right = copyLeftRightNode(treeNode->right, map);
    return cloneNode;
}

void copyRandom(Node* treeNode, Node* cloneNode, std::unordered_map<Node*, Node*>& map)
{
    if (cloneNode == NULL)
        return;
    cloneNode->random = map[treeNode->random];
    copyRandom(treeNode->left, cloneNode->left, map);
    copyRandom(treeNode->right, cloneNode->right, map);
}

Node* cloneTree(Node* root)
{
    if (root == NULL)
        return NULL;
    std::unordered_map<Node*, Node*> map;
    Node* newTree = copyLeftRightNode(root, map);
    copyRandom(root, newTree, map);
    return newTree;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;

    // recur on left sutree
    printInorder(node->left);

    // print data of Node and its random
    std::cout << "[" << node->data << " ";
    if (node->random == NULL)
        std::cout << "NULL], ";
    else
        std::cout << node->random->data << "], ";

    // recur on right subtree
    printInorder(node->right);
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->random = root->left->right;
    root->left->left->random = root;
    root->left->right->random = root->right;

    std::cout << "Inorder traversal of original binary tree is: \n";
    printInorder(root);

    Node* clone = cloneTree(root);

    std::cout << "\n\nInorder traversal of cloned binary tree is: \n";
    printInorder(clone);

    return 0;
}