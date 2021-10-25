/* We have an array arr[0 . . . n-1]. We should be able to

1. Find the minimum value from index l to r where 0 <= l <= r <= n-1
2. Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.
*/

#include <iostream>

void updateValueUtil(int* st, int start, int end, int i, int newValue, int idx)
{
    if (i < start || i > end)
        return;

    if (start == end)
    {
        st[idx] = newValue;
        return;
    }
    

    int mid = (start + end) / 2;
    if(i <= mid)
        updateValueUtil(st, start, mid, i, newValue, 2 * idx + 1);
    else
        updateValueUtil(st, mid + 1, end, i, newValue, 2 * idx + 2);

    st[idx] = std::min(st[2 * idx + 1], st[2 * idx + 2]);
}

void updateValue(int arr[], int* st, int n, int i, int newValue)
{
    // Check for erroneous input index
    if (i < 0 || i > n - 1)
    {
        std::cout << "Invalid Input";
        return;
    }

    // Update the value in array
    arr[i] = newValue;

    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n - 1, i, newValue, 0);
}

int getMinimumUtil(int* st, int start, int end, int l, int r, int idx)
{
    // If segment of this node is a part of given range, then return the min of the segment (Total overlap)
    if (l <= start && r >= end)
        return st[idx];

    // If segment of this node is outside the given range (No overlap)
    if (end < l || start > r)
        return INT_MAX;

    // If a part of this segment overlaps with the given range (Partial overlap)
    int mid = (start + end) / 2;
    return std::min(getMinimumUtil(st, start, mid, l, r, 2 * idx + 1), 
                    getMinimumUtil(st, mid + 1, end, l, r, 2 * idx + 2));
}

int getMinimum(int* st, int n, int l, int r)
{
    if (l < 0 || r > n - 1 || l > r)
    {
        std::cout << "Invalid Input";
        return -1;
    }

    return getMinimumUtil(st, 0, n - 1, l, r, 0);
}

int constructSTUtil(int arr[], int* st, int start, int end, int idx)
{
    // If there is one element in array, store it in current node of segment tree and return
    if (start == end)
    {
        st[idx] = arr[start];
        return arr[start];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store minimum of two values in this node
    int mid = (start + end) / 2;
    st[idx] = std::min(constructSTUtil(arr, st, start, mid, 2 * idx + 1), 
                       constructSTUtil(arr, st, mid + 1, end, 2 * idx + 2));
    return st[idx];
}

int* constructST(int arr[], int n)
{
    // Allocate memory for the segment tree

    //Height of segment tree
    int x = (int)(ceil(log2(n)));

    //Maximum size of segment tree
    int maxSize = 2 * (int)pow(2, x) - 1;

    // Allocate memory
    int* st = new int[maxSize];

    // Fill the allocated memory st
    constructSTUtil(arr, st, 0, n - 1, 0);

    // Return the constructed segment tree
    return st;
}

int main()
{
    int arr[] = { 1, 3, 2, 7, 9, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Build segment tree from given array
    int* st = constructST(arr, n);

    // Print minimum value in array from index 1 to 3
    std::cout << "Minimum of values in range = " << getMinimum(st, n, 1, 3) << std::endl;

    // Update: set arr[1] = -10 and update corresponding segment tree nodes
    updateValue(arr, st, n, 1, -10);

    // Find minimum value after the value is updated
    std::cout << "Minimum of values in range = " << getMinimum(st, n, 1, 3) << std::endl;
    return 0;
}