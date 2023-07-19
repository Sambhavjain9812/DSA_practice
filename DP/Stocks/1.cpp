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
        int buy = 1e9;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            buy = min(prices[i], buy);
            int p = prices[i] - buy;
            profit = max(profit, p);
        }
        return profit;
    }
};
