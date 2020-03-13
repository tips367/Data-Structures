// ReverseALinkedListInGroupsOfGivenSize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
	int data;
	Node* next;
};

Node* reverse(Node* head, int k)
{
	Node* prev = NULL;
	Node* current = head;
	Node* next = NULL;
	int count = 0;

	/*reverse first k nodes of the linked list */
	while (current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	/* next is now a pointer to (k+1)th node
	Recursively call for the list starting from current.
	And make rest of the list as next of first node */
	if (next != NULL)
	{
		head->next = reverse(next, k);
	}
	/* prev is new head of the input list */
	return prev;
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

// Driver code
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	std::cout << "Given Linked List is : \n";
	printList(head);

	head = reverse(head, 3);

	std::cout << "Reversed Linked List is: \n";
	printList(head);

	return 0;
}