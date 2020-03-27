// RotateLinkedListCounterClockwiseByKNodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
	int data;
	Node* next;
};

// Utility function to count nodes in list
int getCount(Node* head)
{
	int count = 0;
	Node* current = head; 
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}
 
void rotate(Node** headRef, int k)
{
	if (k == 0)
		return;

	// For handling k greater than the number of nodes in list
	Node* current = *headRef;
	int numNodes = getCount(current);
	if (k > numNodes)
		k = k % numNodes;

	int count = 1;
	// current will point to kth node after this loop
	while (count < k && current != NULL)
	{
		current = current->next;
		count++;
	}
	if (current == NULL)
		return;

	Node* kthNode = current;
	// current will point to last node after this loop
	while (current->next != NULL)
		current = current->next;
	// change next of last node to previous head
	current->next = *headRef;
	// change head to (k+1)th node
	*headRef = kthNode->next;
	// change next of kth node to NULL
	kthNode->next = NULL;
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

	// create a list 10->20->30->40->50->60  
	for (int i = 60; i > 0; i -= 10)
		push(&head, i);

	std::cout << "Given Linked List is : \n";
	printList(head);

	rotate(&head, 4);

	std::cout << "Rotated Linked List is: \n";
	printList(head);

	return 0;
}