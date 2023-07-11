#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
using namespace std;
int kDistinctChars(int k, string &str)
{
    unordered_map<char, int> mp; // for storing the count of each character and to find the length of the unique characters
    int maxi = 0;
    int n = str.size();
    int i = 0, j = 0; // two pointers for sliding window
    while (j < n)
    {
        if (mp.find(str[j]) == mp.end())
        {
            mp[str[j]] = 0;
        }
        mp[str[j]]++;
        if (mp.size() < k)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else
        {
            if (mp.size() == k)
            {
                maxi = max(maxi, j - i + 1);
            }
            else if (mp.size() > k)
            {
                while (mp.size() > k)
                {
                    mp[str[i]]--;
                    if (mp[str[i]] == 0)
                        mp.erase(str[i]);
                    i++;
                }
            }
            j++;
        }
    }
    return maxi;
}