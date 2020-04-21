// Implementing Stack using Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class StackNode {
public:
    int data;
    StackNode* next;
};

StackNode* newNode(int data)
{
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

bool isEmpty(StackNode* root)
{
    if (root == NULL)
        return true;
    return false;
}

void push(StackNode** root, int data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    std::cout << data << " pushed to stack" << std::endl;
}

int pop(StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main()
{
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    std::cout << pop(&root) << " popped from stack\n";

    std::cout << "Top element is " << peek(root) << std::endl;

    return 0;
}