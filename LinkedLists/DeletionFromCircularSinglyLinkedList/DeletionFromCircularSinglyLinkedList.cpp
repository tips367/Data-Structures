// DeletionFromCircularSinglyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

void deleteNode(Node** headRef, int key)
{
    // If linked list is empty
    if (*headRef == NULL)
        return;
    // If the list contains only a single node
    if ((*headRef)->data == key && (*headRef)->next == *headRef)
    {
        free(*headRef);
        *headRef = NULL;
    }

    Node* last = *headRef, *d;

    // If head is to be deleted 
    if ((*headRef)->data == key)
    {
        // Find the last node of the list 
        while (last->next != *headRef)
            last = last->next;
        // Point last node to the next of head i.e. the second node of the list 
        last->next = (*headRef)->next;
        free(*headRef);
        *headRef = last->next;
    }
    while (last->next != *headRef && last->next->data != key)
        last = last->next;
    // If node to be deleted was found 
    if (last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    else
    {
        std::cout << "\nNo such key found.";
    }
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning of a Circular linked list */
void push(Node** headRef, int data)
{
    Node* ptr1 = new Node();
    Node* temp = *headRef;
    ptr1->data = data;
    ptr1->next = *headRef;

    /* If linked list is not NULL then
    set the next of last node */
    if (*headRef != NULL)
    {
        while (temp->next != *headRef)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; /*For the first node */

    *headRef = ptr1;
}

/* Function to print nodes in a given Circular linked list */
void printList(Node* head)
{
    Node* temp = head;
    if (head != NULL)
    {
        do
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}

int main()
{
    /* Initialize lists as empty */
    Node* head = NULL;

    /* Created linked list will be 2->5->7->8->10 */
    push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);

    std::cout << "List Before Deletion: ";
    printList(head);

    deleteNode(&head, 7);

    std::cout << "\nList After Deletion: ";
    printList(head);

    return 0;
}

