#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool solve(string s, unordered_set<string> &mp)
    {
        if (mp.size() == 0)
            return false;

        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j])
                {
                    string temp = s.substr(j, i - j);
                    if (mp.find(temp) != mp.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
    bool wordBreak(string s, vector<string> &wd)
    {
        unordered_set<string> mp;
        for (int i = 0; i < wd.size(); i++)
        {
            mp.insert(wd[i]);
        }
        return solve(s, mp);
    }
};