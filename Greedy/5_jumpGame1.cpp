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
    bool canJump(vector<int> &nums)
    {
        int target = nums.size() - 1;
        for (int i = target; i >= 0; i--)
        {
            if (nums[i] + i >= target)
            {
                target = i;
            }
        }
        return target == 0;
    }
};