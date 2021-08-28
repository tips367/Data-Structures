/* Given an array of integers where each element represents the max number of steps that can be made forward from that element.
Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element).
If an element is 0, they cannot move through that element.

Examples:

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 -> 9)
Jump from 1st element to 2nd element as there is only 1 step, now there are three options 5, 8 or 9.
If 8 or 9 is chosen then the end node 9 can be reached. So 3 jumps are made.

Input:  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
Output: 10
In every step a jump is needed so the count of jumps is 10.
*/

#include <iostream>
#include <algorithm>

// Method 1. Recursion... Time complexity : Exponential  Space : 0(1) No external space used apart from internal stack space
/*
int minJumps(int arr[], int n, int currentPos)
{
    // Base condition
    if (currentPos >= n - 1)
        return 0;
    int minJump = INT_MAX;
    int maxSteps = arr[currentPos];
    while (maxSteps > 0)
    {
        minJump = std::min(minJump, 1 + minJumps(arr, n, currentPos + maxSteps));
        maxSteps--;
    }
    return minJump;
} */

// Method 2. Dynamic programming....Time complexity : O(n^2)  Space : 0(n) 
/*
int minJumps(int arr[], int n)
{
    int* minJumps = new int[n];
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
    minJumps[0] = 0;
    for (int i = 1; i < n; i++)
    {
        minJumps[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            // minJumps[j] != INT_MAX to ensure minJumps[j] + 1 does not overflow
            if (i <= j + arr[j] && minJumps[j] != INT_MAX && minJumps[i] > minJumps[j] + 1)
            {
                minJumps[i] = minJumps[j] + 1;
            }
        }
    }
    return minJumps[n - 1];
} */

// Method 3. Greedy....Time complexity : O(n)  Space : 0(1) 
int minJumps(int arr[], int n)
{
    if (n <= 1)
        return 0;
    int ladder = arr[0];
    int stairs = arr[0];
    int jump = 1;
    for (int i = 1; i < n; ++i)
    {
        if (i == n - 1)
            return jump;
        if (i + arr[i] > ladder)
            ladder = i + arr[i];
        --stairs;
        if (stairs == 0)
        {
            ++jump;
            stairs = ladder - i;
        }
    }
    return jump;
}

// Driver Code
int main()
{
    int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // std::cout << "Minimum number of jumps to reach the end is " << minJumps(arr, n, 0);      // for Method 1 (recursive)
    std::cout << "Minimum number of jumps to reach the end is " << minJumps(arr, n);
    return 0;
}