// Infix to Postfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>


int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(std::string s)
{
    std::stack<char> st;
    st.push('#');
    int l = s.length();
    std::string postfixExp;
    for (int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string. 
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            postfixExp += s[i];

        // If the scanned character is an ‘(‘, push it to the stack. 
        else if (s[i] == '(')
            st.push('(');

        // If the scanned character is an ‘)’, pop and add to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if (s[i] == ')')
        {
            while (st.top() != '#' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                postfixExp += c;
            }
            if (st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }
        //If an operator is scanned 
        else {
            while (st.top() != '#' && precedence(s[i]) <= precedence(st.top()))
            {
                char c = st.top();
                st.pop();
                postfixExp += c;
            }
            st.push(s[i]);
        }

    }
    //Pop all the remaining elements from the stack 
    while (st.top() != '#')
    {
        char c = st.top();
        st.pop();
        postfixExp += c;
    }
    std::cout << "Postfix expression : " << postfixExp << std::endl;
}

//Driver program to test above functions 
int main()
{
    std::string infixExp = "a+b*(c^d-e)^(f+g*h)-i";
    std::cout << "Infix expression : " << infixExp << std::endl;
    infixToPostfix(infixExp);
    return 0;
}
