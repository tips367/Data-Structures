// InsertionInCircularSinglyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

Node* addToEmpty(Node* last, int data)
{
    // This function is only for empty list 
    if (last != NULL)
        return last;

    Node* temp = new Node();

    temp->data = data;
    last = temp;

    // Creating the link. 
    last->next = last;

    return last;
}

Node* addBegin(Node* last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);

    Node* temp = new Node();

    temp->data = data;
    temp->next = last->next;
    last->next = temp;

    return last;
}

Node* addEnd(Node* last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);

    Node* temp = new Node();

    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}

Node* addAfter(Node* last, int data, int item)
{
    if (last == NULL)
        return NULL;

    Node* temp, * p;
    p = last->next;
    do
    {
        if (p->data == item)
        {
            temp = new Node();
            temp->data = data;
            temp->next = p->next;
            p->next = temp;

            if (p == last)
                last = temp;
            return last;
        }
        p = p->next;
    } while (p != last->next);

    std::cout << item << " not present in the list." << std::endl;
    return last;
}

void traverse(Node* last)
{
    Node* p;

    // If list is empty, return. 
    if (last == NULL)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    // Pointing to first Node of the list. 
    p = last->next;

    // Traversing the list. 
    do
    {
        std::cout << p->data << " ";
        p = p->next;

    } while (p != last->next);
}

// Driven Program 
int main()
{
    Node* last = NULL;

    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);

    traverse(last);

    return 0;
}