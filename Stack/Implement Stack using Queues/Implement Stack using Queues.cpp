/* We are given a Queue data structure that supports standard operations like enqueue() and dequeue(). We need to implement a Stack data structure using \
only instances of Queue and queue operations allowed on the instances.*/

#include <iostream>
#include <queue>

// Method 1. Push operation costly
// This method makes sure that newly entered element is always at the front of ‘q1’, so that pop operation just dequeues from ‘q1’. 
// ‘q2’ is used to put every new element at front of ‘q1’.
/*
class Stack
{
public:
    Stack(): m_currentSize(0){}
    void push(int x);
    void pop();
    int top();
    int size();

private:
    std::queue<int> q1, q2;
    int m_currentSize;
};

void Stack::push(int x)
{
    m_currentSize++;
    // Push x first in empty q2
    q2.push(x);
    // Push all the remaining elements from q1 to q2.
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    // swap the two queues
    std::queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

void Stack::pop()
{
    if (q1.empty())
        return;
    q1.pop();
    m_currentSize--;
}

int Stack::top()
{
    if (q1.empty())
        return -1;
    return q1.front();
}

int Stack::size()
{
    return m_currentSize;
} */

// Method 2. Pop operation costly
// In push operation, the new element is always enqueued to q1. In pop() operation, if q2 is empty then all the elements except the last, 
// are moved to q2. Finally the last element is dequeued from q1 and returned.
class Stack
{
public:
    Stack() : m_currentSize(0) {}
    void push(int x);
    void pop();
    int top();
    int size();

private:
    std::queue<int> q1, q2;
    int m_currentSize;
};

void Stack::push(int x)
{
    m_currentSize++;
    q1.push(x);
}

void Stack::pop()
{
    if (q1.empty())
        return;
    // Leave one element in q1 and push others in q2.
    while (q1.size() != 1) 
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.pop();
    m_currentSize--;

    // swap the names of two queues
    std::queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

int Stack::top()
{
    if (q1.empty())
        return -1;
    // Leave one element in q1 and push others in q2.
    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    // last pushed element
    int temp = q1.front();
    // to empty the auxiliary queue after last operation
    q1.pop();
    // push last element to q2
    q2.push(temp);

    // swap the names of two queues
    std::queue<int> q = q1;
    q1 = q2;
    q2 = q;
    return temp;
}

int Stack::size()
{
    return m_currentSize;
}

// Driver code
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "current size: " << s.size() << std::endl;
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;

    std::cout << "current size: " << s.size() << std::endl;
    return 0;
}


