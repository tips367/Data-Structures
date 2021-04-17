
#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

void deleteNode(Node** headRef, int key)
{
    Node* temp = *headRef;
    Node* prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        // Changed head
        *headRef = temp->next; 
        // free old head
        delete temp;            
        return;
    }
    else
    {
        // Search for the key to be deleted, keep track of the previous node as we need to change prev->next
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == NULL)
            return;

        // Unlink the node from linked list
        prev->next = temp->next;

        // Free memory
        delete temp;
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
    Node* head = NULL;

    // Add elements in linked list
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    puts("Created Linked List: ");
    printList(head);

    deleteNode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");

    printList(head);

    return 0;
}
