/* Given a rectangular matrix which has only two possible values ‘X’and ‘O’.The values ‘X’ always appear in form of 
rectangular islandsand these islands are always row - wise and column - wise separated by at least one line of ‘O’s.
Note that islands can only be diagonally adjacent. Count the number of islands in the given matrix.

Examples:

mat[M][N] = { {'O', 'O', 'O'},
              {'X', 'X', 'O'},
              {'X', 'X', 'O'},
              {'O', 'O', 'X'},
              {'O', 'O', 'X'},
              {'X', 'X', 'O'}};

Output: Number of islands is 3

mat[M][N] = { {'X', 'O', 'O', 'O', 'O', 'O'},
              {'X', 'O', 'X', 'X', 'X', 'X'},
              {'O', 'O', 'O', 'O', 'O', 'O'},
              {'X', 'X', 'X', 'O', 'X', 'X'},
              {'X', 'X', 'X', 'O', 'X', 'X'},
              {'O', 'O', 'O', 'O', 'X', 'X'}};

Output: Number of islands is 4

*/

#include <iostream>
#include <vector>

int countIslands(std::vector<std::vector<char>>& mat)
{
    int row = mat.size();
    int col = mat[0].size();

    int count = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // If current cell is 'X', then check whether this is top-leftmost of a rectangle. If yes, then increment count
            if (mat[i][j] == 'X')
            {
                if ((i==0 || mat[i - 1][j] == 'O') && (j == 0 || mat[i][j - 1] == 'O'))
                    count++;
            }
        }
    }

    return count;
}

int main()
{
    std::vector<std::vector<char>>  mat = {{'O', 'O', 'O'},
                                           {'X', 'X', 'O'},
                                           {'X', 'X', 'O'},
                                           {'O', 'O', 'X'},
                                           {'O', 'O', 'X'},
                                           {'X', 'X', 'O'}};

    std::cout << "Number of rectangular islands is " << countIslands(mat);
    return 0;
}