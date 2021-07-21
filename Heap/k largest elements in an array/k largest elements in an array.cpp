/* Write an efficient program for printing k largest elements in an array. Elements in array can be in any order.
For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the largest 3 elements 
i.e., k = 3 then your program should print 50, 30, and 23.
*/

#include <iostream>
#include <math.h>

// Method 1: Using min-heap 
/*
class MinHeap 
{
public:
    MinHeap(int input[], int size);
    void heapify(int i);
    void buildHeap();

private:
    int size;
    int* arr;
};

MinHeap::MinHeap(int input[], int size)
{
    this->size = size;
    this->arr = input;
    // Building the Min Heap
    buildHeap();
}

void MinHeap::heapify(int i)
{
    int leftChildIndex = 2 * i + 1;;
    int rightChildIndex = 2 * i + 2;;
    int min = i;

    if (leftChildIndex < size && arr[leftChildIndex] < arr[i])
        min = leftChildIndex;
    if (rightChildIndex < size && arr[rightChildIndex] < arr[min])
        min = rightChildIndex;
    if (min != i)
    {
        std::swap(arr[i], arr[min]);
        heapify(min);
    }
}

// Build Min Heap
void MinHeap::buildHeap()
{
    // Calling Heapify for all non leaf nodes
    for (int i = size / 2 - 1; i >= 0; i--) 
    {
        heapify(i);
    }
}

void kLargestElements(int arr[], int size, int k) 
{
    // Creating Min Heap for given array with first k elements
    MinHeap* minHeap = new MinHeap(arr, k);

    // Loop For each element in array after the kth element
    for (int i = k; i < size; i++) 
    {

        // if current element is smaller than minimum element, do nothing and continue to next element
        if (arr[0] > arr[i])
            continue;

        // Otherwise Change minimum element to current element, and call heapify to restore the heap property
        else 
        {
            arr[0] = arr[i];
            minHeap->heapify(0);
        }
    }

    // Now min heap contains k maximum elements, Iterate and print
    for (int i = 0; i < k; i++) 
    {
        std::cout << arr[i] << " ";
    }
} */

// Method 2: Using Quick Sort partitioning algorithm
int findPivot(int a[], int start, int end)
{
    // Selecting the pivot element
    int pivot = a[end];

    // Initially partition-index will be at starting
    int pIndex = start;

    for (int i = start; i < end; i++) 
    {
        // If an element is lesser than pivot, swap it.
        if (a[i] <= pivot) 
        {
            std::swap(a[i], a[pIndex]);
            // Incrementing pIndex for further swapping.
            pIndex++;
        }
    }

    std::swap(a[pIndex], a[end]);
    return pIndex;
}

void kLargestElementsUtil(int a[], int low, int high, int size, int k)
{
    if (low == high)
        return;
    else 
    {
        int pivotIndex = findPivot(a, low, high);

        if (k == pivotIndex) 
        {
            std::cout << k << " largest elements are : ";
            for (int i = (size - pivotIndex); i < size; i++)
                std::cout << a[i] << " ";
        }
        else if (k < pivotIndex)
        {
            kLargestElementsUtil(a, low, pivotIndex - 1, size, k);
        }
        else if (k > pivotIndex)
        {
            kLargestElementsUtil(a, pivotIndex + 1, high, size, k);
        }
    }
}

void kLargestElements(int arr[], int size, int k)
{
    int low = 0;
    int high = size - 1;
    kLargestElementsUtil(arr, low, high, size, k);
}

int main()
{
    int arr[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    kLargestElements(arr, size, k);

    return 0;
}



