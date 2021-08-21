/* You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates 
in the list. One of the integers is missing in the list. Write an efficient code to find the missing integer.

Example: 

Input: arr[] = {1, 2, 4, 6, 3, 7, 8}
Output: 5
Explanation: The missing number from 1 to 8 is 5

Input: arr[] = {1, 2, 3, 5}
Output: 4
Explanation: The missing number from 1 to 5 is 4
*/

#include <iostream>

// Method 1: Using summation formula
/*
int getMissingNumber(int arr[], int n)
{
    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++)
        total -= arr[i];
    return total;
} */

// Method 2: Avoiding overflow
/*
int getMissingNumber(int arr[], int n)
{
    int  total = 1;
    for (int i = 2; i <= (n + 1); i++)
    {
        total += i;
        total -= arr[i - 2];
    }
    return total;
} */

// Method 3: Using XOR
int getMissingNumber(int arr[], int n)
{
    // For xor of all the elements in array
    int x1 = arr[0];

    // For xor of all the elements from 1 to n+1
    int x2 = 1;

    for (int i = 1; i < n; i++)
        x1 = x1 ^ arr[i];

    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;

    return (x1 ^ x2);
}

int main()
{
    int arr[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int missingNum = getMissingNumber(arr, n);
    std::cout << missingNum;
}


