#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || board[0].empty())
        {
            return false;
        }

        int m = board.size();
        int n = board[0].size();

        // Iterate through the board
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    // Start the backtracking search
                    if (dfs(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int index)
    {
        // Check if the current character matches
        if (board[i][j] != word[index])
        {
            return false;
        }

        // Check if all characters of the word have been found
        if (index == word.length() - 1)
        {
            return true;
        }

        // Temporarily mark the current character as visited
        char temp = board[i][j];
        board[i][j] = '*';

        // Explore the neighboring cells in a depth-first manner
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size())
            {
                if (dfs(board, word, x, y, index + 1))
                {
                    return true;
                }
            }
        }

        // Revert the character back to its original value
        board[i][j] = temp;

        return false;
    }
};
