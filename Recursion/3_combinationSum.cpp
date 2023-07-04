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
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, k, n, 1);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &curr, int k, int n, int start)
    {
        if (curr.size() == k && n == 0)
        {
            ans.push_back(curr);
            return;
        }
        if (curr.size() == k || n < 0)
        {
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            curr.push_back(i);
            backtrack(ans, curr, k, n - i, i + 1);
            curr.pop_back();
        }
    }
};
