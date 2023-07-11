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
    int atmost(int k, vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int count = 0, j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            while (mp.size() > k)
            {
                if (mp[nums[j]] == 1)
                    mp.erase(nums[j]);
                else
                    mp[nums[j]]--;

                j++;
            }
            count += i - j + 1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atmost(k, nums) - atmost(k - 1, nums);
    }
};

/*
Concept is very simple u just have to convert the problem in a better problem
ans for k=3 will be difference of atmost(3)-atmost(3)
now for the function atmost

*/

