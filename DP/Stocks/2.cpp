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
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
        {
            return 0;
        }
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};