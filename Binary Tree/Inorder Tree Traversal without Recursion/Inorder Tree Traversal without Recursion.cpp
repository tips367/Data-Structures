/* Inorder Tree Traversal without Recursion

                       1
                     /   \
                    2     3
                  /  \
                 4    5

Inorder (Left, Root, Right) : 4 2 5 1 3

*/

#include <iostream>
#include <stack>

class Node
{
public:
    int data;
    Node* left, * right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void printInOrder(Node* node)
{
    std::stack<Node*> st;
    Node* current = node;

    while (current != NULL || st.empty() == false)
    {
        // Reach the left most Node of the current Node
        while (current != NULL)
        {
            st.push(current);
            current = current->left;
        }

        // Current will become NULL at this point
        current = st.top();
        st.pop();
        std::cout << current->data << " ";

        // we have visited the node and its left subtree. Now, it's right subtree turn
        current = current->right;
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "Inorder traversal of binary tree is \n";
    printInOrder(root);

    return 0;
}


