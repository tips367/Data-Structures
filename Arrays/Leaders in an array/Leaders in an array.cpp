/* Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the 
elements to its right side. And the rightmost element is always a leader.

For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.
*/

#include <iostream>

// Method 1: Brute force...Time complexity : O(n^2)
/*
void printLeaders(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
                break;
        }
        if (j == n) 
            std::cout << arr[i] << " ";
    }
} */

// Method 2: Scan from right...Time complexity : O(n)
void printLeaders(int arr[], int n)
{
    int currentMax = INT_MIN;

    for (int i = n-1; i >= 0; i--)
    {
        if (currentMax < arr[i])
        {
            currentMax = arr[i];
            std::cout << currentMax << " ";
        }
    }
}

int main()
{
    int arr[] = { 16, 17, 4, 3, 5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printLeaders(arr, n);
    return 0;
}

