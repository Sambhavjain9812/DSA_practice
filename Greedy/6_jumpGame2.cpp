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
    int jump(vector<int> &nums)
    {
        int ans = 0, end = 0, farthest = 0;
        int n = nums.size() - 1;
        for (int i = 0; i < n; i++)
        {
            farthest = max(farthest, nums[i] + i);
            if (farthest >= n)
            {
                ans++;
                break;
            }
            if (i == end)
            {
                ans++;
                end = farthest;
            }
        }
        return ans;
    }
};