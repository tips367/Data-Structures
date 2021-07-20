// Heap Sort

#include <iostream>

void maxHeapify(int arr[], int n, int i)
{
    int leftChildIndex = 2 * i + 1;
    int rightChildIndex = 2 * i + 2;
    int max = i;

    if (leftChildIndex < n && arr[leftChildIndex] > arr[i])
        max = leftChildIndex;
    if (rightChildIndex < n && arr[rightChildIndex] > arr[max])
        max = rightChildIndex;

    // If largest is not root
    if (max != i)
    {
        std::swap(arr[i], arr[max]);

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, max);
    }
}

void heapSort(int arr[], int n)
{
    // Build max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) 
    {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array is \n";
    printArray(arr, n);

    heapSort(arr, n);

    std::cout << "Sorted array is \n";
    printArray(arr, n);
}

