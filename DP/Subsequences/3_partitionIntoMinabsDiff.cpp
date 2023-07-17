#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
using namespace std;

void helper(int n, int k, vector<int> &arr, vector<vector<bool>> &dp) //prg 1 called asa helper in this
{
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
}

int minSubsetSumDifference(vector<int> &nums, int n)
{
    int sum = 0;
    // int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    int k = sum;
    int ans = 1e9;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    helper(n, k, nums, dp);
    for (int i = 0; i <= k; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int s1 = i;
            int s2 = k - i;
            ans = min(ans, abs(s2 - s1));
        }
    }
    return ans;
}