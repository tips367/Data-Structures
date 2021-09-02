/* Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

For example, consider the below binary matrix.
     0 1 1 0 1
     1 1 0 1 0
     0 1 1 1 0
     1 1 1 1 0
     1 1 1 1 1
     0 0 0 0 0

Maximum size square sub matrix with all 1s has size = 3

*/

#include <iostream>
#include <vector>
#include <algorithm>

#define R 6
#define C 5

int maxSizeSquareSubMatrixWithAllOnes(bool M[][C])
{
    std::vector<std::vector<int>> auxMatrix(R, std::vector<int>(C)); // auxMatrix[R][C]
    int maxSize = 0;

    for (int i = 0; i < R; i++)
    {
        auxMatrix[i][0] = M[i][0];
        maxSize = auxMatrix[i][0] > maxSize ? auxMatrix[i][0] : maxSize;
    }
    for (int j = 0; j < C; j++)
    {
        auxMatrix[0][j] = M[0][j];
        maxSize = auxMatrix[0][j] > maxSize ? auxMatrix[0][j] : maxSize;
    }
    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {
            if (M[i][j] == 0)
            {
                auxMatrix[i][j] = 0;
            }
            else
            {
                auxMatrix[i][j] = std::min(std::min(auxMatrix[i][j - 1], auxMatrix[i - 1][j - 1]), auxMatrix[i - 1][j]) + 1;
                maxSize = auxMatrix[i][j] > maxSize ? auxMatrix[i][j] : maxSize;
            }
        }
    }
    return maxSize;
}

/* Driver code */
int main()
{
    bool M[R][C] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0} };

    std::cout << "Maximum size square sub-matrix with all 1s is: " << maxSizeSquareSubMatrixWithAllOnes(M);
}