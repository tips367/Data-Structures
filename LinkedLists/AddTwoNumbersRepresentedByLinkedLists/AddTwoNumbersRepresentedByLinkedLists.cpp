/* Given two numbers represented by two lists, write a function that returns the sum list. 
The sum list is list representation of the addition of two input numbers.

Example:

Input:
List1: 5->6->3 // represents number 365
List2: 8->4->2 // represents number 248
Output:
Resultant list: 3->1->6 // represents number 613
Explanation: 365 + 248 = 613

Input:
List1: 7->5->9->4->6 // represents number 64957
List2: 8->4 // represents number 48
Output:
Resultant list: 5->0->0->5->6 // represents number 65005
Explanation: 64957 + 48 = 65005
*/

#include <iostream>

class Node
{
public:
	int data;
	Node* next;
};

// Utility function that appends a new node at the end
void appendAtEnd(Node** headRef, int newData)
{
    // Allocate node
    Node* newNode = new Node();

    Node* last = *headRef;

    // Insert data in the new node
    newNode->data = newData;

    // This new node is going to be the last node, so make next of it as NULL
    newNode->next = NULL;

    // If the Linked List is empty, then make the new node as head
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }

    // Else traverse till the last node 
    while (last->next != NULL)
        last = last->next;

    // Change the next of last node
    last->next = newNode;
}

Node* addTwoNumbers(Node* first, Node* second)
{
	Node* result = NULL;
	int carry = 0, sum;
	while (first != NULL && second != NULL)
	{
		sum = first->data + second->data + carry;
		carry = sum / 10;
        appendAtEnd(&result, sum % 10);
        first = first->next;
        second = second->next;
	}
    // traversed completely one of the list and reached NULL
    first = first ? first : second;
    while (first != NULL)
    {
        sum = first->data + carry;
        carry = sum / 10;
        appendAtEnd(&result, sum % 10);
        first = first->next;
    }
    if (carry > 0)
    {
        appendAtEnd(&result, carry);
    }
    return result;
}

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
    while (node->next != NULL)
    {
        std::cout << node->data << "->";
        node = node->next;
    }
    std::cout << node->data << std::endl;
}

int main(void)
{
    Node* res = NULL;
    Node* first = NULL;
    Node* second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    std::cout << "First List is ";
    printList(first);

    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    std::cout << "Second List is ";
    printList(second);

    res = addTwoNumbers(first, second);
    std::cout << "Resultant list is ";
    printList(res);

    return 0;
}

