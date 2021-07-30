/* Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array. 
Write a function that returns true if array contains duplicates within k distance.

Examples: 

Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
Output: false
All duplicates are more than k distance away.

Input: k = 3, arr[] = {1, 2, 3, 1, 4, 5}
Output: true
1 is repeated at distance 3.
*/

#include <iostream>
#include <unordered_set>

bool checkDuplicatesWithinKDistance(int arr[], int n, int k)
{
    std::unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i]) != s.end())
            return true;
        
        s.insert(arr[i]);
        if (i >= k)
            s.erase(arr[i - k]);     
    }
    return false;
}

int main()
{
    int arr[] = { 10, 5, 3, 4, 3, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    if (checkDuplicatesWithinKDistance(arr, n, 3))
        std::cout << "Yes";
    else
        std::cout << "No";
}

