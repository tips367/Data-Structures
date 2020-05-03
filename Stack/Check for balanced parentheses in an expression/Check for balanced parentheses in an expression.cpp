// Check for balanced parentheses in an expression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

bool areParenthesisBalanced(std::string  expr)
{
    std::stack<char> st;
    int n = expr.length();
    char x;
    for (int i = 0; i < n; i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            st.push(expr[i]);
            continue;
        }
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


