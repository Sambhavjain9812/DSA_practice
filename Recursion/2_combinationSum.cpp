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
            if (t == 0)
            {
                ans.push_back(ds);
                return;
            }
            for (int i = ind; i < arr.size(); i++)
            {
                if (i > ind && arr[i] == arr[i - 1]) continue;
                if (arr[i] > t)
                {
                    break;
                }
                ds.push_back(arr[i]);
                helper(i + 1, t - arr[i], arr, ds, ans);
                ds.pop_back();
            }
        }
    vector<vector < int>> combinationSum2(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        vector<int> ds;
        vector<vector < int>> ans;
        helper(0, target, arr, ds, ans);
        return ans;
    }
};


// Approach : Pick and Not pick 
// Base Case: if  target ==0 then we must push the datastructure in our ans array and return
// recursion: this time we must use a loop after sorting the arr if arr[i]>target obv break and if we have same number then we continue
//  
