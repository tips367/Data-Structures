/* Write a program that, given an array A[] of n numbers and another number x, determines whether or not 
there exist two elements in A[] whose sum is exactly x. 

Examples:

Input: arr[] = {0, -1, 2, -3, 1}
        sum = -2
Output: -3, 1
If we calculate the sum of the output,
1 + (-3) = -2

Input: arr[] = {1, -2, 1, 0, 5}
       sum = 0
Output: -1
No valid pair exists
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

//  1. Brute Force...Time complexity : O(n^2)
/*
std::vector<int> twoSum(std::vector<int>& nums, int target) 
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j]) == target)
                return std::vector<int>{i, j};
        }
    }
    return std::vector<int>{-1};
} */

//  2. Sorting and two-pointers technique...Time complexity : O(nlogn)
/*
std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left < right) 
    {
        if (nums[left] + nums[right] == target)
            return std::vector<int>{left, right};
        else if (nums[left] + nums[right] < target)
            left++;
        else
            right--;
    }
    return {-1};
} */

// 3. Using two-pass hash table...Time complexity: O(n)
/*
std::vector<int> twoSum(std::vector<int>& nums, int target) 
{
    //Key is the number and value is its index in the vector.
    std::unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int numberToFind = target - nums[i];
        if (hash.find(numberToFind) != hash.end() && hash[numberToFind] != i)
        {
            return { hash[numberToFind], i };
        }
    }
    return {-1};
} */

// 4. Using one-pass hash table...Time complexity: O(n)
std::vector<int> twoSum(std::vector<int>& nums, int target) 
{
    //Key is the number and value is its index in the vector.
    std::unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        int numberToFind = target - nums[i];
        if (hash.find(numberToFind) != hash.end())
        {
            return { hash[numberToFind], i };
        }
        // Number is not found so put it in the map
        hash[nums[i]] = i;
    }
    return { -1 };
}

int main()
{
    std::vector<int> nums = { 1, 4, 45, 6, 10, -8 };
    int target = 16;

    std::vector<int> result = twoSum(nums, target);

    for (int a : result)
        if (a != -1)
            std::cout << nums[a] << " ";
        else
            std::cout << a;

    return 0;
}


