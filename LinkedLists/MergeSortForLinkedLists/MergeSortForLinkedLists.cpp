// MergeSortForLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

void frontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
    Node* slow;
    Node* fast;
    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

Node* mergeTwoSortedList(Node* a, Node* b)
{
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
        if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }
    return dummy.next;
}

void sortList(Node** headref) 
{
    Node* head = *headref;
    if (head == NULL || head->next == NULL)
        return;
    Node* a;
    Node* b;
    frontBackSplit(head, &a, &b);
    sortList(&a);
    sortList(&b);
    *headref = mergeTwoSortedList(a, b);
}

/* Utility Function to insert a node at
the beginging of the linked list */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Utility Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node->next != NULL)
    {
        std::cout << node->data << "->";
        node = node->next;
    }
    std::cout << node->data << std::endl;
}

// Driver code
int main()
{
    /* Start with the empty list */
    Node* a = NULL;

    /* Let us create a unsorted linked lists to test the functions
    Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    std::cout << "Unsorted Linked List is : \n";
    printList(a);

    sortList(&a);

    std::cout << "Sorted Linked List is: \n";
    printList(a);

    return 0;
}