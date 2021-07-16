/* Given a Balanced Binary Search Tree and a target sum, write a function that returns true if there is a pair with sum 
equals to target sum, otherwise return false.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
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

// Method 1: InOrder traversal and Two-Pointers technique.......Time complexity : O(n), Space : O(n)
/*
void convertTreeToVector(Node* node, std::vector<int>& v)
{
    if (node == NULL)
        return;
    convertTreeToVector(node->left, v);
    v.push_back(node->data);
    convertTreeToVector(node->right, v);
}

bool isPairPresent(Node* root, int target)
{
    std::vector<int> vec;
    convertTreeToVector(root, vec);

    int start = 0;
    int end = vec.size() - 1;
    while (start < end)
    {
        if (vec[start] + vec[end] == target)
        {
            std::cout << "Pair Found: " << vec[start] << " + " << vec[end] << " = " << target << std::endl;
            return true;
        }
        else if (vec[start] + vec[end] < target)
            start++;
        else
            end--;
    }
    return false;
} */

// Method 2: Using InOrder traversal and set.......Time complexity : O(n), Space : O(n)
/*
bool inOrderUtil(Node* node, std::unordered_set<int>& s, int target)
{
    if (node == NULL)
        return false;

    // return true if pair is found in the left subtree
    if (inOrderUtil(node->left, s, target)) {
        return true;
    }

    // if a pair is formed with the current node, print the pair and return true
    if (s.find(target - node->data) != s.end())
    {
        std::cout << "Pair Found: " << target - node->data << " + " << node->data << " = " << target << std::endl;
        return true;
    }
    // insert the current node's value into the set
    else 
    {
        s.insert(node->data);
    }

    // search in the right subtree
    return inOrderUtil(node->right, s, target);
}

bool isPairPresent(Node* root, int target)
{
    std::unordered_set<int> s;
    return inOrderUtil(root, s, target);
} */

// Method 3: Using Two pointer technique.......Time complexity : O(n), Space : O(log n)
void pushLeftNodes(Node* node, std::stack<Node*>& st1)
{
    while (node)
    {
        st1.push(node);
        node = node->left;
    }
}

void pushRightNodes(Node* node, std::stack<Node*>& st2)
{
    while (node)
    {
        st2.push(node);
        node = node->right;
    }
}

bool isPairPresent(Node* root, int target)
{
    if (root == NULL)
        return false;

    std::stack<Node*> st1, st2;
    pushLeftNodes(root, st1);
    pushRightNodes(root, st2);

    Node* low = st1.top();
    Node* high = st2.top();

    while (low && high && low->data < high->data)
    {
        int sum = low->data + high->data;
        if (sum < target) // increase low
        {
            pushLeftNodes(low->right, st1);
            low = st1.top();
            st1.pop();
        }
        else if (sum > target) // decrease high
        {
            pushRightNodes(high->left, st2);
            high = st2.top();
            st2.pop();
        }
        else
        {
            std::cout << "Pair Found: " << low->data << " + " << high->data << " = " << target << std::endl;
            return true;
        }
    }
    return false;
}

int main()
{
    /* Create BST
    * 
                15
               /  \
             10     20
            /  \   /   \
           8   12 16   25 
    */

    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    int target = 33;
    if (isPairPresent(root, target) == false)
        std::cout << "\nNo such values are found\n";
    return 0;
}

