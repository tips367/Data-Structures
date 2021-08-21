/* An element in a sorted array can be found in O(log n) time via binary search. But suppose we rotate an ascending 
order sorted array at some pivot unknown to you beforehand. So for instance, 1 2 3 4 5 might become 3 4 5 1 2. 
Devise a way to find an element in the rotated array in O(log n) time.

Example:

Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
         key = 3
Output : Found at index 8

Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
         key = 30
Output : Not found
*/

#include <iostream>
#include <vector>

// Method 1: Two pass binary search
/*
int findPivot(std::vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid < right && nums[mid]>nums[mid + 1])
            return mid;
        else if (mid > left && nums[mid] < nums[mid - 1])
            return mid - 1;
        else if (nums[left] < nums[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binarySearch(std::vector<int>& nums, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int pivotedBinarySearch(std::vector<int>& nums, int target)
{
    int n = nums.size();
    int pivot = findPivot(nums);

    int left = 0, right = n - 1;
    if (pivot == -1)
        return binarySearch(nums, left, right, target);

    if (nums[pivot] == target)
        return pivot;

    if (nums[0] <= target)
        right = pivot - 1;
    else
        left = pivot + 1;

    return binarySearch(nums, left, right, target);
} */

// Method 2: Efficient one pass binary search
int pivotedBinarySearch(std::vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target <= nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (target >= nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> nums = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int target = 3;

    std::cout << "Index of the element is : " << pivotedBinarySearch(nums, target);
}


