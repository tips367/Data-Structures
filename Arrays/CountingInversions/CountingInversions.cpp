/* Inversion Count for an array indicates – how far(or close) the array is from being sorted.If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Example :
The sequence 2, 4, 1, 3, 5 has three inversions(2, 1), (4, 1), (4, 3).
*/

#include <iostream>

// 1. Simple method : For each element, count number of elements which are on right side of it and are smaller than it.

/*
int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}

int main()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Number of inversions are "
        << getInvCount(arr, n);
    return 0;
}
*/

// 2. Using merge sort

int merge(int arr[], int l, int m, int r)
{
    int inv_count = 0;
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            inv_count = inv_count + (n1 - i);
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return inv_count;
}

int mergeSort(int arr[],  int l,  int r)
{
    int inv_count = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        inv_count += mergeSort(arr, l, m);
        inv_count += mergeSort(arr, m + 1, r);
        inv_count += merge(arr, l, m, r);
    }
    return inv_count;
}

int main()
{
    //int arr[] = { 1, 20, 6, 4, 5 };
    int arr[] = { 1, 4, 3, 2, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Number of inversions are "
        << mergeSort(arr, 0,n-1);
    return 0;
}