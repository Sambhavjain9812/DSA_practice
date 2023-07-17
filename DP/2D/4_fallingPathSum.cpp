#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
using namespace std;
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = n - 2; i >= 0; i--)
        {
            int a = matrix[i].size();
            for (int j = 0; j < a; j++)
            {
                int minVal = matrix[i + 1][j];
                if (j > 0)
                {
                    minVal = min(minVal, matrix[i + 1][j - 1]);
                }
                if (j < a - 1)
                {
                    minVal = min(minVal, matrix[i + 1][j + 1]);
                }
                matrix[i][j] += minVal;
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, matrix[0][i]);
        }
        return ans;
    }
};