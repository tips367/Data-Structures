/* Create a data structure twoStacks that represents two stacks. Implementation of twoStacks should use only one array, 
i.e., both stacks should use the same array for storing elements. Following functions must be supported by twoStacks.

push1(int x) –> pushes x to first stack 
push2(int x) –> pushes x to second stack
pop1() –> pops an element from first stack and return the popped element 
pop2() –> pops an element from second stack and return the popped element

Implementation of twoStack should be space efficient.
*/

#include <iostream>

class twoStacks
{
    int* arr;
    int size;
    int top1, top2;
public:
    twoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    // Method to push an element x to stack1
    void push1(int x)
    {
        // There is at least one empty space for new element 
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;            
        }
        else
        {
            std::cout << "\nStack Overflow";
            exit(1);
        }
    }
    // Method to push an element x to stack2
    void push2(int x)
    {
        // There is at least one empty space for new element 
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            std::cout << "\nStack Overflow";
            exit(1);
        }
    }
    // Method to pop an element from stack1
    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            std::cout << "\nStack Underflow";
            exit(1);
        }
    }
    // Method to pop an element from stack2
    int pop2()
    {
        if (top2 < size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            std::cout << "\nStack Underflow";
            exit(1);
        }
    }
};

/* Driver program to test twStacks class */
int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    std::cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    std::cout << "\nPopped element from stack2 is " << ts.pop2();
    return 0;
}
