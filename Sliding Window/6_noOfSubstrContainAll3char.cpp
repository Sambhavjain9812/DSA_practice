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
    int numberOfSubstrings(string s)
    {
        unordered_map<char, int> map;
        int count = 0, start = 0, end = 0;
        int n = s.size();
        while (end < n)
        {
            map[s[end]]++;
            while (map['a'] && map['b'] && map['c'])
            {
                count += n - end; // iska mtlb yeh hai ki yaha tk to hai hi substr but iske baad me kuch bhi add karlo yeh valid rhega to unko bhi count  me add kardia
                map[s[start]]--;
                start++;
            }
            end++;
        }
        return count;
    }
};