/* Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x
is the first greater element on the right side of x in array. Elements for which no greater element exist,
consider next greater element as -1. The next greater elements should be printed in same order as input array.

Example:
for the input array [4, 5, 2, 25]
Element         NGE
   4      -->    5
   5      -->    25
   2      -->    25
   25     -->    -1
*/

#include <iostream>
#include <stack>
#include <unordered_map>

// Method 1. Using unordered map
/*
void printNextGreaterElement(int arr[], int n)
{
    std::stack<int> st;
    std::unordered_map<int, int> map;
    // push first element to stack
    st.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (st.empty())
        {
            st.push(arr[i]);
            continue;
        }
        while (st.empty() == false && st.top() < arr[i])
        {
            map[st.top()] = arr[i];
            st.pop();
        }
        // push next to stack so that we can find next greater for it
        st.push(arr[i]);
    }
    // After iterating over the loop, the remaining elements in stack do not have the next greater element, so store -1 for them 
    while (!st.empty())
    {
        map[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " --> " << map[arr[i]] << std::endl;
} */

// Method 2. Traversing from right to left
void printNextGreaterElement(int arr[], int n)
{
    std::stack<int> st;
    int* solnArray = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        // We will pop till we get the greater element on top or stack gets empty
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        // if stack gets empty means there is no element on right which is greater than the current element.
        // if not empty then the next greater element is on top of stack
        if (st.empty())
        {
            solnArray[i] = -1;
        }
        else
        {
            solnArray[i] = st.top();
        }
        st.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ---> " << solnArray[i] << std::endl;
    }
}


/* Driver program to test above functions */
int main() {
    int arr[] = { 4, 5, 2, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNextGreaterElement(arr, n);
    return 0;
}


