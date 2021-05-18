/* Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() 
and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of 
SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data 
structure like arrays, list, etc. 

Example:

Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should return 15, which is the minimum element in the current stack.

If we do pop two times on stack, the stack becomes
29  --> TOP
19
18

When getMin() is called, it should return 18 which is the minimum in the current stack.
*/

#include <iostream>

class Stack 
{

public:
    Stack(): m_top(-1){}
    bool isEmpty();
    bool isFull();
    int pop();
    void push(int x);
    int top();

private:
    static const int MAX = 1000;
    int arr[MAX];
    int m_top;

};

bool Stack::isEmpty()
{
    if (m_top == -1)
        return true;
    return false;
}

bool Stack::isFull()
{
    if (m_top == MAX - 1)
        return true;
    return false;
}

int Stack::pop()
{
    if (isEmpty()) 
    {
        std::cout << "Stack Underflow";
        return 0;
    }
    return arr[m_top--];
}

void Stack::push(int x)
{
    if (isFull()) 
    {
        std::cout << "Stack Overflow";
        return;
    }
    arr[++m_top] = x;
}

int Stack::top()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
        return 0;
    }
    return arr[m_top];
}

// Approach 1. Use two stacks, one to store actual stack elements and the other as an auxiliary stack to store minimum values
// Time complexity : O(1) for all operations,    Space : O(n)

/* A class that supports all the stack operations and one additional operation getMin() that returns the minimum element from stack at
any time. This class inherits from the stack class and uses an auxiliarry stack that holds minimum elements */
/*
class SpecialStack : public Stack 
{
public:
    int pop();
    void push(int x);
    int getMin();

private:
    Stack m_min;
};

void SpecialStack::push(int x)
{
    if (isEmpty()) 
    {
        Stack::push(x);
        m_min.push(x);
    }
    else 
    {
        Stack::push(x);
        int y = m_min.top();
        // Update min stack with appropriate minimum values
        if (x < y)
            m_min.push(x);
        else
            m_min.push(y);
    }
}

int SpecialStack::pop()
{
    int x = Stack::pop();
    // Removes top element from min stack also
    m_min.pop();
    return x;
}

int SpecialStack::getMin()
{
    return m_min.top();
}
*/

// Approach 2: Space optimized - limit the number of elements in the auxiliary stack
// push only when the incoming element of the main stack is smaller than or equal to the top of the auxiliary stack
// During pop, if the pop-off element equal to the top of the auxiliary stack, remove the top element of the auxiliary stack
// Time complexity : O(1) for all operations,    Space : O(n), The complexity in the worst case is the same as above 
// but in other cases, it will take slightly less space than the above approach as repetition is neglected.
/*
class SpecialStack : public Stack
{
public:
    int pop();
    void push(int x);
    int getMin();

private:
    Stack m_min;
};

void SpecialStack::push(int x)
{
    if (isEmpty())
    {
        Stack::push(x);
        m_min.push(x);
    }
    else
    {
        Stack::push(x);
        int y = m_min.top();
        // push only when the incoming element of main stack is smaller than or equal to top of auxiliary stack
        if (x <= y)
            m_min.push(x);
    }
}

int SpecialStack::pop()
{
    int x = Stack::pop();
    // if the pop-off element x equal to the top of the auxiliary stack, remove the top element of the auxiliary stack
    if (x == m_min.top())
    {
        m_min.pop();
    }
    return x;
}

int SpecialStack::getMin()
{
    return m_min.top();
} */

// Approach 3: Further optimized O(1) time complexity and O(1) space complexity solution 
// While pushing an element ‘e’ into the stack, store it as (e * DUMMY_VALUE + minFoundSoFar), this way we know what was the 
// minimum value present in the stack at the time ‘e’ was being inserted.
// To pop the actual value just return e / DUMMY_VALUE and set the new minimum as (minFoundSoFar % DUMMY_VALUE)
class SpecialStack : public Stack
{
public:
    int pop();
    void push(int x);
    int getMin();
    int peek();

private:
    int min = -1;
    static const int DUMMY_VALUE = 99999;
};

int SpecialStack::getMin()
{
    return min;
}

void SpecialStack::push(int x)
{
    if (isEmpty() || x < min)
    {
        min = x;
    }
    Stack::push(x * DUMMY_VALUE + min);
}

int SpecialStack::pop()
{
    int x = Stack::pop();

    if (!isEmpty())
    {
        min = Stack::top() % DUMMY_VALUE;
    }
    else
    {
        min = -1;
    }
    return x / DUMMY_VALUE;
}

int SpecialStack::peek()
{
    return Stack::top() / DUMMY_VALUE;
}

int main()
{
    SpecialStack st;
    st.push(18);
    st.push(19);
    st.push(29);
    std::cout << st.getMin() << std::endl;
    st.push(15);
    std::cout << st.getMin() << std::endl;
    st.push(16);
    std::cout << st.getMin() << std::endl;
    st.pop();
    st.pop();
    std::cout << st.getMin();

    return 0;
}

