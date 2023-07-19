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
    int longestCommonSubsequence(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[m - i] == t[n - j])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    int a = dp[i - 1][j];
                    int b = dp[i][j - 1];
                    dp[i][j] = max(a, b);
                }
            }
        }
        return dp[m][n];
    }
};