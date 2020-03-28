// SplitCircularLinkedListIntoTwoHalves.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

void splitList(Node* head, Node** headRef1, Node** headRef2)
{
    if (head == NULL)
        return;
    Node* slowPtr = head;
    Node* fastPtr = head;
    /* If there are odd nodes in the circular list then fast_ptr->next becomes head and for even nodes
       fast_ptr->next->next becomes head */
    while (fastPtr->next != head && fastPtr->next->next != head)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    /* If there are even elements in list then move fast_ptr */
    if (fastPtr->next->next == head)
        fastPtr = fastPtr->next;
    /* Set the head pointer of first half */
    *headRef1 = head;
    /* Set the head pointer of second half */
    if(head->next != head)
        *headRef2 = slowPtr->next;
    /* Make second half circular */
    fastPtr->next = slowPtr->next;
    /* Make first half circular */
    slowPtr->next = head;
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

/* Driver program to test above functions */
int main()
{
    /* Initialize lists as empty */
    Node* head = NULL;
    Node* head1 = NULL;
    Node* head2 = NULL;

    /* Created linked list will be 11->2->56->12 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    std::cout << "Original Circular Linked List\n";
    printList(head);

    /* Split the list */
    splitList(head, &head1, &head2);

    std::cout << "\nFirst Circular Linked List\n";
    printList(head1);

    std::cout << "\nSecond Circular Linked List\n";
    printList(head2);
    return 0;
}