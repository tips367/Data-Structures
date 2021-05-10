/* The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to 
calculate span of stock’s price for all n days.

The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
for which the price of the stock on the current day is less than or equal to its price on the given day. 

For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, 
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6} 

*/

#include <iostream>
#include <stack>

// Method 1: Brute force.......    Time complexity: O(n^2)
/*
void calculateSpan(int price[], int n, int S[])
{
    // Span value of first day is always 1
    S[0] = 1;
    for (int i = 1; i < n; i++)
    {
        S[i] = 1;
        // Traverse left while the next element on left is smaller than price[i]
        for (int j = i - 1; j >= 0 && price[j] <= price[i]; j--)
        {
            S[i]++;
        }
    }
} */

// Method 2. Using stack.......     Time complexity: O(n)
void calculateSpan(int price[], int n, int span[])
{
    std::stack<int> st;
    st.push(0);
    // Span value of first day is always 1
    span[0] = 1;
    for (int i = 1; i < n; i++)
    {
        // Pop elements from stack while stack is not empty and top of stack is smaller than price[i]
        while (!st.empty() && price[st.top()] <= price[i])
        {
            st.pop();
        }
        // If stack becomes empty, then price[i] is greater than all elements on left of it
        // Else price[i] is greater than elements after top of stack
        span[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }
}

// Driver code
int main()
{
    int price[] = { 10, 4, 5, 90, 120, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    int* span = new int[n];

    // Fill the span values in array S[]
    calculateSpan(price, n, span);

    for (int i = 0; i < n; i++)
        std::cout << span[i] << " ";

    return 0;
}