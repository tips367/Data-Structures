// SortedInsertForCircularLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

void sortedInsert(Node** headRef, Node* newNode)
{
    Node* current = *headRef;
    // If Linked List is empty
    if (current == NULL)
    {
        newNode->next = newNode;
        *headRef = newNode;
    }
    // New node is to be inserted just before the head node
    else if (newNode->data <= current->data)
    {
        while (current->next != *headRef)
            current = current->next;
        newNode->next = *headRef;
        current->next = newNode;
        *headRef = newNode;
    }
    // New node is to be inserted somewhere after the head
    else
    {
        /* Locate the node before the point of insertion */
        while (current->next != *headRef && current->next->data < newNode->data)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
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
    int arr[] = { 12, 56, 2, 11, 1, 90 };

    /* start with empty linked list */
    Node* start = NULL;
    Node* temp;

    /* Create linked list from the array arr[].
       Created linked list will be 1->2->11->12->56->90 */
    for (int i = 0; i < 6; i++)
    {
        temp = new Node();
        temp->data = arr[i];
        sortedInsert(&start, temp);
    }
    printList(start);
    return 0;
}


/* Case 2 of the above algo can be optimized
else if (current->data >= new_node->data)
{
// swap the data part of head node and new node 
// assuming that we have a function swap(int *, int *) 
swap(&(current->data), &(new_node->data));

new_node->next = (*head_ref)->next;
(*head_ref)->next = new_node;
}
*/