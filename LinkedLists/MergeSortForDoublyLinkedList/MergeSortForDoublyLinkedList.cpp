// MergeSortForDoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

Node* split(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

// Function to merge two linked lists  
Node* mergeTwoSortedList(Node* first, Node* second)
{
    // If first linked list is empty  
    if (!first)
        return second;

    // If second linked list is empty  
    if (!second)
        return first;

    // Pick the smaller value  
    if (first->data < second->data)
    {
        first->next = mergeTwoSortedList(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = mergeTwoSortedList(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

Node* mergeSort(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node* second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return mergeTwoSortedList(head, second);
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

// A utility function to print a doubly linked list in  
// both forward and backward directions  
void print(Node* head)
{
    Node* temp = head;
    std::cout << "Forward Traversal using next pointer\n";
    while (head)
    {
        std::cout << head->data << " ";
        temp = head;
        head = head->next;
    }
    std::cout << "\nBackward Traversal using prev pointer\n";
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
}

// Driver program  
int main(void)
{
    Node* head = NULL;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);
    push(&head, 10);
    std::cout << "Linked List before sorting:\n";
    print(head);
    head = mergeSort(head);
    std::cout << "\n\nLinked List after sorting:\n";
    print(head);
    return 0;
}