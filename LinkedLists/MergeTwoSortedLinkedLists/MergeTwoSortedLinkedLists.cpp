/* Write a SortedMerge() function that takes two lists, each of which is sorted in increasing order, and merges the two together 
into one list which is in increasing order. SortedMerge() should return the new list. The new list should be made by splicing 
together the nodes of the first two lists.

For example if the first linked list a is 5->10->15 and the other linked list b is 2->3->20, 
then SortedMerge() should return a pointer to the head node of the merged list 2->3->5->10->15->20.
*/

#include <iostream>
#include <assert.h>

class Node
{
public:
    int data;
    Node* next;
};

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the node from the front of the source, and move it to the front of the dest.
It is an error to call this with the source list empty.
Before calling MoveNode():
source == {1, 2, 3}
dest == {1, 2, 3}

Affter calling MoveNode():
source == {2, 3}
dest == {1, 1, 2, 3} */

void moveNode(Node** destRef, Node** sourceRef)
{
    // the front source node
    Node* newNode = *sourceRef;
    assert(newNode != NULL);

    // Advance the source pointer
    *sourceRef = newNode->next;

    // Link the old dest off the new node
    newNode->next = *destRef;

    // Move dest to point to the new node
    *destRef = newNode;
}

// 1. Using dummy node
Node* sortedMerge(Node* a, Node* b)
{
    // a dummy first node to hang the result on
    Node dummy;

    // tail points to the last result node 
    Node* tail = &dummy;

    // so tail->next is the place to add new nodes to the result. 
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            // if either list runs out, use the other list 
            tail->next = b;
            break;
        }
        if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            moveNode(&(tail->next), &a);
        else
            moveNode(&(tail->next), &b);

        tail = tail->next;
    }
    return (dummy.next);
} 

// 2. Another approach
/*
Node* sortedMerge(Node* a, Node* b)
{
    // a dummy first node to hang the result on
    Node dummy;

    // tail points to the last result node 
    Node* tail = &dummy;

    // so tail->next is the place to add new nodes to the result. 
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            // if either list runs out, use the other list 
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
    return (dummy.next);
} */

// 3. Using Recursion
/*
Node* sortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    // Base cases
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    // Pick either a or b and recur
    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}*/

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
    while (node != NULL)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
}

// Driver code
int main()
{
    /* Start with the empty list */
    Node* res = NULL;
    Node* a = NULL;
    Node* b = NULL;

    /* Let us create two sorted linked lists
    to test the functions
    Created lists, a: 5->10->15, b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);

    push(&b, 20);
    push(&b, 3);
    push(&b, 2);

    res = sortedMerge(a, b);

    std::cout << "Merged Linked List is: \n";
    printList(res);

    return 0;
}

