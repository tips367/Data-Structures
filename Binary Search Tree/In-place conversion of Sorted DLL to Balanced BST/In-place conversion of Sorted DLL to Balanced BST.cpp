/* Given a Doubly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree
which has same data members as the given Doubly Linked List. The tree must be constructed in-place.
(No new node should be allocated for tree conversion)

Examples:

Input:  Doubly Linked List 1  2  3
Output: A Balanced BST
     2
   /  \
  1    3


Input: Doubly Linked List 1 2 3 4 5 6 7
Output: A Balanced BST
        4
      /   \
     2     6
   /  \   / \
  1   3  5   7

*/

#include <iostream>

class Node
{
public:
    int data;
    Node* next; // For tree, next pointer can be used as right subtree pointer
    Node* prev; // For tree, prev pointer can be used as left subtree pointer
};

int countNodes(Node* head)
{
    int count = 0;
    Node* temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node* sortedDLLToBSTRecur(Node*& headRef, int n)
{
    if (n <= 0)
        return NULL;

    // Recursively construct the left subtree
    Node* left = sortedDLLToBSTRecur(headRef, n / 2);

    // headRef now refers to middle node, make middle node as root of BST
    Node* root = headRef;
    root->prev = left;
    headRef = headRef->next;

    // Recursively construct the right subtree and link it with root
    // The number of nodes in right subtree is total nodes - nodes in left subtree - 1 (for root)
    root->next = sortedDLLToBSTRecur(headRef, n - n / 2 - 1);
    return root;
}

Node* sortedDLLToBST(Node* head)
{
    int n = countNodes(head);
    return sortedDLLToBSTRecur(head, n);
}

// Utility functions
/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void push(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
}

void printList(Node* node)
{
    while (node != NULL)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
}

/* A utility function to print
preorder traversal of BST */
void printPreOrder(Node* node)
{
    if (node == NULL)
        return;
    std::cout << node->data << " ";
    printPreOrder(node->prev);
    printPreOrder(node->next);
}

// A utility function to print Inoder traversal of a Binary Tree
void printInOrder(Node* node)
{
    if (node == NULL)
        return;
    printInOrder(node->prev);
    std::cout << node->data << " ";
    printInOrder(node->next);
}

int main()
{
    Node* head = NULL;

    // Create a sorted linked list to test the functions
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    std::cout << "Given Linked List\n";
    printList(head);

    Node* root = sortedDLLToBST(head);
    std::cout << "\nInOrder Traversal of constructed BST \n ";
    printInOrder(root);
    std::cout << "\nPreOrder Traversal of constructed BST \n ";
    printPreOrder(root);

    return 0;
}

