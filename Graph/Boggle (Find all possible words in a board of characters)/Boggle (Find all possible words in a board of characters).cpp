/* Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. 
Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 
8 adjacent characters, but a word should not have multiple instances of same cell.

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G', 'I', 'Z'},
                       {'U', 'E', 'K'},
                       {'Q', 'S', 'E'}};
      isWord(str): returns true if str is present in dictionary else false.

Output:  Following words of dictionary are present
         GEEKS
         QUIZ

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

#define M 3
#define N 4

// Below arrays detail all eight possible movements from a cell
// (top, right, bottom, left, and four diagonal moves)
int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };

// Function to check if it is safe to go to cell (x, y) from the current cell.
// The function returns false if (x, y) is not valid matrix coordinates or cell (x, y) is already processed.
bool isSafe(int i, int j, bool visited[][N])
{
    return (i >= 0 && i < M) && (j >= 0 && j < N) && !visited[i][j];
}

// A recursive function to generate all possible words in a boggle
void searchBoggleDFS(char boggle[][N], std::unordered_set<std::string>& words,
    bool visited[][N], int i, int j, std::string path)
{
    // mark the current node as processed
    visited[i][j] = true;

    // update the path with the current character and insert it into the set
    path = path + boggle[i][j];
    words.insert(path);

    // check for all eight possible movements from the current cell
    for (int k = 0; k < 8; k++)
    {
        // skip if a cell is invalid, or it is already processed
        if (isSafe(i + row[k], j + col[k], visited)) {
            searchBoggleDFS(boggle, words, visited, i + row[k], j + col[k], path);
        }
    }

    // backtrack: mark the current node as unprocessed
    visited[i][j] = false;
}

void searchBoggle(char boggle[][N], std::vector<std::string>& dictionary)
{
    // Mark all characters as not visited
    bool visited[M][N] = { {false} };

    // construct a set to store all possible words constructed from the matrix
    std::unordered_set<std::string> words;

    // generate all possible words in a boggle
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // consider each character as a starting point and run DFS
            searchBoggleDFS(boggle, words, visited, i, j, "");
        }
    }

    // for each word in the dictionary, check whether it is present in the set
    for (auto word : dictionary)
    {
        if (words.find(word) != words.end()) 
        {
            std::cout << word << std::endl;
        }
    }
}

int main()
{
    char boggle[M][N] = 
    {
        {'M', 'S', 'E', 'F'},
        {'R', 'A', 'T', 'D'},
        {'L', 'O', 'N', 'E'}
    };

    std::vector<std::string> dictionary{ "START", "NOTE", "SAND", "STONED" };

    searchBoggle(boggle, dictionary);

    return 0;
}
