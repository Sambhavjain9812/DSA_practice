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
    int minInsertions(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector<int>> output(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int a = output[i - 1][j - 1];
                int b = output[i][j - 1];
                int c = output[i - 1][j];
                if (s[n - i] == t[n - j])
                {
                    output[i][j] = a + 1;
                }
                else
                {
                    output[i][j] = max(b, c);
                }
            }
        }
        int a = output[n][n];
        return n - a;
    }
};