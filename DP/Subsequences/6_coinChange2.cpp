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
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            for (int j = 0; j <= amount; j++)
            {
                int nottake = dp[i - 1][j];
                int take = 0;
                if (coins[i - 1] <= j)
                {
                    take = dp[i][j - coins[i - 1]];
                }
                dp[i][j] = take + nottake;
            }
        }

        return dp[n][amount];
    }
};