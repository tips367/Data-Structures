/* Given a binary matrix, print all unique rows of the given matrix. 

Example: 

Input:
        {0, 1, 0, 0, 1}
        {1, 0, 1, 1, 0}
        {0, 1, 0, 0, 1}
        {1, 1, 1, 0, 0}

Output:

        0 1 0 0 1 
        1 0 1 1 0 
        1 1 1 0 0 
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

// Method 1. Basic...Time complexity: O(row^2 x col), Space : O(1)
/*
void findUniqueRows(std::vector<std::vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        int flag = false;
        for (int j = 0; j < i; j++)
        {
            flag = true;
            for (int k = 0; k < col; k++)
            {
                if (matrix[i][k] != matrix[j][k])
                    flag = false;
            }

            if (flag)
                break;
        }

        if (flag == false)
        {
            for (int j = 0; j < col; j++)
                std::cout << matrix[i][j] << " ";
            std::cout << "\n";
        }
    }
} */

// Method 2. Using Hashset...Time complexity: O(row * col), Space : O(row * col)
void findUniqueRows(std::vector<std::vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    std::unordered_set<std::string> set;

    for (int i = 0; i < row; i++)
    {
        std::string s = "";

        for (int j = 0; j < col; j++)
            s += std::to_string(matrix[i][j]);

        if (set.count(s) == 0)
        {
            set.insert(s);
            std::cout << s << std::endl;

        }
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = { {0, 1, 0, 0, 1},
                                             {1, 0, 1, 1, 0},
                                             {0, 1, 0, 0, 1},
                                             {1, 0, 1, 0, 0} };

    findUniqueRows(matrix);

    return 0;
}

