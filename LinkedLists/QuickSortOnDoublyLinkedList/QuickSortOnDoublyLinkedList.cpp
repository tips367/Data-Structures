// QuickSortOnDoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

Node* partition(Node* l, Node* h)
{
    int pivot = h->data;
    Node* i = l->prev;
    for (Node* j = l; j != h; j = j->next)
    {
        if (j->data <= pivot)
        {
            i = i == NULL ? l : i->next;
            swap(&(i->data), &(j->data));
        }
    }
    i = i == NULL ? l : i->next;
    swap(&(i->data), &(h->data));
    return i;
}

void _quickSort(Node* l, Node* h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Node* p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

Node* lastNode(Node* head)
{
    while (head && head->next)
        head = head->next;
    return head;
}

void quickSort(Node* head)
{
    // Find last node
    Node* h = lastNode(head);
    _quickSort(head, h);
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
    Node* a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    std::cout << "Linked List before sorting \n";
    printList(a);

    quickSort(a);

    std::cout << "\nLinked List after sorting \n";
    printList(a);

    return 0;
}