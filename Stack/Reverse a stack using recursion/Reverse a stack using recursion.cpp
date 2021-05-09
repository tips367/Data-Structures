/* Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc, and 
you can only use the following ADT functions on Stack S: 

isEmpty(S) 
push(S) 
pop(S)

*/

#include <iostream>
#include <stack>

void pushAtBottom(std::stack<int>& st, int item)
{
	// Here, we want to pop whatever is already in the stack and move 'item' to the bottommost part, then restore/push everything back.

	// We keep on popping till stack is empty and if the stack is empty, then push the element 'item', 
	// This is done because whatever be the stack, we want 'item' to be at the bottommost part.
	if (st.empty())
	{
		st.push(item);
	}
	else
	{
		int x = st.top();
		st.pop();
		// Recursion which ensures that stack becomes empty at some point and then push 'item'
		pushAtBottom(st, item);
		// Push the popped element 'x' since we have already pushed 'item' at the bottommost part now.
		st.push(x);
	}
}

void reverseStack(std::stack<int>& st)
{
	if (!st.empty())
	{
		// Hold all items in Function Call Stack until we reach end of the stack 
		int item = st.top();
		st.pop();

		// Call it again so that all the elements get popped and then we insert the top element 'item' at the bottom.
		reverseStack(st);

		// Inserting the element 'item' at the bottom. If we ensure this happens in every instance of recursion, 
		// we know that the top element 'item' is going to get inserted at the bottom of stack.
		// Since the top element of stack is called first, its recursion instance comes last and so it will be 
		// at the bottommost part of the stack.
		pushAtBottom(st, item);
	}
}

// This functions prints the stack in top to bottom manner
// Note: This function creates a duplicate stack so pop operation on that stack does not impact original stack
void printStack(std::stack<int> duplicate) 
{
	while (!duplicate.empty())
	{
		int t = duplicate.top();
		std::cout << t << std::endl;
		duplicate.pop();
	}
}

int main()
{
	std::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	std::cout << "Original Stack" << std::endl;
	printStack(st);

	reverseStack(st);

	std::cout << "Reversed Stack" << std::endl;
	printStack(st);

	return 0;
}
