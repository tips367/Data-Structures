/* Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x 
is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

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

void printNextGreaterElement(int arr[], int n)
{
    std::stack<int> st;
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
            std::cout << st.top() << " --> " << arr[i] << std::endl;
            st.pop();
        }
        /* push next to stack so that we can find next greater for it */
        st.push(arr[i]);
    }
    while (!st.empty())
    {
        std::cout << st.top() << " --> " << -1 << std::endl;
        st.pop();
    }
}

/* Driver program to test above functions */
int main() {
    int arr[] = { 4, 5, 2, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNextGreaterElement(arr, n);
    return 0;
}


