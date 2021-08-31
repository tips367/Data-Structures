/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

1. Integers in each row are sorted from left to right.
2. The first integer of each row is greater than the last integer of the previous row.

Example:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

#include <iostream>
#include <vector>

using namespace std;

bool binarySearchOnRow(vector<vector<int>>& matrix, int mid, int target)
{
    int row = size(matrix);
    int col = size(matrix[0]);
    int left = 0;
    int right = col - 1;

    while (left <= right)
    {
        int m = (left + right) / 2;
        if (target == matrix[mid][m])
            return true;
        else if (target < matrix[mid][m])
            right = m - 1;
        else
            left = m + 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int row = size(matrix);
    int col = size(matrix[0]);

    if (target < matrix[0][0] || target > matrix[row - 1][col - 1])
        return false;

    int top = 0;
    int bottom = row - 1;
    while (top <= bottom)
    {
        int mid = (top + bottom) / 2;
        if (target >= matrix[mid][0] && target <= matrix[mid][col - 1])
            return binarySearchOnRow(matrix, mid, target);
        else if (target < matrix[mid][0])
            bottom = mid - 1;
        else
            top = mid + 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = { {1,  3,  5,  7},
                                   {10, 11, 16, 20},
                                   {23, 30, 34, 60} };
    int target = 3;

    if (searchMatrix(matrix, target))
        cout << "Element found";
    else
        cout << "Element not found";
}


