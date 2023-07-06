#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
using namespace std;
class solution
{
public:
    void solve(vector<int> arr, vector<int> &ans, int sum, int i, int n)
    {
        if (i == n)
        {
            ans.push_back(sum);
            return;
        }
        solve(arr, ans, sum + arr[i], i + 1, n);
        solve(arr, ans, sum, i + 1, n);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        solve(arr, ans, 0, 0, n);
        return ans;
    }
};