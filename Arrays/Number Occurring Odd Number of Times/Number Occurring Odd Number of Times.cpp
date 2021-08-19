/* Given an array of positive integers. All numbers occur an even number of times except one number which occurs 
an odd number of times. Find the number in O(n) time & constant space.

Examples : 

Input : arr = {1, 2, 3, 2, 3, 1, 3}
Output : 3

Input : arr = {5, 7, 2, 7, 5, 2, 5}
Output : 5
*/

#include <iostream>

int getOddOccurrence(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
        result = result ^ arr[i];

    return result;
}

int main()
{
    int ar[] = { 2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2 };
    int n = sizeof(ar) / sizeof(ar[0]);

    std::cout << getOddOccurrence(ar, n);

    return 0;
}

