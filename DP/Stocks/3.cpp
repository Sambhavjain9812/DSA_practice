#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n <= 1)
    {
        return 0; // No prices or only one price, no profit
    }

    // First transaction
    int buy1 = 1e9;
    int profit1 = 0;

    // Second transaction
    int buy2 = 1e9;
    int profit2 = 0;

    for (int i = 0; i < n; i++)
    {
        // Update the first buy price
        buy1 = min(buy1, prices[i]);
        // Update the profit after the first sell
        profit1 = max(profit1, prices[i] - buy1);
        // Update the second buy price with the remaining budget after the first sell
        buy2 = min(buy2, prices[i] - profit1);
        // Update the profit after the second sell
        profit2 = max(profit2, prices[i] - buy2);
    }

    return profit2;
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int ans = maxProfit(prices);
    cout << ans;
}