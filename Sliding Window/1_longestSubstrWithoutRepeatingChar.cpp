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
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int n = s.size();
        int maxlength = 0;
        int start = 0, end = 0;
        while (end < n)
        {
            if (mp.find(s[end]) != mp.end())
            {
                start = max(start, mp[s[end]] + 1);
            }
            mp[s[end]] = end;
            maxlength = max(maxlength, end - start + 1);
            end++;
        }
        return maxlength;
    }
};