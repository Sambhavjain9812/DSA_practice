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
        void helper(int ind, int t, vector<int> &arr, vector<int> &ds, vector< vector< int>> &ans)
        {
            if (ind == arr.size())
            {
                if (t == 0)
                {
                    ans.push_back(ds);
                }
                return;
            }
            if (arr[ind] <= t)
            {
                ds.push_back(arr[ind]);
                helper(ind, t - arr[ind], arr, ds, ans);
                ds.pop_back();
            }
            helper(ind + 1, t, arr, ds, ans);
        }
    vector<vector < int>> combinationSum(vector<int> &arr, int target)
    {
        vector<int> ds;
        vector<vector < int>> ans;
        helper(0, target, arr, ds, ans);
        return ans;
    }
};



// Approach : Pick and Not pick 
// Base Case: if index reaches end and target ==0 then we must push the datastructure in our ans array 
// recursion: as question said we can take a index any number of time so in the first recursion we will keept our index and in 
//  in the second one we discard our index