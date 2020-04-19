// Insertion Sort for Singly Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node** headRef, Node* newNode)
{
    if (*headRef == NULL || (*headRef)->data >= newNode->data)
    {
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else
    {
        Node* current = *headRef;
        /* Locate the node before the point of insertion */
        while (current->next != NULL && current->next->data < newNode->data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertionSort(Node** headRef)
{
    // Initialize sorted linked list 
    Node* sorted = NULL;
    // Traverse the given linked list and insert every node to sorted
    Node* current = *headRef;
    while (current != NULL)
    {
        // Store next for next iteration
        Node* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    // Update head_ref to point to sorted linked list
    *headRef = sorted;
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

// Driver program  
int main()
{
    struct Node* a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    printf("Linked List before sorting \n");
    printList(a);

    insertionSort(&a);

    printf("\nLinked List after sorting \n");
    printList(a);

    return 0;
}