/* Write a function which takes an array and prints the majority element (if it exists), otherwise prints 
“No Majority Element”. A majority element in an array A[] of size n is an element that appears more than n/2 
times (and hence there is at most one such element). 

Examples : 

Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
Output : 4
Explanation: The frequency of 4 is 5 which is greater than the half of the size of the array size. 

Input : {3, 3, 4, 2, 4, 4, 2, 4}
Output : No Majority Element
Explanation: There is no element whose frequency is greater than the half of the size of the array size.
*/

#include <iostream>
#include <unordered_map>

// 1. Brute force...Time complexity : O(n^2), Space : O(1)
/*
void findMajority(int arr[], int n)
{
    int maxCount = 0;
    int index = -1; 
    for (int i = 0; i < n; i++) 
    {
        int count = 0;
        for (int j = 0; j < n; j++) 
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxCount) 
        {
            maxCount = count;
            index = i;
        }
    }

    if (maxCount > n / 2)
        std::cout << arr[index] << std::endl;
    else
        std::cout << "No Majority Element" << std::endl;
} */

// 2. Using Hashmap...Time complexity : O(n), Space: O(n)
/*
void findMajority(int arr[], int size)
{
    std::unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
        map[arr[i]]++;

    bool found = false;
    for (auto i : map)
    {
        if (i.second > size / 2)
        {
            found = true;
            std::cout << i.first << std::endl;
            break;
        }
    }

    if (found == false)
        std::cout << "No Majority element" << std::endl;
} */


// 3. Using Moore’s Voting Algorithm...Time complexity : O(n), Space: O(1)
int findCandidate(int arr[], int n)
{
    int majIndex = 0, count = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[majIndex])
            count++;
        else
            count--;

        if (count == 0)
        {
            majIndex = i;
            count = 1;
        }
    }
    return arr[majIndex];
}

void findMajority(int arr[], int n)
{
    int candidate = findCandidate(arr, n);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
            count++;
    }
    
    if (count > n / 2)
        std::cout << candidate << std::endl;
    else
        std::cout << "No Majority Element" << std::endl;
}

int main()
{
    int arr[] = { 1, 1, 2, 1, 3, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    findMajority(arr, n);

    return 0;
}
