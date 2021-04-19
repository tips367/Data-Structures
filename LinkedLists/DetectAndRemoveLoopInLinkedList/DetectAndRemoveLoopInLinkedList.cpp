// DetectAndRemoveLoopInLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>

class Node
{
public:
	int data;
	Node* next;
};

// Method 1: Check one by one
/*
void removeLoop(Node* loopNode, Node* head)
{
	Node* ptr1;
	Node* ptr2;
	ptr1 = head;
	while (1)
	{
		ptr2 = loopNode;
		while (ptr2->next != loopNode && ptr2->next != ptr1)
		{
			ptr2 = ptr2->next;
		}
		if (ptr2->next == ptr1)
			break;
		// If ptr2 didnt reach ptr1 then try the next node after ptr1
		ptr1 = ptr1->next;
	}
	ptr2->next = NULL;
}
*/

// Method 2: Better solution
/*
void removeLoop(Node* loopNode, Node* head)
{
	Node* ptr1 = loopNode;
	Node* ptr2 = loopNode;
	int k = 1;
	// Count no. of nodes in loop
	while (ptr1->next != ptr2)
	{
		ptr1 = ptr1->next;
		k++;
	}
	ptr1 = head;
	ptr2 = head;
	// Fix one pointer to head and move another to a kth node from the head
	for (int i = 0; i < k; i++)
		ptr2 = ptr2->next;
	// Move both pointer at same pace they will meet at loop starting point
	while (ptr2 != ptr1)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	// Get pointer to last node
	while (ptr2->next != ptr1)
		ptr2 = ptr2->next;
	ptr2->next = NULL;
}
*/

// Method 3: Optimized method 2, without counting nodes in loop.
void removeLoop(Node* loopNode, Node* head)
{
	Node* ptr1 = head;
	Node* ptr2 = loopNode;
	// this check is needed when slow and fast both meet at the head of the LL
	// eg: 1->2->3->4->5 and then 5->next = 1 i.e the head of the LL
	if (ptr1 == ptr2)
	{
		while (ptr2->next != ptr1)
			ptr2 = ptr2->next;
	}
	else
	{
		while (ptr1->next != ptr2->next)
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}
	ptr2->next = NULL;
}

// Method 4: Hashing
void hashAndRemove(Node* head)
{
	std::unordered_map<Node*, int> nodeMap;
	Node* last = NULL;
	while (head != NULL)
	{
		if (nodeMap.find(head) == nodeMap.end())
		{
			nodeMap[head]++;
			last = head;
			head = head->next;
		}
		else
		{
			last->next = NULL;
			break;
		}
	}
}

int detectAndRemoveLoop(Node* list)
{
	Node* slowPtr = list, *fastPtr = list;
	while (slowPtr && fastPtr && fastPtr->next)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if (slowPtr == fastPtr)
		{
			removeLoop(slowPtr, list);
			return 1;
		}
	}
	return 0;
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

Node* newNode(int key)
{
    Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}

// Driver Code 
int main()
{
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);
   // hashAndRemove(head);

    std::cout << "Linked List after removing loop:" << std::endl;

    printList(head);

    return 0;
}