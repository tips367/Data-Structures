/* Given two balanced binary search trees e.g., AVL or Red Black Tree. Write a function that merges the two given 
balanced BSTs into a balanced binary search tree.
*/

#include <iostream>
#include <vector>

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

void convertTreeToVector(Node* node, std::vector<int>& v)
{
    if (node == NULL)
        return;
    convertTreeToVector(node->left, v);
    v.push_back(node->data);
    convertTreeToVector(node->right, v);
}

// A utility function to merge two sorted vectors into one
std::vector<int>& mergeSortedVectors(std::vector<int>& v1, std::vector<int>& v2)
{
    int sizeV1 = v1.size();
    int sizeV2 = v2.size();
    std::vector<int>* mergedVector = new std::vector<int>();
    int i = 0, j = 0;

    while (i < sizeV1 && j < sizeV2)
    {
        // Pick the smaller element and put it in mergedVector
        if (v1[i] < v2[j])
        {
            mergedVector->push_back(v1[i]);
            i++;
        }
        else
        {
            mergedVector->push_back(v2[j]);
            j++;
        }
    }

    // If there are more elements in first vector
    while (i < sizeV1)
    {
        mergedVector->push_back(v1[i]);
        i++;
    }

    // If there are more elements in second vector
    while (j < sizeV2)
    {
        mergedVector->push_back(v2[j]);
        j++;
    }

    return *mergedVector;
}

Node* sortedVectorToBST(std::vector<int>& vec, int start, int end)
{
    if (start > end)
        return NULL;

    // Get the middle element and make it root
    int mid = (start + end) / 2;
    Node* root = new Node(vec[mid]);

    // Recursively construct the left subtree and make it left child of root
    root->left = sortedVectorToBST(vec, start, mid - 1);

    // Recursively construct the right subtree and make it right child of root
    root->right = sortedVectorToBST(vec, mid + 1, end);

    return root;
}

Node* merge(Node* root1, Node* root2)
{
    // store inorder traversal of first tree in vector 1
    std::vector<int> vec1;
    convertTreeToVector(root1, vec1);

    // store inorder traversal of second tree in vector 2
    std::vector<int> vec2;
    convertTreeToVector(root2, vec2);

    // Merge the two sorted vectors into one
    std::vector<int>& mergedVector = mergeSortedVectors(vec1, vec2);

    // Construct a tree from the merged vector and return root of the tree
    return sortedVectorToBST(mergedVector, 0, mergedVector.size() - 1);
}

// A utility function to print Inoder traversal of a Binary Tree
void printInOrder(Node* node)
{
    if (node == NULL)
        return;

    // recur on left subtree
    printInOrder(node->left);

    // print node data
    std::cout << node->data << " ";

    // then recur on right subtree
    printInOrder(node->right);
}

int main()
{
    Node* root1 = NULL, * root2 = NULL;

    /* Create the following tree as first tree
         100
        /   \
       50   300
      /  \
     20  70
    */

    root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    /* Create the following tree as second tree
         80
        /  \
       40  120
    */
    root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    Node* mergedTree = merge(root1, root2);

    std::cout << "Inorder traversal of the merged tree \n";
    printInOrder(mergedTree);

    return 0;
}

