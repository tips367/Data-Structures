// Implement Queue using Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct QNode 
{
    int data;
    QNode* next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
private:
    QNode* m_pFront, * m_pRear;

public:
    Queue() : m_pFront(NULL), m_pRear(NULL) {}
    bool isEmpty();
    void enqueue(int item);
    int dequeue();
    int front();
    int rear();
    void display();
};

bool Queue::isEmpty()
{
    return (m_pFront == NULL && m_pRear == NULL);
}

void Queue::enqueue(int item)
{
    // Create a new LL node
    QNode* newNode = new QNode(item);

    if (isEmpty())
    {
        m_pFront = m_pRear = newNode;
    }
    else
    {
        m_pRear->next = newNode;
        m_pRear = newNode;
    }
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty\n";
        return INT_MIN;
    }

    QNode* temp = m_pFront;
    int item = m_pFront->data;
    m_pFront = m_pFront->next;

    // If front becomes NULL, then change rear also as NULL
    if (m_pFront == NULL)
    {
        m_pRear = NULL;
    }
    delete temp;
    return item;
}

int Queue::front()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty\n";
        return INT_MIN;
    }
    return m_pFront->data;
}

int Queue::rear()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty\n";
        return INT_MIN;
    }
    return m_pRear->data;
}

void Queue::display()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty\n";
        return;
    }

    QNode* temp = m_pFront;
    std::cout << "Queue is: ";
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

// Driver code
int main()
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);

    queue.display();
    std::cout << queue.dequeue() << " dequeued from queue\n";
    std::cout << queue.dequeue() << " dequeued from queue\n";
    queue.display();

    std::cout << "Front item is " << queue.front() << std::endl;
    std::cout << "Rear item is " << queue.rear() << std::endl;

    return 0;
}


