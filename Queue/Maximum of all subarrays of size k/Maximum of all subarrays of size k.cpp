/* Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.

Examples : 

Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3
Output: 3 3 4 5 5 5 6

Explanation:
Maximum of 1, 2, 3 is 3
Maximum of 2, 3, 1 is 3
Maximum of 3, 1, 4 is 4
Maximum of 1, 4, 5 is 5
Maximum of 4, 5, 2 is 5
Maximum of 5, 2, 3 is 5
Maximum of 2, 3, 6 is 6
*/

#include <iostream>
#include <deque>

// Method 1: Simple.....................Time complexity : O(N*K)..Space : O(1)
/*
void printKMax(int arr[], int n, int k)
{
    for (int i = 0; i <= n - k; i++)
    {
        int max = arr[i];
        for (int j = 1; j < k; j++)
        {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        std::cout << max << " ";
    }
} */

// Method 2: Use Deque................   Time complexity : O(n)..Space : O(k)
void printKMax(int arr[], int n, int k)
{
    // Double Ended Queue, dq that will store indexes of array elements
    // The dq will store indexes of useful elements in every window and it will
    // maintain decreasing order of values from front to rear in dq
    std::deque<int> dq(k);

    // Process first k elements i.e first window of size k
    for (int i = 0; i < k; i++)
    {
        // Remove useless element i.e Remove all elements smaller than the currently being added element
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            // Remove from rear end
            dq.pop_back();
        }
        // Add new element at rear end
        dq.push_back(i);
    }
    // Process rest of the elements
    for (int i = k; i < n; i++)
    {
        // The element at the front of the dq is the largest element of previous window
        std::cout << arr[dq.front()] << " ";
        // Remove elements which are out of current window
        while (!dq.empty() && dq.front() <= i - k)
        {
            // Remove from front of dq
            dq.pop_front();
        }
        // Remove useless element i.e Remove all elements smaller than the currently being added element
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            // Remove from rear end
            dq.pop_back();
        }
        // Add new element at rear end
        dq.push_back(i);
    }
    // Maximum element of last window
    std::cout << arr[dq.front()];
}

// Driver code
int main()
{
    int arr[] = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}

