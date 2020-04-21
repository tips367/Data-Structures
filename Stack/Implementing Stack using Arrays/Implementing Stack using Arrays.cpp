// Implementing Stack using Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define MAX 100

class Stack
{
    int top;
    int a[MAX];

public:
    Stack()
    {
        top = -1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= MAX - 1)
    {
        std::cout << "Stack overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        std::cout << x << " pushed into stack" << std::endl;
        return true;
    }
}

int Stack::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack underflow" << std::endl;
        return 0;
    }
    return a[top--];
}

int Stack::peek()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
        return 0;
    }
    return a[top];
}

bool Stack::isEmpty()
{
    return (top < 0);
}

// Driver program to test above functions 
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << s.pop() << " popped from stack\n";

    return 0;
}

