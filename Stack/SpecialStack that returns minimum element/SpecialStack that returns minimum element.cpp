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

/* A class that supports all the stack operations and one additional operation getMin() that returns the minimum element from stack at
any time. This class inherits from the stack class and uses an auxiliarry stack that holds minimum elements */
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

