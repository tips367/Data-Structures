/* Given a stack, sort it using recursion. Use of any loop constructs like while, for..etc is not allowed. 
We can only use the following ADT functions on Stack S: 

is_empty(S)  : Tests whether stack is empty or not.
push(S)      : Adds new element to the stack.
pop(S)       : Removes top element from the stack.
top(S)       : Returns value of the top element. Note that this function does not remove element from the stack.

*/

#include <iostream>
#include <stack>

void sortedInsert(std::stack<int>& st, int item)
{
	// Base case: Either stack is empty or newly inserted
	// item is greater than top
	if (st.empty() || item > st.top())
	{
		st.push(item);
	}
	else
	{
		// If top is greater, remove the top item and recur
		int x = st.top();
		st.pop();
		sortedInsert(st, item);

		// Put back the top item removed earlier
		st.push(x);
	}
}

void sortStack(std::stack<int>& st)
{
	if (!st.empty())
	{
		// Hold all items in Function Call Stack until we reach end of the stack 
		int item = st.top();
		st.pop();

		// Call it again so that all the elements get popped and then we insert the top element in stack in sorted order.
		sortStack(st);

		sortedInsert(st, item);
	}
}

// This functions prints the stack in top to bottom manner
// Note: This function creates a duplicate stack so pop operation on that stack does not impact original stack
void printStack(std::stack<int> duplicate)
{
	while (!duplicate.empty())
	{
		int t = duplicate.top();
		std::cout << t << " ";
		duplicate.pop();
	}
	std::cout << "\n";
}

int main()
{
	std::stack<int> st;
	st.push(30);
	st.push(-5);
	st.push(18);
	st.push(14);
	st.push(-3);

	std::cout << "Stack elements before sorting:" << std::endl;
	printStack(st);

	sortStack(st);

	std::cout << "Stack elements after sorting:" << std::endl;
	printStack(st);

	return 0;
}

