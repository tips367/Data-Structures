/* Given two Linked Lists, create union and intersection lists that contain union and intersection of the elements 
present in the given lists. Order of elements in output lists doesn’t matter.

Example:
 
Input:
   List1: 10->15->4->20
   lsit2:  8->4->2->10
Output:
   Intersection List: 4->10
   Union List: 2->8->20->4->15->10
*/

#include <iostream>
#include <unordered_set>

class Node
{
public:
    int data;
    Node* next;
};

void appendAtEnd(Node** headRef, int newData);

Node* getIntersection(Node* head1, Node* head2)
{
    Node* result = NULL;
    std::unordered_set<int> s;

    while (head1)
    {
        s.insert(head1->data);
        head1 = head1->next;
    }

    while (head2)
    {
        if (s.find(head2->data) != s.end())
        {
            appendAtEnd(&result, head2->data);
        }
        head2 = head2->next;
    }
    return result;
}

Node* getUnion(Node* head1, Node* head2)
{
    Node* result = NULL;
    std::unordered_set<int> s;

    while (head1 || head2)
    {
        if (head1)
        {
            s.insert(head1->data);
            head1 = head1->next;
        }
        if (head2)
        {
            s.insert(head2->data);
            head2 = head2->next;
        }
    }

    for (auto i : s)
    {
        appendAtEnd(&result, i);
    }
    return result;
}

/* Utility Function to insert a node at
the end of the linked list */
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

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* intersection = NULL;
    Node* Union = NULL;

    /*create a linked lits 10->15->4->20 */
    push(&head1, 20);
    push(&head1, 4);
    push(&head1, 15);
    push(&head1, 10);

    /*create a linked lits 8->4->2->10 */
    push(&head2, 10);
    push(&head2, 2);
    push(&head2, 4);
    push(&head2, 8);

    intersection = getIntersection(head1, head2);
    Union = getUnion(head1, head2);

    std::cout << "First list is " << std::endl;
    printList(head1);

    std::cout << "\nSecond list is " << std::endl;
    printList(head2);

    std::cout << "\nIntersection list is " << std::endl;
    printList(intersection);

    std::cout << "\nUnion list is " << std::endl;
    printList(Union);

    return 0;
}

