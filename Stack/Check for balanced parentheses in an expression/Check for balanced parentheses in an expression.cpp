/* Given an expression string exp, write a program to examine whether the pairs and the orders of 
“{“, “}”, “(“, “)”, “[“, “]” are correct in exp.

Example:

Input: exp = “[()]{}{[()()]()}”
Output: Balanced

Input: exp = “[(])”
Output: Not Balanced
*/

#include <iostream>
#include <stack>

bool areParenthesisBalanced(std::string  expr)
{
    std::stack<char> st;
    int n = expr.length();
    char x;
    for(int i = 0; i < n; i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            st.push(expr[i]);
            continue;
        }

        // If current current character is not opening bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (st.empty())
            return false;
        x = st.top();
        st.pop();
        switch (expr[i])
        {
        case ')':
            if (x != '(')
                return false;
            break;
        case '}':
            if (x != '{')
                return false;
            break;
        case ']':
            if (x != '[')
                return false;
            break;
        }
    }
    return (st.empty());
}

// Driver program to test above function 
int main()
{
    std::string expr = "{()}[]";

    if (areParenthesisBalanced(expr))
        std::cout << "Balanced";
    else
        std::cout << "Not Balanced";
    return 0;
}


