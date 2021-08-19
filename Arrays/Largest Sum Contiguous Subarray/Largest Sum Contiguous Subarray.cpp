/* Find the sum of contiguous subarray within a one-dimensional array of numbers that has the largest sum.
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#include <iostream>
#include <vector>

// Method 1: Brute force.....Time complexity : O(n^3)...Space : O(1)
/*
int maxContiguousSubarraySum(std::vector<int>& nums)
{
    int n = nums.size();
    int maximumSubArraySum = INT_MIN;
    for (int left = 0; left < n; left++)
    {
        for (int right = left; right < n; right++)
        {
            // investigate this window
            int windowSum = 0;
            // Add all items in the window
            for (int k = left; k <= right; k++)
            {
                windowSum += nums[k];
            }
            maximumSubArraySum = std::max(maximumSubArraySum, windowSum);
        }
    }
    return maximumSubArraySum;
} */

// Method 2: Optimized method 1.....Time complexity : O(n^2)...Space : O(1)
/*
int maxContiguousSubarraySum(std::vector<int>& nums)
{
    int n = nums.size();
    int maximumSubArraySum = INT_MIN;
    for (int left = 0; left < n; left++)
    {
        int runningWindowSum = 0;
        for (int right = left; right < n; right++)
        {
            // Add the current element to previous computed value to get the subarray sum
            runningWindowSum += nums[right];
            maximumSubArraySum = std::max(maximumSubArraySum, runningWindowSum);
        }
    }
    return maximumSubArraySum;
} */

// Method 3: Kadane’s Algorithm.....Time complexity : O(n)...Space : O(1)
int maxContiguousSubarraySum(std::vector<int>& nums)
{
    int n = nums.size();
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];

    for (int i = 1; i < n; i++)
    {
        maxEndingHere = std::max(maxEndingHere + nums[i], nums[i]);
        maxSoFar = std::max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int main()
{
    std::vector<int> vec = { -2,1,-3,4,-1,2,1,-5,4 };
    std::cout << "Maximum contiguous sum is " << maxContiguousSubarraySum(vec);
    return 0;
}
