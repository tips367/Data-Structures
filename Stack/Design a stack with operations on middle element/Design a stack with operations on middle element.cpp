/* Implement a stack which will support following operations in O(1) time complexity :

1) push(): which adds an element to the top of stack. 
2) pop(): which removes an element from top of stack. 
3) findMiddle(): which will return middle element of the stack. 
4) deleteMiddle(): which will delete the middle element. */

#include <iostream>

class DLLNode
{
public:
    int data;
    DLLNode* next;
    DLLNode* prev;
};

class Stack
{
public:
    Stack() : head(NULL), mid(NULL), count(0){}
    void push(int newData);
    int pop();
    int findMiddle();
    int deleteMiddle();
    
private:
    DLLNode* head;
    DLLNode* mid;
    int count;
};

void Stack::push(int newData)
{
    // Allocate DLLNode and put in data
    DLLNode* newDLLNode = new DLLNode();
    newDLLNode->data = newData;
    // As we are adding to the beginning, prev will be NULL
    newDLLNode->prev = NULL;
    newDLLNode->next = head;
    // Increment count of items
    count++;

    // Change mid pointer in two cases
    // (1) Linked List is empty
    // (2) Number of nodes in linked list is even
    if (count == 1)
    {
        mid = newDLLNode;
    }
    else
    {
        head->prev = newDLLNode;
        if (count % 2 == 0)
        {
            mid = mid->prev;
        }
    }
    head = newDLLNode;
}

int Stack::pop()
{
    if (count == 0)
    {
        std::cout << "Stack is empty\n";
        return -1;
    }

    DLLNode* temp = head;
    int item = temp->data;
    head = head->next;
    // If linked list doesn't become empty, update prev of new head as NULL
    if (head != NULL)
        head->prev = NULL;
    // Decrement count of items
    count--;

    // update the mid pointer when we have odd number of elements in the stack, i.e move down the mid pointer.
    if (count & 1)
        mid = mid->next;
    delete temp;
    return item;
}

int Stack::findMiddle()
{
    if (count == 0) 
    {
        std::cout << "Stack is empty\n";
        return -1;
    }
    return mid->data;
}

int Stack::deleteMiddle()
{
    if (count == 0)
    {
        std::cout << "Stack is empty\n";
        return -1;
    }
    DLLNode* temp = mid;
    int item = mid->data;
    // Decrement count of items
    count--;
    if (count == 1)
    {
        head = head->next;
        mid = head;
    }
    else if (count > 0)
    {
        mid->prev->next = mid->next;
        mid->next->prev = mid->prev;
        if (count & 1)
        {
            mid = mid->next;
        }
        else
        {
            mid = mid->prev;
        }
    }
    delete temp;
    return item;
}

// Driver code
int main()
{
    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);

    std::cout << "Item popped is " << st.pop() << std::endl;
    std::cout << "Item popped is " << st.pop() << std::endl;
    std::cout << "Middle Element is " << st.findMiddle() << std::endl;
    std::cout << "Deleted mid element " << st.deleteMiddle() << std::endl;
    std::cout << "Middle Element is " << st.findMiddle() << std::endl;
    std::cout << "Deleted mid element " << st.deleteMiddle() << std::endl;
    std::cout << "Middle Element is " << st.findMiddle() << std::endl;
    return 0;
}

/*
class myStack 
{
	stack<int> st;
	deque<int> dq;

public:
	void add(int data)
	{
		dq.push_back(data);
		if (dq.size() > st.size() + 1) {
			int temp = dq.front();
			dq.pop_front();
			st.push(temp);
		}
	}

	void pop()
	{
		int data = dq.back();
		dq.pop_back();
		if (st.size() > dq.size()) {
			int temp = st.top();
			st.pop();
			dq.push_front(temp);
		}
	}

	int getMiddleElement() {
	return dq.front();
	}

	void deleteMiddleElement()
	{
		dq.pop_front();
		if (st.size() > dq.size()) { // new middle element
			int temp = st.top();	 // should come at front of deque
			st.pop();
			dq.push_front(temp);
		}
	}
};

int main()
{
	myStack st;
	st.add(2);
	st.add(5);
	cout << "Middle Element: " << st.getMiddleElement() << endl;
	st.add(3);
	st.add(7);
	st.add(4);
	cout << "Middle Element: " << st.getMiddleElement() << endl;
	st.deleteMiddleElement();
	cout << "Middle Element: " << st.getMiddleElement() << endl;
	st.deleteMiddleElement();
	cout << "Middle Element: " << st.getMiddleElement() << endl;
	st.pop();
	st.pop();
	st.deleteMiddleElement();
}
*/
