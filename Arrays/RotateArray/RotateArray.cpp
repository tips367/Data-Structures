/* Write a function leftRotate(arr[], n, k) that rotates arr[] of size n by k elements to the left.

Example:
Array : 1,2,3,4,5,6,7
Rotation of above array by 2 will make array
3,4,5,6,7,1,2

*/

#include <iostream>

// Method 1: Using temp array...Time : O(n), Space : O(k)
/*
void leftRotate(int arr[], int n, int k)
{
    int* temp = new int[k];
    for (int i = 0; i < k; i++)
        temp[i] = arr[i];

    for (int i = k; i < n; i++)
        arr[i - k] = arr[i];

    int j = 0;
    for (int i = n - k; i < n; i++)
        arr[i] = temp[j++];
} */

// Method 2: Rotate one by one...Time : O(n * k), Space : O(1)
/*
void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    arr[n-1] = temp;
}

void leftRotate(int arr[], int n, int k)
{
    for (int i = 0; i < k; i++)
        leftRotateByOne(arr, n);
}*/

// Method 3: Juggling Algorithm...Time : O(n), Space : O(1)
int getGcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return getGcd(b, a % b);
}

void leftRotate(int arr[], int n, int k)
{
    k = k % n;  // To handle if k>=n
    int gcd = getGcd(n, k);
    for (int i = 0; i < gcd; i++)
    {
        int temp = arr[i];
        int j = i;
        while (1)
        {
            int d = (j + k) % n;
            if (d == i)
                break;
            arr[j] = arr[d];
            j = d;
        }
        arr[j] = temp;
    }
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Given array is \n");
    printArray(arr, arr_size);

    leftRotate(arr, arr_size, k);

    printf("\nRotated array is \n");
    printArray(arr, arr_size);
    return 0;
}
