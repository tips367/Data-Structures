/* Given pointer to the head node of a linked list, the task is to reverse the linked list. 
We need to reverse the list by changing the links between nodes.

Example:

Input: Head of following linked list
1->2->3->4->NULL
Output: Linked list should be changed to,
4->3->2->1->NULL
*/

#include <iostream>
#include <stack>

class Node
{
public:
    int data;
    Node* next;
};

// Method 1. Iterative
void reverse(Node** headReference)
{
    Node* current = *headReference;
    Node* prev = NULL;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headReference = prev;
}

// Method 2. Recursive
/*
Node* reverse(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // reverse the rest list and put the first element at the end
    Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    // fix the head pointer
    return rest;
} */

// Method 3. Using Stack
/*
void reverse(Node** headReference)
{
    // Create a stack s of Node type
    std::stack<Node*> s;
    Node* temp = *headReference;
    while (temp->next != NULL)
    {
        // Push all the nodes in to stack
        s.push(temp);
        temp = temp->next;
    }
    *headReference = temp;

    while (!s.empty())
    {
        // Store the top value of stack in list
        temp->next = s.top();

        // Pop the value from stack
        s.pop();

        // update the next pointer in the in the list
        temp = temp->next;
    }
    temp->next = NULL;
}
*/

// Method 4. Using only two pointers
/*
void reverse(Node** headReference)
{
    Node* current = *headReference;
    Node* next = NULL;

    while (current->next != NULL)
    {
        next = current->next;
        current->next = next->next;
        next->next = (*headReference);
        *headReference = next;
    }
} */

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

    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    std::cout << "Given Linked list is: \n";
    printList(head);
    reverse(&head);
    std::cout << "\nReversed Linked list: \n";
    printList(head);
    return 0;
}

