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
    bool check(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
            return false;
        int i = 0, j = 0;
        while (i < s1.size())
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (s1.size() == i && j == s2.size())
            return true;
        return false;
    }

    static bool compare(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev <= ind - 1; prev++)
            {
                if (check(arr[ind], arr[prev]) && 1 + dp[prev] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                }
            }
            if (dp[ind] > maxi)
            {
                maxi = dp[ind];
            }
        }

        return maxi;
    }
};