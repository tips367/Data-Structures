/* Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer. 
For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. 
*/

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
 
// Method 1
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

// Method 2. We can first make the linked list circular and then moving k-1 steps forward from head node, 
// making it null and make kth node as head.
/*
void rotate(Node** headRef, int k)
{
	if (k == 0)
		return;

	// For handling k greater than the number of nodes in list
	Node* current = *headRef;
	int numNodes = getCount(current);
	if (k > numNodes)
		k = k % numNodes;

	// traverse till the end
	while (current->next != NULL)
		current = current->next;

	current->next = *headRef;
	current = *headRef;

	// traverse the linked list to k-1 position which will be last element for rotated array.
	for (int i = 0; i < k - 1; i++)
		current = current->next;

	// update the head_ref and last element pointer to NULL
	*headRef = current->next;
	current->next = NULL;
} */

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