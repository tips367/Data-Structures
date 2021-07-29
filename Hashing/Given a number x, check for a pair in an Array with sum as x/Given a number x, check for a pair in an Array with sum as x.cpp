/* Write a program that, given an array A[] of n numbers and another number x, determines whether or not there exist 
two elements in A whose sum is exactly x. 

Examples: 

Input: arr[] = {0, -1, 2, -3, 1}
        sum = -2
Output: -3, 1
If we calculate the sum of the output,
1 + (-3) = -2

Input: arr[] = {1, -2, 1, 0, 5}
       sum = 0
Output: -1
No valid pair exists.
*/

#include <iostream>
#include <unordered_map>

// Method 1 : Brute force...Time complexity : O(n^2)
/*
void printPairs(int arr[], int arr_size, int sum)
{
    for (int i = 0; i < arr_size-1; i++)
    {
        for (int j = i + 1; j < arr_size; j++)
        {
            if ((arr[i] + arr[j]) == sum)
                std::cout << "Pair with given sum " << sum << " is (" << arr[i] << "," << arr[j] << ")" << std::endl;
        }
    }
} */

// Method 2 : Hashing...Time complexity : O(n)
void printPairs(int arr[], int arr_size, int sum)
{
    //Key is the number and value is its index in the array.
    std::unordered_map<int, int> hash;

    for (int i = 0; i < arr_size; i++)
    {
        int numberToFind = sum - arr[i];
        if (hash.find(numberToFind) != hash.end())
        {
            std::cout << "Pair with given sum " << sum << " is (" << arr[i] << "," << numberToFind << ")" << std::endl;
        }
        // Number is not found so put it in the map
        hash[arr[i]] = i;
    }
}

int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int n = 16;
    int arr_size = sizeof(A) / sizeof(A[0]);

    printPairs(A, arr_size, n);

    return 0;
}

