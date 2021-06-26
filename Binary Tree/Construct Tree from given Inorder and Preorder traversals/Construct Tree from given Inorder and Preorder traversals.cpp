/* Let us consider the below traversals:

Inorder sequence: D B E A F C 
Preorder sequence: A B D E C F

Then the construted binary tree will be:

                 A
               /   \
             /       \
            B         C
           / \        /
         /     \    /
        D       E  F
*/

#include <iostream>
#include <unordered_map>

class Node
{
public:
    char data;
    Node* left, * right;
    Node(char data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Method 1: Time complexity - O(n^2)

/*
// Utility func to search index of value in arr[start...end]
int search(char arr[], int start, int end, char value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

Node* constructTree(char inOrder[], char preOrder[], int start, int end)
{
    static int preIndex = 0;

    if (start > end)
        return NULL;

    char curr = preOrder[preIndex];
    preIndex++;
    Node* node = new Node(curr);
    
    // If current node has no children then return
    if (start == end)
        return node;

    // Else find the index of current node in Inorder traversal
    int inIndex = search(inOrder, start, end, node->data);

    // Using index in Inorder traversal, construct left and right subtress
    node->left = constructTree(inOrder, preOrder, start, inIndex - 1);
    node->right = constructTree(inOrder, preOrder, inIndex + 1, end);

    return node;
} */

// Method 2: Using Hashing....Time complexity - O(n)
Node* constructTreeInternal(char inOrder[], char preOrder[], int start, int end, std::unordered_map<char, int>& map)
{
    static int preIndex = 0;

    if (start > end)
        return NULL;

    char curr = preOrder[preIndex];
    preIndex++;
    Node* node = new Node(curr);

    // If current node has no children then return
    if (start == end)
        return node;

    // Else find the index of current node in Inorder traversal
    int inIndex = map[curr];

    // Using index in Inorder traversal, construct left and right subtress
    node->left = constructTreeInternal(inOrder, preOrder, start, inIndex - 1, map);
    node->right = constructTreeInternal(inOrder, preOrder, inIndex + 1, end, map);

    return node;
}

Node* constructTree(char inOrder[], char preOrder[], int len)
{
    // Store indexes of all items so that we can find later
    std::unordered_map<char, int> map;
    for (int i = 0; i < len; i++)
        map[inOrder[i]] = i;

    return constructTreeInternal(inOrder, preOrder, 0, len - 1, map);
}

// Utility function to test built tree
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

// Utility function to test built tree
void printPreOrder(Node* node)
{
    if (node == NULL)
        return;

    // print node data
    std::cout << node->data << " ";

    // recur on left subtree
    printPreOrder(node->left);

    // then recur on right subtree
    printPreOrder(node->right);
}

int main()
{
    char inOrder[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char preOrder[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(inOrder) / sizeof(inOrder[0]);
    // Node* root = constructTree(inOrder, preOrder, 0, len - 1);   // for method 1
    Node* root = constructTree(inOrder, preOrder, len);

    // Test by printing inorder and preorder traversal of built tree
    std::cout << "Inorder traversal of the constructed tree is \n";
    printInOrder(root);
    std::cout << "\nPreorder traversal of the constructed tree is \n";
    printPreOrder(root);
}

