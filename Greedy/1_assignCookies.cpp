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
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0, i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[j] >= g[i])
            {
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};