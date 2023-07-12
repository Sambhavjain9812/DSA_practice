#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <map>
#include <string.h>
using namespace std;
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int s)
    {
        int n = hand.size();
        sort(hand.begin(), hand.end());
        map<int, int> mp;
        for (auto e : hand)
        {
            mp[e]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[hand[i]] == 0)
            {
                continue;
            }

            for (int j = 0; j < s; j++)
            {
                int x = hand[i] + j;
                if (mp[x] == 0)
                {
                    return false;
                }
                mp[x]--;
            }
        }
        return true;
    }
};