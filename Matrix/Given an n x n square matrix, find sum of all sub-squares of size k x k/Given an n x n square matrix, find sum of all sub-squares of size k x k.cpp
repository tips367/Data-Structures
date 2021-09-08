/* Given an n x n square matrix, find sum of all sub-squares of size k x k where k is smaller than or equal to n. 

Examples : 

Input:
n = 5, k = 3

arr[][] = { {1, 1, 1, 1, 1},
            {2, 2, 2, 2, 2},
            {3, 3, 3, 3, 3},
            {4, 4, 4, 4, 4},
            {5, 5, 5, 5, 5},
         };
Output:
       18  18  18
       27  27  27
       36  36  36
*/

#include <iostream>
#include <vector>

#define n 5

// Method 1. Brute force...Time complexity : O (n^2 * k^2), Space : O(1)
/*
void printSum(int mat[][n], int k)
{
    if (k > n) 
        return;

    // row number of first cell in current sub-square of size k x k
    for (int i = 0; i < n - k + 1; i++)
    {
        // column of first cell in current sub-square of size k x k
        for (int j = 0; j < n - k + 1; j++)
        {
            int sum = 0;
            // sum of current sub-square
            for (int x = i; x < i + k; x++)
                for (int y = j; y < j + k; y++)
                    sum += mat[x][y];
            std::cout << sum << "  ";
        }
        std::cout << "\n";
    }
} */

// Method 2. Using precomputed sum...Time complexity : O(n^2), Space : O(n^2)
void printSum(int mat[][n], int k)
{
    if (k > n)
        return;

    int row = n;
    int col = n;
    std::vector<std::vector<int>> dp(row + 1, std::vector<int>(col + 1));

    for (int i = 1; i < dp.size(); i++) 
    {
        for (int j = 1; j < dp[0].size(); j++) 
        {
            dp[i][j] = mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    for (int i = 1; i < dp.size(); i++) 
    {
        for (int j = 1; j < dp[0].size(); j++) 
        {
            if (i - k >= 0 && j - k >= 0) 
            {
                int submatrixSum = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
                std::cout << submatrixSum << " ";
            }           
        }
        std::cout << "\n";
    }
}


int main()
{
    int mat[n][n] = { {1, 1, 1, 1, 1},
                      {2, 2, 2, 2, 2},
                      {3, 3, 3, 3, 3},
                      {4, 4, 4, 4, 4},
                      {5, 5, 5, 5, 5}};
    int k = 3;
    printSum(mat, k);
    return 0;
}
