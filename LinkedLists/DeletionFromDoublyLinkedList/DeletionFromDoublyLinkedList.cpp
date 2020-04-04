// DeletionFromDoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

void deleteNode(Node** headRef, Node* del)
{
    if (*headRef == NULL || del == NULL)
        return;
    // If the node to be deleted is head node
    if (*headRef == del)
        *headRef = del->next;
    // Change next only if node to be deleted is NOT the last node 
    if (del->next != NULL)
        del->next->prev = del->prev;
    // Change prev only if node to be deleted is NOT the first node
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    return;
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

/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;

    /* Let us create the doubly linked list 10<->8<->4<->2 */
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    std::cout << "Original Linked list ";
    printList(head);

    /* delete nodes from the doubly linked list */
    deleteNode(&head, head); /*delete first node*/
    deleteNode(&head, head->next); /*delete middle node*/
    deleteNode(&head, head->next); /*delete last node*/

    /* Modified linked list will be NULL<-8->NULL */
    std::cout << "\nModified Linked list ";
    printList(head);

    return 0;
}