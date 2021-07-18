// Binary Heap Operations

#include <iostream>

class MinHeap
{
public:
    // Constructor
    MinHeap(int capacity);

    // to heapify a subtree with the root at given index
    void MinHeapify(int i);

    int parent(int i) 
    { 
        return (i - 1) / 2;
    }

    // to get index of left child of node at index i
    int left(int i) 
    { 
        return (2 * i + 1); 
    }

    // to get index of right child of node at index i
    int right(int i) 
    { 
        return (2 * i + 2); 
    }

    // to extract the root which is the minimum element
    int extractMin();

    // Decreases key value of key at index i to newValue
    void decreaseKey(int i, int newValue);

    // Returns the minimum key (key at root) from min heap
    int getMin() 
    { 
        return heapArray[0]; 
    }

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key
    void insertKey(int key);

private:
    int* heapArray;
    int heapCapacity;
    int heapSize;
};

MinHeap::MinHeap(int capacity)
{
    heapSize = 0;
    heapCapacity = capacity;
    heapArray = new int[capacity];
}

// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int leftChildIndex = left(i);
    int rightChildIndex = right(i);
    int min = i;

    if (leftChildIndex < heapSize && heapArray[leftChildIndex] < heapArray[i])
        min = leftChildIndex;
    if (rightChildIndex < heapSize && heapArray[rightChildIndex] < heapArray[min])
        min = rightChildIndex;
    if (min != i)
    {
        std::swap(heapArray[i], heapArray[min]);
        MinHeapify(min);
    }
}

int MinHeap::extractMin()
{
    if (heapSize <= 0)
        return INT_MAX;

    if (heapSize == 1)
    {
        heapSize--;
        return heapArray[0];
    }

    // Store the minimum value, and remove it from heap
    int root = heapArray[0];
    heapArray[0] = heapArray[heapSize - 1];
    heapSize--;
    MinHeapify(0);

    return root;
}

// It is assumed that newValue is smaller than heapArray[i].
void MinHeap::decreaseKey(int i, int newValue)
{
    heapArray[i] = newValue;
    // Fix the min heap property if it is violated
    while (i != 0 && heapArray[parent(i)] > heapArray[i])
    {
        std::swap(heapArray[i], heapArray[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::insertKey(int key)
{
    if (heapSize == heapCapacity)
    {
        std::cout << "\nOverflow: Could not insert Key\n";
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    heapArray[i] = key;

    // Fix the min heap property if it is violated
    while (i != 0 && heapArray[parent(i)] > heapArray[i])
    {
        std::swap(heapArray[i], heapArray[parent(i)]);
        i = parent(i);
    }
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    std::cout << h.extractMin() << " ";
    std::cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    std::cout << h.getMin();
    return 0;
}


