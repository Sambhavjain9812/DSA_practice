/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/
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
    int n;
    int helper(vector<int> &nums, int k, int i, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            if (k == 0)
                return 1;
            return 0;
        }
        if (dp[i][k] != -1)
            return dp[i][k];
        int notTake = helper(nums, k, i + 1, dp);
        int take = 0;
        if (nums[i] <= k)
        {
            take = helper(nums, k - nums[i], i + 1, dp);
        }
        return dp[i][k] = take + notTake;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        n = nums.size();
        int total = 0;
        for (auto x : nums)
        {
            total += x;
        }
        int k = total - target;
        if (k < 0)
            return 0;
        if (k % 2 == 1)
            return 0;
        k /= 2;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return helper(nums, k, 0, dp);
    }
};