/* Given a 2D array, find the maximum sum subarray in it. */

#include <iostream>
#include <vector>


void printMaxSumRectange(std::vector<std::vector<int>>& matrix, int left, int right, int top, int bottom);
int kadane(int* arr, int n, int& start, int& end)
{
    int maxSum = INT_MIN;

    // initial value to check for all negative values case
    end = -1;

    int localStart = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            localStart = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            start = localStart;
            end = i;
        }
    }

    // There is at-least one non-negative number
    if (end != -1)
        return maxSum;

    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];
    start = end = 0;

    // Find the maximum element in array
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            start = end = i;
        }
    }
    return maxSum;
}

void maxSumRectangle(std::vector<std::vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int maxRecSum = INT_MIN;
    int maxRecLeft, maxRecRight, maxRecTop, maxRecBottom, sum, top, bottom;

    int* temp = new int[row];

    // Set the left column
    for (int left = 0; left < col; left++)
    {
        memset(temp, 0, sizeof(int) * row);
        // Set the right column for the left column set by outer loop
        for (int right = left; right < col; right++)
        {
            // Calculate sum between current left and right for every row 'i'
            for (int i = 0; i < row; i++)
            {
                temp[i] += matrix[i][right];
            }

            sum = kadane(temp, row, top, bottom);

            if (sum > maxRecSum)
            {
                maxRecSum = sum;
                maxRecLeft = left;
                maxRecRight = right;
                maxRecTop = top;
                maxRecBottom = bottom;
            }
        }
    }

    std::cout << "Max sum is: " << maxRecSum << std::endl;
    printMaxSumRectange(matrix, maxRecLeft, maxRecRight, maxRecTop, maxRecBottom);
}

void printMaxSumRectange(std::vector<std::vector<int>>& matrix, int left, int right, int top, int bottom)
{
    std::cout << "\nMaximum Sum Rectangle is :\n";
    for (int i = top; i <= bottom; i++)
    {
        for (int j = left; j <= right; j++)
        {
            std::cout << matrix[i][j] << "     ";
        }
        std::cout << "\n";
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = { {  1 , 2, -1, -4, -20 },
                                                 { -8, -3,  4,  2,  1 },
                                                 {  3,  8,  10, 1,  3 },
                                                 { -4, -1,  1,  7, -6 } };

    maxSumRectangle(matrix);

    return 0;
}


