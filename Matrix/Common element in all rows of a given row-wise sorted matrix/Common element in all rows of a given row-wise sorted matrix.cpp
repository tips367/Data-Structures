/* Given a matrix where every row is sorted in increasing order. Write a function that finds and returns a common 
element in all rows. If there is no common element, then returns -1. 

Example: 
 

Input: mat[4][5] = {{1, 2, 3, 4, 5},
                    {2, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9}};
Output: 5
*/

#include <iostream>
#include <vector>
#include <unordered_map>

#define M 4
#define N 5

// Method 1
/*
void findCommon(int mat[M][N])
{
    // store indexes of current last column
    std::vector<int> column(M, N-1);

    // To store index of row whose current last element is minimum
    int minRow = 0;

    // Keep finding min_row in current last column, till either all elements of last column become same or we hit first column.
    while (column[minRow] >= 0)
    {
        // Find minimum in current last column
        for (int i = 0; i < M; i++)
        {
            if (mat[i][column[i]] < mat[minRow][column[minRow]])
                minRow = i;
        }

        int equalCount = 0;

        for (int i = 0; i < M; i++)
        {
            // Decrease last column index of a row whose value is more than minimum
            if (mat[i][column[i]] > mat[minRow][column[minRow]])
            {
                if (column[i] == 0)
                {
                    std::cout << "No common element";
                    return;
                }
                column[i]--;
            }
            else
            {
                equalCount++;
            }
        }

        if (equalCount == M)
        {
            std::cout << "Common element is " << mat[minRow][column[minRow]];
            return;
        }

    }
    std::cout << "No common element";
} */

// Method 2 : Using HashMap (works even if the rows are not sorted and can be used to print all common elements)
void findCommon(int mat[M][N])
{
    std::unordered_map<int, int> map;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // insert elements of the first row into the map and initialize them with a value of 1
            if (i == 0) 
            {
                map[mat[0][j]] = 1;
            }

            // from the second row onwards, check if the current element exists in the map and first in the current row
            if (i > 0 && map[mat[i][j]] == i)
            {
                // increment the count of the element by 1
                map[mat[i][j]] = i + 1;

                // if `i` represent the last row, print the element
                if (i == M - 1) 
                {
                    std::cout << mat[i][j] << " ";
                }
            }
        }
    }
}

int main()
{
    int mat[M][N] = {
        { 1, 2, 3, 4, 5 },
        { 2, 4, 5, 8, 10 },
        { 3, 5, 7, 9, 11 },
        { 1, 3, 5, 7, 9 },
    };

    findCommon(mat);

    return 0;
}

