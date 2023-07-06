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
    void helper(int open, int close, int n, string curr, vector<string> &ans)
    {
        if (curr.size() == n * 2)
        {
            ans.push_back(curr);
            return;
        }
        if (open < n)
        {
            helper(open + 1, close, n, curr + '(', ans);
        }
        if (close < open)
        {
            helper(open, close + 1, n, curr + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        helper(0, 0, n, "", ans);
        return ans;
    }
};