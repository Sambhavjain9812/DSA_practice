// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
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
    int longestOnes(vector<int> &nums, int k)
    {
        int right = 0, left = 0, zero = 0, count = 0;
        int n = nums.size();
        while (right < n)
        {
            if (nums[right] == 0)
            {
                zero++;
            }
            while (zero > k)
            {
                if (nums[left] == 0)
                {
                    zero--;
                }
                left++;
            }
            count = max(count, right - left + 1);
            right++;
        }
        return count;
    }
};