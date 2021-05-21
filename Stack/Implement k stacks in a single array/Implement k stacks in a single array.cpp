/* Create a data structure kStacks that represents k stacks. Implementation of kStacks should use only one array, i.e., k stacks should 
use the same array for storing elements. Following functions must be supported by kStacks.

push(int x, int sn) –> pushes x to stack number ‘sn’ where sn is from 0 to k-1
pop(int sn) –> pops an element from stack number ‘sn’ where sn is from 0 to k-1 
*/

#include <iostream>

class KStacks
{
public:
    KStacks(int k, int n);

    bool isFull();

    // To push an item in stack number where stackNumber is from 0 to k-1
    void push(int item, int stackNumber);

    // To pop an item from stack number where stackNumber is from 0 to k-1
    int pop(int stackNumber);

    // To check whether stack number 'stackNumber' is empty or not
    bool isEmpty(int stackNumber);

private:
    int* stackData;     // Array of size n to store actual content to be stored in stacks
    int* topOfStack;    // Array of size k to store indexes of top elements of stacks
    int* nextIndex;     // Array of size n to store next entry in all stacks and free list
    int nextAvailable;  // store the current free index
};

KStacks::KStacks(int k, int n)
{
    stackData = new int[n];
    topOfStack = new int[k];
    nextIndex = new int[n];

    // Initialize all stacks as empty
    for (int i = 0; i < k; i++)
    {
        topOfStack[i] = -1;
    }

    // Initialize all spaces as free
    nextAvailable = 0;
    for (int i = 0; i < n - 1; i++)
    {
        nextIndex[i] = i + 1;
    }
    nextIndex[n - 1] = -1;  // -1 is used to indicate end of free list
}

bool KStacks::isFull() 
{ 
    return (nextAvailable == -1);
}

bool KStacks::isEmpty(int stackNumber)
{
    return (topOfStack[stackNumber] == -1);
}

void KStacks::push(int item, int stackNumber)
{
    if (isFull())
    {
        std::cout << "Stack Overflow\n";
        return;
    }

    // Store index of first free slot
    int firstFreeSlotIndex = nextAvailable;
    // Update index of free slot to index of next slot in free list
    nextAvailable = nextIndex[firstFreeSlotIndex];

    // Update next of topOfStack and then topOfStack for stack number 'stackNumber'
    nextIndex[firstFreeSlotIndex] = topOfStack[stackNumber];
    topOfStack[stackNumber] = firstFreeSlotIndex;
    // Put the item in stack
    stackData[firstFreeSlotIndex] = item;
}

int KStacks::pop(int stackNumber)
{
    if (isEmpty(stackNumber))
    {
        std::cout << "Stack Underflow\n";
        return INT_MIN;
    }

    // Find index of top item in stack number 'stackNumber'
    int topItemIndex = topOfStack[stackNumber];
    // Change topOfStack to store next index of previous top
    topOfStack[stackNumber] = nextIndex[topItemIndex];

    // Attach the previous top to the beginning of free list
    nextIndex[topItemIndex] = nextAvailable;
    nextAvailable = topItemIndex;

    // Return the previous top item
    return stackData[topItemIndex];
}

int main()
{
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    KStacks ks(k, n);

    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);

    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    std::cout << "Popped element from stack 2 is " << ks.pop(2) << std::endl;
    std::cout << "Popped element from stack 1 is " << ks.pop(1) << std::endl;
    std::cout << "Popped element from stack 0 is " << ks.pop(0) << std::endl;

    return 0;
}
