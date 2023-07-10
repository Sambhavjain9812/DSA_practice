#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> prefixSum;
        int count = 0;
        int sum = 0;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (sum == goal)
            {
                count++;
            }

            if (prefixSum.count(sum - goal))
            {
                count += prefixSum[sum - goal];
            }

            prefixSum[sum]++;
        }

        return count;
    }
};