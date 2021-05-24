/* We are given a stack data structure with push and pop operations, the task is to implement a queue using instances of stack data structure
and operations on them.
*/

#include <iostream>
#include <stack>

// Method 1. Enqueue operation costly
// This method makes sure that oldest entered element is always at the top of stack1, so that dequeue operation just pops from stack1.
// To put the element at top of stack1, stack2 is used.
/*
class Queue
{
public:
    void enqueue(int item);
    int dequeue();

private:
    std::stack<int> s1, s2;
};

void Queue::enqueue(int item)
{
    // Move all elements from s1 to s2
    while (!s1.empty()) 
    {
        s2.push(s1.top());
        s1.pop();
    }

    // Push item into s1
    s1.push(item);

    // Push everything back to s1
    while (!s2.empty()) 
    {
        s1.push(s2.top());
        s2.pop();
    }
}

int Queue::dequeue()
{
    // if first stack is empty
    if (s1.empty()) 
    {
        std::cout << "Queue is Empty";
        return INT_MIN;
    }

    // Return top of s1
    int x = s1.top();
    s1.pop();
    return x;
} */

// Method 2. Dequeue operation costly
// In this method, in en-queue operation, the new element is entered at the top of stack1. In de-queue operation, 
// if stack2 is empty then all the elements are moved to stack2 and finally top of stack2 is returned.
/*
class Queue
{
public:
    void enqueue(int item);
    int dequeue();

private:
    std::stack<int> s1, s2;
};

void Queue::enqueue(int item)
{
    s1.push(item);
}

int Queue::dequeue()
{
    // if both stacks are empty
    if (s1.empty() && s2.empty()) 
    {
        std::cout << "Queue is Empty";
        return INT_MIN;
    }

    // if s2 is empty, move elements from s1
    if (s2.empty()) 
    {
        while (!s1.empty()) 
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    // return the top item from s2
    int x = s2.top();
    s2.pop();
    return x;
} */

// Method 3. Implementation of method 2 using Function Call Stack
class Queue
{
public:
    void enqueue(int item);
    int dequeue();

private:
    std::stack<int> s;
};

void Queue::enqueue(int item)
{
    s.push(item);
}

int Queue::dequeue()
{
    if (s.empty())
    {
        std::cout << "Queue is Empty";
        return INT_MIN;
    }

    int item = s.top();
    s.pop();

    // if stack becomes empty, return the popped item
    if (s.empty())
    {
        return item;
    }

    int x = dequeue();

    // push popped item back to the stack
    s.push(item);
    // return the result of dequeue() call
    return x;
}

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    std::cout << q.dequeue() << '\n';
    std::cout << q.dequeue() << '\n';
    std::cout << q.dequeue() << '\n';

    q.enqueue(6);

    std::cout << q.dequeue() << '\n';
    std::cout << q.dequeue() << '\n';
    std::cout << q.dequeue() << '\n';


    return 0;
}


