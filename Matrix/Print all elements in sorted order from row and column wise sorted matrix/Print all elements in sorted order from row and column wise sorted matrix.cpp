/* Given an n x n matrix, where every row and column is sorted in non-decreasing order. 
Print all elements of matrix in sorted order.

Example: 
 
Input: mat[][]  =  { {10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50},
                    };

Output:
Elements of matrix in sorted order
10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50
*/

#include <iostream>
#include <vector>
#include <queue>

// Time complexity: O(n^2 log n)
struct MinHeapNode
{
    int element; // The element to be stored
    int i; // index of the row from which the element is taken
    int j; // index of the next element to be picked from row
};

class myComparator
{
public:
    int operator() (const MinHeapNode& lhs, const MinHeapNode& rhs)
    {
        return lhs.element > rhs.element;
    }
};

/*
bool operator>(const MinHeapNode& lhs, const MinHeapNode& rhs)
{
    return lhs.element > rhs.element;
} */

void printSorted(std::vector<std::vector<int>>& matrix)
{
    int n = matrix.size();
    std::priority_queue<MinHeapNode, std::vector<MinHeapNode>, myComparator> pq;
    // priority_queue<MinHeapNode, vector<MinHeapNode>, greater<MinHeapNode>> pq;

    for (int row = 0; row < n; row++)
    {
        MinHeapNode m;
        m.element = matrix[row][0];
        m.i = row;
        m.j = 1;
        pq.push(m);
    }

    // Now one by one get the minimum element from min
    // heap and replace it with next element of its array
    for (int count = 0; count < n*n; count++)
    {
        MinHeapNode m = pq.top();
        pq.pop();
        std::cout << m.element << " ";

        if (m.j < n)
        {
            m.element = matrix[m.i][m.j];
            m.j += 1;
        }
        else
            // If root was the last element of its array
            m.element = INT_MAX;

        pq.push(m);
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = { {10, 20, 30, 40},
                                             {15, 25, 35, 45},
                                             {27, 29, 37, 48},
                                             {32, 33, 39, 50},
                                            };
    printSorted(matrix);
    return 0;
}


