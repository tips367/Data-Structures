/* Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. 
Swapping data of nodes may be expensive in many situations when data contains many fields. 

It may be assumed that all keys in the linked list are distinct.

Examples:

Input : 10->15->12->13->20->14,  x = 12, y = 20
Output: 10->15->20->13->12->14

Input : 10->15->12->13->20->14,  x = 10, y = 20
Output: 20->15->12->13->10->14

Input : 10->15->12->13->20->14,  x = 12, y = 13
Output: 10->15->13->12->20->14
*/

#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

// Method 1
/*
void swapNodes(Node** headReference, int x, int y)
{
    // Nothing to do if x and y are same
    if (x == y)
        return;
    // Search for x, keep track of previousX and currentX
    Node* previousX = NULL;
    Node* currentX = *headReference;
    while (currentX && currentX->data != x)
    {
        previousX = currentX;
        currentX = currentX->next;
    }
    // Search for y, keep track of previousY and currentY
    Node* previousY = NULL;
    Node* currentY = *headReference;
    while (currentY && currentY->data != y)
    {
        previousY = currentY;
        currentY = currentY->next;
    }

    // If either x or y is not present, nothing to do
    if (currentX == NULL || currentY == NULL)
        return;

    
    if (previousX != NULL)
        // If x is not head of linked list
        previousX->next = currentY;
    else 
        // Else make y as new head
        *headReference = currentY;

    if (previousY != NULL)
        // If y is not head of linked list
        previousY->next = currentX;
    else
        // Else make x as new head
        *headReference = currentX;

    // Swap next pointers of x and y
    Node* temp = currentY->next;
    currentY->next = currentX->next;
    currentX->next = temp;
}
*/

// Method 2. Optimized
void swap(Node*& a, Node*& b)
{
    Node* temp = a;
    a = b;
    b = temp;
}

void swapNodes(Node** headReference, int x, int y)
{

    // Nothing to do if x and y are same
    if (x == y)
        return;

    Node** a = NULL;
    Node** b = NULL;

    // search for x and y in the linked list and store therir pointer in a and b
    while (*headReference) {

        if ((*headReference)->data == x) {
            a = headReference;
        }
        else if ((*headReference)->data == y) {
            b = headReference;
        }
        headReference = &((*headReference)->next);
    }

    // if we have found both a and b in the linked list, swap current pointer and next pointer of these
    if (a && b) 
    {
        swap(*a, *b);
        swap(((*a)->next), ((*b)->next));
    }
}

// Utility function to print a linked list
void printList(Node* node)
{
    while (node != NULL)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
}

// Utility function to insert a new node on the front of the list.
void push(Node** headRef, int newData)
{
    Node* new_node = new Node();
    new_node->data = newData;
    new_node->next = (*headRef);
    (*headRef) = new_node;
}

int main()
{
    Node* start = NULL;

    /* The constructed linked list is: 10->15->12->13->20->14 */
    push(&start, 14);
    push(&start, 20);
    push(&start, 13);
    push(&start, 12);
    push(&start, 15);
    push(&start, 10);

    std::cout << "Linked list before calling swapNodes() ";
    printList(start);

    swapNodes(&start, 10, 20);

    std::cout << "\nLinked list after calling swapNodes() ";
    printList(start);

    return 0;
}

