/* Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time.

Examples:
Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
        k = 3
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}
*/

#include <iostream>
#include <queue>

void sortKSortedArray(int arr[], int n, int k)
{
    // Insert first k+1 items in a priority queue (or min heap) 
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(arr, arr + k + 1);
    int index = 0;
    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while (pq.empty() == false)
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Driver program to test above functions 
int main()
{
    int k = 3;
    int arr[] = { 2, 6, 3, 12, 56, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Given k sorted array is :" << std::endl;
    printArray(arr, n);

    sortKSortedArray(arr, n, k);

    std::cout << "Following is sorted array :" << std::endl;
    printArray(arr, n);

    return 0;
}

