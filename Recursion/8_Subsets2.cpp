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
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int n, int start)
    {
        ans.push_back(temp);
        for (int i = start; i < n; i++)
        {
            if (i == start || nums[i] != nums[i - 1])
            {
                temp.push_back(nums[i]);
                helper(nums, ans, temp, n, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, ans, temp, nums.size(), 0);
        return ans;
    }
};