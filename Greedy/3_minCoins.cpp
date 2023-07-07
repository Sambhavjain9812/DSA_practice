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
    vector<int> minPartition(int N)
    {

        int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

        vector<int> ans;
        int n = sizeof(coins) / sizeof(coins[0]);
        for (int i = n - 1; i >= 0; i--)
        {
            while (coins[i] <= N)
            {
                N -= coins[i];
                ans.push_back(coins[i]);
            }
        }
        return ans;
    }
};