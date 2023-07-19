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
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t)
        {
            return n;
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[n - i] == t[n - j])
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
        return dp[n][n];
    }
};