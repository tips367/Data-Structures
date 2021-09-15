// XOR Linked List : Memory efficient

#include <iostream>

class Node 
{
public: 
    int data;
    // Xor of next node and previous node
    Node* npx;
};

Node* XOR(Node* x, Node* y)
{
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}

void insert(Node*& headRef, int data)
{
    // Allocate memory for new node
    Node* newNode = new Node();
    newNode->data = data;

    // Since new node is inserted at the start , npx of new node will always be
    // Xor of current head and NULL
    newNode->npx = headRef;

    // If linked list is not empty, then npx of present head node will be Xor of new node
    // and node next to current head
    if (headRef != NULL)
    {
        headRef->npx = XOR(newNode, headRef->npx);
    }
    // Change head
    headRef = newNode;
}

void printList(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    std::cout << "The nodes of Linked List are: \n";

    while (curr != NULL) 
    {
        // print current node
        std::cout << curr->data << " ";

        // get address of next node: curr->npx is next ^ prev, so curr->npx ^ prev will be
        // next^prev^prev which is next
        next = XOR(prev, curr->npx);

        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
}

int main()
{
    Node* head = NULL;
    insert(head, 5);
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    printList(head);

    return (0);
}


