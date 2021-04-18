/* Given a singly linked list and a position, delete a linked list node at the given position.

Example:  

Input: position = 1, Linked List = 8->2->3->1->7
Output: Linked List =  8->3->1->7

Input: position = 0, Linked List = 8->2->3->1->7
Output: Linked List = 2->3->1->7
*/

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

void deleteNodeAtPosition(Node** headRef, int position)
{
    // If linked list is empty
    if (*headRef == NULL)
        return;

    Node* temp = *headRef;

    // If head needs to be removed
    if (position == 0)
    {
        // Changed head
        *headRef = temp->next;
        // free old head
        delete temp;
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;

    // Free memory
    delete(temp->next);

    // Unlink the deleted node from list
    temp->next = next;  
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
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);

    std::cout << "Created Linked list is: ";
    printList(head);
    deleteNodeAtPosition(&head, 3);
    std::cout << "\nLinked List after Deletion at position 3: ";
    printList(head);
    return 0;
}
