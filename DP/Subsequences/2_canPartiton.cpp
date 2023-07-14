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
        bool canPartition(vector<int> &nums)
        {
            int sum = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                sum += nums[i];
            }
            if (sum % 2 != 0)
            {
                return false;
            }
            int target = sum / 2;
            vector<vector < bool>> dp(n, vector<bool> (target + 1, false));
            for (int i = 0; i < n; i++)
            {
                dp[i][0] = true;
            }
            if (nums[0] <= target)
            {
                dp[0][nums[0]] = true;
            }
            for (int row = 1; row < n; row++)
            {
                for (int k = 1; k <= target; k++)
                {
                    bool nottake = dp[row - 1][k];
                    bool take = false;
                    if (nums[row] <= k)
                    {
                        take = dp[row - 1][k - nums[row]];
                    }
                    dp[row][k] = take || nottake;
                }
            }
            return dp[n - 1][target];
        }
};



// Same as the previous one just a twist