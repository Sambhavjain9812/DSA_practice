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
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return nums;
        }
        vector<int> dp(n, 1), hash(n);
        sort(nums.begin(), nums.end());
        int maxi = 0, lastIndex = 0;
        for (int i = 1; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        // reverse(temp.begin(), temp.end());
        return temp;
    }
};