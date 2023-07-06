#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Solution
{
private:
    int isValidPath(vector<vector<int>> &m, int n, int ratX, int ratY,
                    vector<vector<int>> &visited)
    {
        if ((ratX >= 0 && ratX < n) && (ratY >= 0 && ratY < n) &&
            visited[ratX][ratY] == 0 && m[ratX][ratY] == 1)
            return 1;
        return 0;
    }

    void solveRat(vector<vector<int>> &m, int n, vector<vector<int>> visited,
                  int ratX, int ratY, string str, vector<string> &ans)
    {

        // Base Condition.
        if (ratX == n - 1 && ratY == n - 1)
        {
            ans.push_back(str);
            return;
        }

        visited[ratX][ratY] = 1;

        // Down
        if (isValidPath(m, n, ratX + 1, ratY, visited))
        {
            str += "D";
            solveRat(m, n, visited, ratX + 1, ratY, str, ans);
            str.pop_back();
        }

        // Left
        if (isValidPath(m, n, ratX, ratY - 1, visited))
        {
            str += "L";
            solveRat(m, n, visited, ratX, ratY - 1, str, ans);
            str.pop_back();
        }

        // Right
        if (isValidPath(m, n, ratX, ratY + 1, visited))
        {
            str += "R";
            solveRat(m, n, visited, ratX, ratY + 1, str, ans);
            str.pop_back();
        }

        // UP
        if (isValidPath(m, n, ratX - 1, ratY, visited))
        {
            str += "U";
            solveRat(m, n, visited, ratX - 1, ratY, str, ans);
            str.pop_back();
        }

        visited[ratX][ratY] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        if (m[0][0] == 0)
            return {"-1"};

        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<string> ans;
        string str = "";
        int ratX = 0, ratY = 0;

        solveRat(m, n, visited, ratX, ratY, str, ans);

        return ans;
    }
};