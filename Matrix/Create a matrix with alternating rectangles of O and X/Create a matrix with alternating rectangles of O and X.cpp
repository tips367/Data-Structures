/* Write a code which inputs two numbers m and n and creates a matrix of size m x n (m rows and n columns) in which every 
elements is either X or 0. The Xs and 0s must be filled alternatively, the matrix should have outermost rectangle of Xs, 
then a rectangle of 0s, then a rectangle of Xs, and so on.

Examples:

Input: m = 3, n = 3
Output: Following matrix
X X X
X 0 X
X X X

Input: m = 4, n = 5
Output: Following matrix
X X X X X
X 0 0 0 X
X 0 0 0 X
X X X X X

Input:  m = 5, n = 5
Output: Following matrix
X X X X X
X 0 0 0 X
X 0 X 0 X
X 0 0 0 X
X X X X X
*/

#include <iostream>
#include <vector>

void fill0X(int m, int n)
{
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;
    int direction = 0;

    std::vector<std::vector<char>> matrix(m, std::vector<char>(n));
    char x = 'X';

    while (left <= right && top <= bottom)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; ++i)
                matrix[top][i] = x;
            ++top;
        }
        else if (direction == 1)
        {
            for (int i = top; i <= bottom; ++i)
                matrix[i][right] = x;
            --right;
        }
        else if (direction == 2)
        {
            for (int i = right; i >= left; --i)
                matrix[bottom][i] = x;
            --bottom;
        }
        else
        {
            for (int i = bottom; i >= top; --i)
                matrix[i][left]  = x;
            ++left;
        }
        direction = (direction + 1) % 4;
        if (direction == 0)
            x = (x == 'X') ? 'O' : 'X';
    }

    // Print the filled matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << " " << matrix[i][j];
        std::cout << "\n";
    }
}

int main()
{
    std::cout << "Output for m = 5, n = 6\n";
    fill0X(5, 6);

    std::cout << "\nOutput for m = 4, n = 4\n";
    fill0X(4, 4);

    std::cout << "\nOutput for m = 3, n = 4\n";
    fill0X(3, 4);

    std::cout << "\nOutput for m = 6, n = 7\n";
    fill0X(6, 7);

    return 0;
}


