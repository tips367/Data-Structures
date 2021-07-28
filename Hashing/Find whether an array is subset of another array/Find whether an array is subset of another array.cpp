/* Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. 
Both the arrays are not in sorted order. It may be assumed that elements in both array are distinct.

Examples:

Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3}
Output: arr2[] is not a subset of arr1[]
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>

// Method 1: Using sorting and merging...Time complexity : O(mlogm + nlogn)
/*
bool isSubset(int arr1[], int arr2[], int sizeArr1, int sizeArr2)
{
    int i = 0, j = 0;

    if (sizeArr1 < sizeArr2)
        return 0;

    // Sort both the arrays
    std::sort(arr1, arr1 + sizeArr1);
    std::sort(arr2, arr2 + sizeArr2);

    // Iterate till they do not exceed their sizes
    while (i < sizeArr2 && j < sizeArr1)
    {
        // If the element is smaller than Move aheaad in the first array
        if (arr1[j] < arr2[i])
            j++;
        // If both are equal, then move both of them forward
        else if (arr1[j] == arr2[i])
        {
            j++;
            i++;
        }

        // If we donot have a element smaller or equal to the second array then break
        else if (arr1[j] > arr2[i])
            return 0;
    }

    return (i < sizeArr2) ? false : true;
} */

// Method 2: Using Hashing
/*
bool isSubset(int arr1[], int arr2[], int sizeArr1, int sizeArr2)
{
    // Using set for hashing
    std::set<int> hashset;

    for (int i = 0; i < sizeArr1; i++)
    {
        hashset.insert(arr1[i]);
    }

    // loop to check if all elements of arr2 also lies in arr1
    for (int i = 0; i < sizeArr2; i++) 
    {
        if (hashset.find(arr2[i]) == hashset.end())
            return false;
    }
    return true;
} */

// Method 3: Using unordered set...Time complexity : O(m+n)
/*
bool isSubset(int arr1[], int arr2[], int sizeArr1, int sizeArr2)
{
    std::unordered_set<int> s;

    for (int i = 0; i < sizeArr1; i++)
    {
        s.insert(arr1[i]);
    }

    int setSize = s.size();
    for (int i = 0; i < sizeArr2; i++)
    {
        s.insert(arr2[i]);
    }

    if (s.size() == setSize)
        return true;
    else
        return false;
} */

// Method 4: Using frequency table...Time complexity : O(m+n)
bool isSubset(int arr1[], int arr2[], int sizeArr1, int sizeArr2)
{
    std::map<int, int> frequencyMap;

    // Increase the frequency of each element in the frequency table.
    for (int i = 0; i < sizeArr1; i++)
    {
        frequencyMap[arr1[i]]++;
    }
    // Decrease the frequency if the element was found in the frequency table with the frequency more than 0.
    // else return 0 and if loop is completed return 1.
    for (int i = 0; i < sizeArr2; i++)
    {
        if (frequencyMap[arr2[i]] > 0)
            frequencyMap[arr2[i]]--;
        else
            return false;
    }
    return true;
}

int main()
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };

    int sizeArr1 = sizeof(arr1) / sizeof(arr1[0]);
    int sizeArr2 = sizeof(arr2) / sizeof(arr2[0]);

    if (isSubset(arr1, arr2, sizeArr1, sizeArr2))
        std::cout << "Array 2 is a subset of Array 1";
    else
        std::cout << "Array 2 is not a subset of Array 1";

    return 0;
}
