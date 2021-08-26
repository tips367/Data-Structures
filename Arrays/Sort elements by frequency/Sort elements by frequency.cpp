/* Print the elements of an array in the decreasing frequency if 2 numbers have same frequency then print the one 
which came first. 

Examples:  

Input:  arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6}

Input: arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8}
Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999}
*/

#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b)
{
    if (a.second.second != b.second.second)
        return a.second.second > b.second.second;
    else
        return a.second.first < b.second.first;
}

void sortByFrequency(int arr[], int n)
{
    // map will contain <element, <first index, frequency>>
    unordered_map<int, pair<int, int> > hash;

    // store the count of all the elements and their first index in the hashmap
    for (int i = 0; i < n; i++)
    {
        if (hash.find(arr[i]) != hash.end())
            hash[arr[i]].second++;
        else
            hash[arr[i]] = make_pair(i, 1);
    }

    // Vector to store the Final Sortted order
    vector<pair<int, pair<int, int> > > b;
    for (auto it = hash.begin(); it != hash.end(); ++it)
        b.push_back(make_pair(it->first, it->second));

    sort(b.begin(), b.end(), compare);

    for (int i = 0; i < b.size(); i++) 
    {
        int freq = b[i].second.second;
        while (freq--)
            cout << b[i].first << " ";
    }
}

int main()
{
    int arr[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sortByFrequency(arr, n);

    return 0;
}
