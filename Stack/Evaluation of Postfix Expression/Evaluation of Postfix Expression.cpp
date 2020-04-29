// Evaluation of Postfix Expression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

int evaluatePostfix(std::string s)
{
    std::stack<int> st;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i]-'0');
        }
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            default:
                break;
            }
        }
        
    }
    return st.top();
}

// Driver program to test above functions  
int main()
{
    std::string postfixExp = "231*+9-";
    std::cout << "Postfix expression : " << postfixExp << std::endl;
    std::cout << "Postfix evaluation : " << evaluatePostfix(postfixExp);
    return 0;
}
