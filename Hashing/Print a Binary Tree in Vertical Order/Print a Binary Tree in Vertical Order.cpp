/* Given a binary tree, print it vertically. The following example illustrates vertical order traversal.
* 
           1
        /    \
       2       3
     /   \   /   \
    4     5 6     7
              \     \
               8     9 
                        
The output of print this tree vertically will be:

4
2
1 5 6
3 8
7
9 
*/

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <utility>

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

// Method 1: Time complexity : O(w*n), where w is the width of binary tree having n nodes
/*
void findMinMax(Node* node, int& min, int& max, int horizontalDistance)
{
    if (node == NULL)
        return;

    // Update min and max
    min = std::min(min, horizontalDistance);
    max = std::max(max, horizontalDistance);

    // Recur for left and right subtrees
    findMinMax(node->left, min, max, horizontalDistance - 1);
    findMinMax(node->right, min, max, horizontalDistance + 1);
}

void printVerticalLine(Node* node, int verticalLine, int horizontalDistance)
{
    if (node == NULL)
        return;

    if (verticalLine == horizontalDistance)
        std::cout << node->data << " ";

    printVerticalLine(node->left, verticalLine, horizontalDistance - 1);
    printVerticalLine(node->right, verticalLine, horizontalDistance + 1);
}

void verticalOrder(Node* root)
{
    // Find min and max distances with resepect to root
    int min = 0, max = 0;
    findMinMax(root, min, max, 0);

    // Iterate through all possible vertical lines starting
    // from the leftmost line and print nodes line by line
    for (int verticalLine = min; verticalLine <= max; verticalLine++)
    {
        printVerticalLine(root, verticalLine, 0);
        std::cout << "\n";
    }
} */

// Method 2: Using hashmap (may not print nodes in same vertical order as they appear in tree)....Time complexity : O(nlogn)
/*
void getVerticalOrder(Node* root, std::map<int, std::vector<int>>& m, int horizontalDistance)
{
    if (root == NULL)
        return;

    // Store current node in map 'm'
    m[horizontalDistance].push_back(root->data);

    // Store nodes in left subtree
    getVerticalOrder(root->left, m, horizontalDistance - 1);

    // Store nodes in right subtree
    getVerticalOrder(root->right, m, horizontalDistance + 1);
}

void verticalOrder(Node* root)
{
    std::map<int, std::vector<int>> m;
    int horizontalDistance = 0;
    getVerticalOrder(root, m, horizontalDistance);

    // Traverse the map and print nodes at every horizontal distance
    std::map<int, std::vector<int>> ::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); ++i)
            std::cout << it->second[i] << " ";
        std::cout << "\n";
    }
} */

// Method 3: Using hashmap and set (print nodes in same vertical order as they appear in tree)....Time complexity : O(n * logn * logn * logn)
/*
void getVerticalOrder(Node* root, std::map<int, std::map<int, std::multiset<int>>>& m, 
    int horizontalDistance, int verticalDistance)
{
    if (root == NULL)
        return;

    // Store current node
    m[horizontalDistance][verticalDistance].insert(root->data);

    // Store nodes in left subtree
    getVerticalOrder(root->left, m, horizontalDistance - 1, verticalDistance + 1);

    // Store nodes in right subtree
    getVerticalOrder(root->right, m, horizontalDistance + 1, verticalDistance + 1);
}

void verticalOrder(Node* root)
{
    std::map<int, std::map<int, std::multiset<int>>> m;
    int horizontalDistance = 0, verticalDistance = 0;
    getVerticalOrder(root, m, horizontalDistance, verticalDistance);

    // Traverse the map and print nodes
    for (auto m1: m)
    {
        for (auto m2: m1.second)
        {
            for(auto m3: m2.second)
                std::cout << m3 << " ";
        }
        std::cout << "\n";
    }
} */

// Method 4 : Using Level order traversal....Time complexity : O(n*logn*logn)
void verticalOrder(Node* root)
{
    // Create queue to do level order traversal.
    // Every item of queue contains node and horizontal distance.
    std::queue<std::pair<Node*, int>> q;
    q.push({ root, 0 });

    std::map<int, std::multiset<int>> mapset;
    while (!q.empty())
    {
        int count = q.size();

        // Iterate for all the nodes in the queue currently
        while (count--)
        {
            Node* curr = q.front().first;
            int horizontalDistance = q.front().second;
            q.pop();
            // insert this node's data in map of set
            mapset[horizontalDistance].insert(curr->data);

            if (curr->left != NULL)
                q.push({ curr->left, horizontalDistance - 1 });
            if (curr->right != NULL)
                q.push({ curr->right, horizontalDistance + 1 });
        }
    }

    // Traverse the map and print nodes at every horizontal distance
    for (auto m1: mapset)
    {
        for (auto m2: m1.second)
            std::cout << m2 << " ";
        std::cout << "\n";
    }
}

int main()
{
    // Create binary tree shown in above figure
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    std::cout << "Vertical order traversal is \n";
    verticalOrder(root);

    return 0;
}


