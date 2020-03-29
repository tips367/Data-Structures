// InsertionInDoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

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

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        std::cout << "The given previous node cannot be NULL";
        return;
    }

    /* 2. allocate new node */
    Node* new_node = new Node();

    /* 3. put in the data */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;

    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;

    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void append(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();

    Node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so
        make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
        node as head */
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}

/* Given a node as next_node, insert a new node before the given node */
void insertBefore(Node** head_ref, Node* next_node, int new_data)
{
    /*1. check if the given next_node is NULL */
    if (next_node == NULL) {
        printf("The given next node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    Node* new_node = new Node();

    /* 3. put in the data */
    new_node->data = new_data;

    /* 4. Make prev of new node as prev of next_node */
    new_node->prev = next_node->prev;

    /* 5. Make the prev of next_node as new_node */
    next_node->prev = new_node;

    /* 6. Make next_node as next of new_node */
    new_node->next = next_node;

    /* 7. Change next of new_node's previous node */
    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    /* 8. If the prev of new_node is NULL, it will be
       the new head node */
    else
        (*head_ref) = new_node;
}

// This function prints contents of  
// linked list starting from the given node  
void printList(Node* node)
{
    Node* last = NULL;
    std::cout << "\nTraversal in forward direction \n";
    while (node != NULL)
    {
        std::cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }

    std::cout << "\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        std::cout << " " << last->data << " ";
        last = last->prev;
    }
}

/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;

    // Insert 6. So linked list becomes 6->NULL  
    append(&head, 6);

    // Insert 7 at the beginning. So  
    // linked list becomes 7->6->NULL  
    push(&head, 7);

    // Insert 1 at the beginning. So  
    // linked list becomes 1->7->6->NULL  
    push(&head, 1);

    // Insert 4 at the end. So linked  
    // list becomes 1->7->6->4->NULL  
    append(&head, 4);

    // Insert 8, after 7. So linked  
    // list becomes 1->7->8->6->4->NULL  
    insertAfter(head->next, 8);

    // Insert 2, before 7. So linked
    // list becomes 1->2->7->8->6->4->NULL 
    insertBefore(&head, head->next, 2);

    std::cout << "Created doubly linked list is: ";
    printList(head);

    return 0;
}


