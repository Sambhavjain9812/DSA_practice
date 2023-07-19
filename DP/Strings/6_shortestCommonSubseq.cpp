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
    string shortestCommonSupersequence(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = i + j;
                }
                else if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }

        int i = m, j = n;
        string supersequence = "";
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                supersequence += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] <= dp[i][j - 1])
            {
                supersequence += str1[i - 1];
                i--;
            }
            else
            {
                supersequence += str2[j - 1];
                j--;
            }
        }

        while (i > 0)
        {
            supersequence += str1[i - 1];
            i--;
        }

        while (j > 0)
        {
            supersequence += str2[j - 1];
            j--;
        }

        reverse(supersequence.begin(), supersequence.end());
        return supersequence;
    }
};