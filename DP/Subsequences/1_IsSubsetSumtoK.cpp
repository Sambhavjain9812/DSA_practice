#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= k)
    {

        dp[0][arr[0]] = true;
    }
    for (int row = 1; row < n; row++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notake = dp[row - 1][target];
            bool take = false;
            if (arr[row] <= target)
            {
                take = dp[row - 1][target - arr[row]];
            }
            dp[row][target] = notake || take;
        }
    }
    return dp[n - 1][k];
}