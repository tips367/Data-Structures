/* Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. 
Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. 
The designed algorithm should have linear time complexity. 

Example: 

Input: mat[4][4] = {  {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 29
Output: Found at (2, 1)

Input : mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 100
Output : Element not found
*/

#include <iostream>
#include <vector>

void search(std::vector<std::vector<int>>& matrix, int key)
{
    int n = matrix.size();
    int minimum = matrix[0][0], maximum = matrix[n - 1][n - 1];

    if (key < minimum || key > maximum)
    {
        std::cout << "Element not found";
        return;
    }

    // set index for top right element
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == key)
        {
            std::cout << "Element found at " << i << ", " << j;
            return;
        }
        else if (matrix[i][j] > key)
            j--;
        else
            i++;
    }

    std::cout << "Element not found";
    return;
}

int main()
{
    std::vector<std::vector<int>> matrix = { { 10, 20, 30, 40 },
                                             { 15, 25, 35, 45 },
                                             { 27, 29, 37, 48 },
                                             { 32, 33, 39, 50 } };
    search(matrix, 29);

    return 0;
}


