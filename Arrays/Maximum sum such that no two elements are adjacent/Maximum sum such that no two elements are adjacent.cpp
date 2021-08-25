/* Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 
numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 
3 2 5 10 7 should return 15 (sum of 3, 5 and 7).

Examples : 

Input : arr[] = {5, 5, 10, 100, 10, 5}
Output : 110

Input : arr[] = {1, 2, 3}
Output : 4

Input : arr[] = {1, 20, 3}
Output : 20
*/

#include <iostream>
#include <vector>

// Method 1: Time complexity : O(n), Space: O(n)
/*
int findMaxSum(std::vector<int>& nums)
{
    int n = nums.size();
    int* dp = new int[n];

    dp[0] = nums[0];
    dp[1] = std::max(nums[1], dp[0]);

    for (int i = 2; i < n; i++)
        dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);

    return dp[n - 1];
} */

// Method 2: Time complexity : O(n), Space: O(1)
int findMaxSum(std::vector<int>& nums)
{
    int include = nums[0];
    int exclude = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        // current max including i
        int newInclude = nums[i] + exclude;
        // current max excluding i
        int newExclude = std::max(include, exclude);
     
        exclude = newExclude;
        include = newInclude;
    }
    return std::max(include, exclude);
}


int main()
{
    std::vector<int> nums = { 5, 5, 10, 100, 10, 5 };
    std::cout << findMaxSum(nums);
}
