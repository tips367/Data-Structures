/* Given a number n, write a function that generates and prints all binary numbers with decimal values from 1 to n. 

Examples: 

Input: n = 2
Output: 1, 10

Input: n = 5
Output: 1, 10, 11, 100, 101
*/

#include <iostream>
#include <queue>

void generateBinary(int n)
{
    // Create an empty queue of strings
    std::queue<std::string> q;

    // Enqueue the first binary number
    q.push("1");

    while (n--) 
    {
        // print the front of queue
        std::string s1 = q.front();
        q.pop();
        std::cout << s1 << "\n";

        std::string s2 = s1; // Store s1 before changing it

        // Append "0" to s1 and enqueue it
        q.push(s1.append("0"));

        // Append "1" to s2 and enqueue it
        q.push(s2.append("1"));
    }
}


int main()
{
    int n = 10;
    generateBinary(n);
    return 0;
}


