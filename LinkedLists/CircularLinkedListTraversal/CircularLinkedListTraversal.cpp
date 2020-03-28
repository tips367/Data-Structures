// CircularLinkedListTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

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

    /* Created linked list will be 11->2->56->12 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    std::cout << "Contents of Circular Linked List\n ";
    printList(head);

    return 0;
}