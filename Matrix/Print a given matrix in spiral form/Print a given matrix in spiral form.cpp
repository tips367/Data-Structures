/* Given a 2D array, print it in spiral form.

Examples: 

Input:  1    2   3   4
        5    6   7   8
        9   10  11  12
        13  14  15  16

Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 

Input:  1   2   3   4  5   6
        7   8   9  10  11  12
        13  14  15 16  17  18

Output: 1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
*/

#include <iostream>
#include <vector>

void spiralOrder(std::vector<std::vector<int>>& matrix) 
{
    int top = 0;
    int bottom = size(matrix) - 1;
    int left = 0;
    int right = size(matrix[0]) - 1;
    int direction = 0;

    while (left <= right && top <= bottom)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; ++i)
                std::cout << matrix[top][i] << " ";
            ++top;
        }
        else if (direction == 1)
        {
            for (int i = top; i <= bottom; ++i)
                std::cout << matrix[i][right] << " ";
            --right;
        }
        else if (direction == 2)
        {
            for (int i = right; i >= left; --i)
                std::cout << matrix[bottom][i] << " ";
            --bottom;
        }
        else
        {
            for (int i = bottom; i >= top; --i)
                std::cout << matrix[i][left] << " ";
            ++left;
        }
        direction = (direction + 1) % 4;
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = { { 1,  2,  3,  4,  5,  6 },
                                             { 7,  8,  9,  10, 11, 12 },
                                             { 13, 14, 15, 16, 17, 18 } };

    spiralOrder(matrix);

    return 0;
}

