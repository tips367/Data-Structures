// RotateArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void reverseArray(int arr[], int left, int right)
{
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

void rotateArray(int arr[], int n, int k)
{
    k = k % n;
    reverseArray(arr, n - k, n - 1);
    reverseArray(arr, 0, n-k-1);
    reverseArray(arr, 0, n-1);
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10,20,30};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int k = 100;

    printf("Given array is \n");
    printArray(arr, arr_size);

    rotateArray(arr, arr_size, k);

    printf("\nRotated array is \n");
    printArray(arr, arr_size);
    return 0;
}
