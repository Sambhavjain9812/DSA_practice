#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<int> replaceWithRank(vector<int> &arr, int n)
{
    // Write your code here
    vector<int> res;
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    unordered_map<int, int> mp;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(temp[i]) != mp.end())
        {
            continue;
        }
        else
        {
            mp[temp[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        res.push_back(mp[arr[i]]);
    }
    return res;
}