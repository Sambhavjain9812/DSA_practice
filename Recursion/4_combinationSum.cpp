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
    vector<int> dp;
    int solve(vector<int> &nums, int target)
    {
        if (target == 0) // fulfilled original target
            return 1;
        if (target < 0) // cannot find sum = target
            return 0;
        if (dp[target] != -1)
        {
            return dp[target];
        }
        int ways = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ways += solve(nums, target - nums[i]);
        } // for each coin look for target - coin in whole array again
        dp[target] = ways;
        return ways;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        dp.resize(target + 1, -1);
        return solve(nums, target);
    }
};