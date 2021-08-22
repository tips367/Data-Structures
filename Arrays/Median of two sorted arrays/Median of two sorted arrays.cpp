/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include <iostream>
#include <vector>
#include <algorithm>

/*
// 1. Linear and Simple approach (Merge two sorted arrays and then calculate median).
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::vector<int> mergedArray;
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] <= nums2[j])
        {
            mergedArray.push_back(nums1[i]);
            i++;
        }
        else
        {
            mergedArray.push_back(nums2[j]);
            j++;
        }
    }
    while (i < n1)
    {
        mergedArray.push_back(nums1[i]);
        i++;
    }
    while (j < n2)
    {
        mergedArray.push_back(nums2[j]);
        j++;
    }
    // If size of merged array is odd
    if ((n1 + n2) & 1)
    {
        return mergedArray[(n1 + n2) / 2];
    }
    else
    {
        return (mergedArray[(n1 + n2) / 2] + mergedArray[(n1 + n2) / 2 - 1]) / 2.0;
    }
}
*/

/*
// 2. Without actually merging the array but keeping track of last element read till we reach the median.
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0, j = 0;
    int m1 = -1, m2 = -1;
    for (int count = 0; count <= (n1 + n2) / 2; count++)
    {
        m2 = m1;
        if (i != n1 && j != n2)
        {
            m1 = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        }
        else if (i < n1)
        {
            m1 = nums1[i++];
        }
        else
        {
            m1 = nums2[j++];
        }
    }
    if ((n1 + n2) & 1)
    {
        return m1;
    }
    else
    {
        return (m1 + m2) / 2.0;
    }
}
*/

// 3. Using Binary search (Time complexity: O(log(min(n,m)))
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    int x = nums1.size();
    int y = nums2.size();
    // If nums1 length is greater than nums2, switch them so that nums1 is smaller than nums2.
    if (x > y)
        return findMedianSortedArrays(nums2, nums1);
    int low = 0;
    int high = x;
    while (low <= high)
    {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
        //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            // We have partitioned array at correct place.
            // Now get max of left elements and min of right elements to get the median in case of even length combined array size
            // or get max of left for odd length combined array size.
            if ((x + y) & 1)
            {
                return std::max(maxLeftX, maxLeftY);
            }
            else
            {
                return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            }
        }
        else if (maxLeftX > minRightY)
        {
            //we are too far on right side for partitionX. Go on left side.
            high = partitionX - 1;
        }
        else
        {
            //we are too far on left side for partitionX. Go on right side.
            low = partitionX + 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> nums1{ 1,2,3,6  };
    std::vector<int> nums2{ 4,6,8,10 };
    std::cout << "The median is " << findMedianSortedArrays(nums1, nums2);
    return 0;
}
