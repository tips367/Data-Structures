/* Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then 
make all the cells of ith row and jth column as 1. 

Example 1
The matrix
1 0
0 0

should be changed to following
1 1
1 0

Example 2

The matrix
1 0 0 1
0 0 1 0
0 0 0 0

should be changed to following
1 1 1 1
1 1 1 1
1 0 1 1
*/

#include <iostream>
#include <vector>

// Method 1. Use two temporary arrays...Time complexity : O(m * n), Space : O(m + n)
/*
void modifyMatrix(std::vector<std::vector<int>>& matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();

    std::vector<bool> row(r, 0);
    std::vector<bool> col(c, 0);

    // Store the rows and columns to be marked as 1 in row and col vectors
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 1)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Modify the input matrix using the above constructed row and col vectors
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 1;
            }
        }
    }

} */

// Method 2. Space optimized...Time complexity : O(m * n), Space : O(1)
void modifyMatrix(std::vector<std::vector<int>>& matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();

    // variables to check if there are any 1 in first row and column
    bool rowFlag = false;
    bool colFlag = false;

    // updating the first row and col if 1 is encountered
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            if (i == 0 && matrix[i][j] == 1)
                rowFlag = true;

            if (j == 0 && matrix[i][j] == 1)
                colFlag = true;

            if (matrix[i][j] == 1) {

                matrix[0][j] = 1;
                matrix[i][0] = 1;
            }
        }
    }

    // Modify the input matrix using the first row and first column of matrix
    for (int i = 1; i < r; i++) 
    {
        for (int j = 1; j < c; j++) 
        {

            if (matrix[0][j] == 1 || matrix[i][0] == 1) 
                matrix[i][j] = 1;
        }
    }

    // modify first row if there was any 1 (based on rowFlag)
    if (rowFlag == true)
        for (int i = 0; i < c; i++) 
            matrix[0][i] = 1;

    // modify first col if there was any 1 (based on colFlag)
    if (colFlag == true)
        for (int i = 0; i < r; i++)
            matrix[i][0] = 1;
    return;
}

void printMatrix(std::vector<std::vector<int>>& matrix)
{
    int i, j;
    for (i = 0; i < matrix.size(); i++)
    {
        for (j = 0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = { {1, 0, 0, 1},
                                             {0, 0, 1, 0},
                                             {0, 0, 0, 0} };

    std::cout << "Input Matrix \n";
    printMatrix(matrix);

    modifyMatrix(matrix);

    std::cout << "Matrix after modification \n";
    printMatrix(matrix);

    return 0;
}

