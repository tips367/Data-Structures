/* Create a data structure kQueues that represents k queues. Implementation of kQueues should use only one array, i.e., k queues should 
use the same array for storing elements. Following functions must be supported by kQueues.

enqueue(int x, int qn) –> adds x to queue number ‘qn’ where qn is from 0 to k-1 
dequeue(int qn) –> deletes an element from queue number ‘qn’ where qn is from 0 to k-1 
*/

#include <iostream>

class KQueues
{
public:
    KQueues(int k, int n);

    bool isFull();

    // To enqueue an item in queue number 'qn' where qn is from 0 to k-1
    void enqueue(int item, int qn);

    // To dequeue an item from queue number 'qn' where qn is from 0 to k-1
    int dequeue(int qn);

    // To check whether queue number 'qn' is empty or not
    bool isEmpty(int qn);

private:
    int* queueData;     // Array of size n to store actual content to be stored in queue
    int* front;         // Array of size k to store indexes of front elements of the queue
    int* rear;          // Array of size k to store indexes of rear elements of the queue 
    int* nextIndex;     // Array of size n to store next entry in all queues
    int nextAvailable;  // store the current free index
};

KQueues::KQueues(int k, int n)
{
    queueData = new int[n];
    front = new int[k];
    rear = new int[k];
    nextIndex = new int[n];

    // Initialize all queues as empty
    for (int i = 0; i < k; i++)
        front[i] = -1;

    // Initialize all spaces as free
    nextAvailable = 0;
    for (int i = 0; i < n - 1; i++)
    {
        nextIndex[i] = i + 1;
    }
    nextIndex[n - 1] = -1;  // -1 is used to indicate end of free list
}

bool KQueues::isFull()
{
    return (nextAvailable == -1);
}

bool KQueues::isEmpty(int qn)
{
    return (front[qn] == -1);
}

void KQueues::enqueue(int item, int qn)
{
    if (isFull())
    {
        std::cout << "Queue Overflow\n";
        return;
    }

    // Store index of first free slot
    int firstFreeSlotIndex = nextAvailable;
    // Update index of free slot to index of next slot in free list
    nextAvailable = nextIndex[firstFreeSlotIndex];

    if (isEmpty(qn))
        front[qn] = firstFreeSlotIndex;
    else
        nextIndex[rear[qn]] = firstFreeSlotIndex;

    nextIndex[firstFreeSlotIndex] = -1;

    // Update next of rear and then rear for queue number 'qn'
    rear[qn] = firstFreeSlotIndex;

    // Put the item in array
    queueData[firstFreeSlotIndex] = item;
}

int KQueues::dequeue(int qn)
{
    if (isEmpty(qn))
    {
        std::cout << "Queue Underflow\n";
        return INT_MIN;
    }

    // Find index of front item in queue number 'qn'
    int frontItemIndex = front[qn];
    // Change front to store next of previous front
    front[qn] = nextIndex[frontItemIndex];

    // Attach the previous front to the beginning of free list
    nextIndex[frontItemIndex] = nextAvailable;
    nextAvailable = frontItemIndex;

    return queueData[frontItemIndex];
}

int main()
{
    // Let us create 3 queue in an array of size 10
    int k = 3, n = 10;
    KQueues kq(k, n);

    // Let us put some items in queue number 2
    kq.enqueue(15, 2);
    kq.enqueue(45, 2);

    // Let us put some items in queue number 1
    kq.enqueue(17, 1);
    kq.enqueue(49, 1);
    kq.enqueue(39, 1);

    // Let us put some items in queue number 0
    kq.enqueue(11, 0);
    kq.enqueue(9, 0);
    kq.enqueue(7, 0);

    std::cout << "Dequeued element from queue 2 is " << kq.dequeue(2) << std::endl;
    std::cout << "Dequeued element from queue 1 is " << kq.dequeue(1) << std::endl;
    std::cout << "Dequeued element from queue 0 is " << kq.dequeue(0) << std::endl;

    return 0;
}
