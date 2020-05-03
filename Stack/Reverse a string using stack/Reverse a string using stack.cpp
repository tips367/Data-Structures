// Reverse a string using stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

void reverse(char str[])
{
    std::stack<int> st;
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        st.push(str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        str[i] = st.top();
        st.pop();
    }
}

// Driver code  
int main()
{
    char str[] = "GeeksQuiz";

    reverse(str);
    std::cout << "Reversed string is " << str;

    return 0;
}


