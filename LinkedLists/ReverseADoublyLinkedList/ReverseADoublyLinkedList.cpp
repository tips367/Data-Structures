// ReverseADoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

void reverse(Node** headRef)
{
    Node* temp = NULL;
    Node* current = *headRef;
    if (current == NULL || current->next == NULL)
        return;
    // swap next and prev for all nodes of doubly linked list
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    *headRef = temp->prev;
}

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

/* Driver code */
int main()
{
    /* Start with the empty list */
    Node* head = NULL;

    /* Let us create a sorted linked list to test the functions
    Created linked list will be 10->8->4->2 */
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    std::cout << "Original Linked list" << std::endl;
    printList(head);

    /* Reverse doubly linked list */
    reverse(&head);

    std::cout << "\nReversed Linked list" << std::endl;
    printList(head);

    return 0;
}