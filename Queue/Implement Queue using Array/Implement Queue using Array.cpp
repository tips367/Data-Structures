// Implement Queue using Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Queue
{
public:
    Queue(int capacity);
    bool isFull();
    bool isEmpty();
    void enqueue(int item);
    int dequeue();
    int front();
    int rear();
    void display();
    
private:
    int* m_array;
    int m_front, m_rear, m_capacity;
};

Queue::Queue(int capacity) : m_front(-1), m_rear(-1)
{
    m_capacity = capacity;
    m_array = new int[capacity];
}

bool Queue::isEmpty()
{
    return (m_front == -1 && m_rear == -1);
}

bool Queue::isFull()
{
    return ((m_rear + 1) % m_capacity == m_front);
}

void Queue::enqueue(int item)
{
    if (isEmpty())
    {
        m_front = m_rear = 0;
        m_array[m_rear] = item;
    }
    else if (isFull())
    {
        std::cout << "Queue is full\n";
        return;
    }
    else
    {
        m_rear = (m_rear + 1) % m_capacity;
        m_array[m_rear] = item;
    }
}

int Queue::dequeue()
{
    int temp = m_array[m_front];
    if (isEmpty())
    {
        std::cout << "Queue is empty\n";
        return INT_MIN;
    }
    else if (m_front == m_rear)
    {
        m_front = m_rear = -1;
    }
    else
    {
        m_front = (m_front + 1) % m_capacity;
    }
    return temp;
}

int Queue::front()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty\n";
        return INT_MIN;
    }
    return m_array[m_front];
}

int Queue::rear()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty\n";
        return INT_MIN;
    }
    return m_array[m_rear];
}

void Queue::display()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty\n";
        return;
    }

    int i = m_front;
    std::cout << "Queue is: ";
    while (i != m_rear)
    {
        std::cout << m_array[i] << " ";
        i = (i + 1) % m_capacity;
    }
    std::cout << m_array[m_rear];
}

// Driver code
int main()
{
    Queue queue(100);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    std::cout << queue.dequeue() << " dequeued from queue\n";

    std::cout << "Front item is " << queue.front() << std::endl;
    std::cout << "Rear item is " << queue.rear() << std::endl;

    return 0;
}

