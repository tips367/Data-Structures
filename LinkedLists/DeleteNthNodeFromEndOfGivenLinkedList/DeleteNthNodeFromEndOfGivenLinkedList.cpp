/* Given a linked list and an integer N, the task is to delete the Nth node from the end of the given linked list.

Examples:

Input: 2 -> 3 -> 1 -> 7 -> NULL, N = 1
Output:
Created Linked list is:
2 3 1 7
Linked List after Deletion is:
2 3 1

Input: 1 -> 2 -> 3 -> 4 -> NULL, N = 4
Output:
Created Linked list is:
1 2 3 4
Linked List after Deletion is:
2 3 4
*/

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

void deleteNode(Node** headRef, int N)
{
    // If linked list is empty
    if (*headRef == NULL)
        return;

    // First pointer will point to the head of the linked list
    Node* first = *headRef;

    // Second pointer will point to the Nth node from the beginning after below loop
    Node* second = *headRef;

    for (int i = 0; i < N; i++)
    {
        // If count of nodes in the given linked list is <= N
        if (second->next == NULL)
        {
            // If count = N then delete the head node
            if (i == N - 1)
            {
                Node* temp = *headRef;
                *headRef = temp->next;
                delete temp;
            }
            return;
        }
        second = second->next;
    }

    // Increment both the pointers by one until second pointer reaches the end
    while (second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }

    // First must be pointing to the Nth node from the end by now
    // So, delete the node first is pointing to
    Node* temp = first->next;
    first->next = temp->next;
    delete temp;
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

    std::cout << "Created Linked list is: ";
    printList(head);

    deleteNode(&head, 1);
    std::cout << "\nLinked List after Deletion: ";

    printList(head);

    return 0;
}