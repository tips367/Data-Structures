// Implementation of Deque or Double ended queue using circular array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Deque
{
public:
    Deque(int capacity);
    bool isFull();
    bool isEmpty();
    void insertFront(int item);
    void insertRear(int item);
    int deleteFront();
    int deleteRear();
    int getFront();
    int getRear();
    void display();

private:
    int* m_array;
    int m_front, m_rear, m_capacity;
};

Deque::Deque(int capacity) : m_front(-1), m_rear(-1)
{
    m_capacity = capacity;
    m_array = new int[capacity];
}

bool Deque::isEmpty()
{
    return (m_front == -1 && m_rear == -1);
}

bool Deque::isFull()
{
    return ((m_front == 0 && m_rear == m_capacity - 1) 
          || m_front == m_rear + 1);
}

void Deque::insertFront(int item)
{
    if (isFull())
    {
        std::cout << "Deque is full\n";
        return;
    }

    if (isEmpty())
    {
        m_front = m_rear = 0;
    }
    else if (m_front == 0)  // front is at first position of queue
    {
        m_front = m_capacity - 1;
    }
    else
    {
        m_front--;
    }
    m_array[m_front] = item;  
}

void Deque::insertRear(int item)
{
    if (isFull())
    {
        std::cout << "Deque is full\n";
        return;
    }

    if (isEmpty())
    {
        m_front = m_rear = 0;
    }
    else if (m_rear == m_capacity - 1)  // rear is at last position of queue
    {
        m_rear = 0;
    }
    else
    {
        m_rear++;
    }
    m_array[m_rear] = item;
}

int Deque::deleteFront()
{
    int temp = m_array[m_front];
    if (isEmpty())
    {
        std::cout << "Deque is empty\n";
        return INT_MIN;
    }

    if (m_front == m_rear) // Only one item present in Deque
    {
        m_front = m_rear = -1;
    }
    else
    {
        if (m_front == m_capacity - 1)
        {
            m_front = 0;
        }
        else
        {
            m_front++;
        }
    }
    return temp;
}

int Deque::deleteRear()
{
    int temp = m_array[m_rear];
    if (isEmpty())
    {
        std::cout << "Deque is empty\n";
        return INT_MIN;
    }

    if (m_front == m_rear) // Only one item present in Deque
    {
        m_front = m_rear = -1;
    }
    else
    {
        if (m_rear == 0)
        {
            m_rear = m_capacity - 1;
        }
        else
        {
            m_rear--;
        }
    }
    return temp;
}

int Deque::getFront()
{
    if (isEmpty())
    {
        std::cout << "Deque is empty\n";
        return INT_MIN;
    }
    return m_array[m_front];
}

int Deque::getRear()
{
    if (isEmpty())
    {
        std::cout << "Deque is empty\n";
        return INT_MIN;
    }
    return m_array[m_rear];
}

void Deque::display()
{
    if (isEmpty())
    {
        std::cout << "Deque is empty\n";
        return;
    }

    int i = m_front;
    std::cout << "Deque is: ";
    while (i != m_rear)
    {
        std::cout << m_array[i] << " ";
        i = (i + 1) % m_capacity;
    }
    std::cout << m_array[m_rear] << std::endl;
}

int main()
{
    Deque dq(5);
    std::cout << "Insert element at rear end : 5 \n";
    dq.insertRear(5);

    std::cout << "Insert element at rear end : 10 \n";
    dq.insertRear(10);

    dq.display();

    std::cout << "Get rear element " << " " << dq.getRear() << std::endl;

    dq.deleteRear();
    std::cout << "After delete rear element new rear" << " become " << dq.getRear() << std::endl;

    std::cout << "Inserting element at front end : 15 \n";
    dq.insertFront(15);
    dq.display();

    std::cout << "get front element " << " " << dq.getFront() << std::endl;

    dq.deleteFront();

    std::cout << "After delete front element new " << "front become " << dq.getFront() << std::endl;
    return 0;
}