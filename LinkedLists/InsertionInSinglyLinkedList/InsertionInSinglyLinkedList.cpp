
#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

// Inserts a new node on the front of the list.
void push(Node** headRef, int newData)
{
    // Allocate node
    Node* newNode = new Node();

    // Insert data in the new node
    newNode->data = newData;

    // Head will become the next of new node
    newNode->next = (*headRef);

    // Head will now point to new node
    (*headRef) = newNode;
}

// Given a node prevNode, insert a new node after the given prevNode
void insertAfter(Node* prevNode, int newData)
{
    if (prevNode == NULL)
    {
        std::cout << "The given previous node cannot be NULL";
        return;
    }

    // Allocate new node
    Node* newNode = new Node();

    // Insert data in the new node
    newNode->data = newData;

    // Make next of new node as next of prev_node
    newNode->next = prevNode->next;

    // Make the next of prev_node as new_node 
    prevNode->next = newNode;
}

// Appends a new node at the end
void appendAtEnd(Node** headRef, int newData)
{
    // Allocate node
    Node* newNode = new Node();

    Node* last = *headRef; 

    // Insert data in the new node
    newNode->data = newData;

    // This new node is going to be the last node, so make next of it as NULL
    newNode->next = NULL;

    // If the Linked List is empty, then make the new node as head
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }

    // Else traverse till the last node 
    while (last->next != NULL)
        last = last->next;

    // Change the next of last node
    last->next = newNode;
}

void printList(Node* node)
{
    while (node != NULL)
    {
        std::cout << " " << node->data;
        node = node->next;
    }
}

int main()
{
    Node* head = NULL;

    // Insert 6, So linked list becomes 6->NULL 
    appendAtEnd(&head, 6);

    // Insert 7 at the beginning, So linked list becomes 7->6->NULL 
    push(&head, 7);

    // Insert 1 at the beginning, So linked list becomes 1->7->6->NULL 
    push(&head, 1);

    // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL 
    appendAtEnd(&head, 4);

    // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL 
    insertAfter(head->next, 8);

    std::cout << "Created Linked list is: ";
    printList(head);

    return 0;
}

