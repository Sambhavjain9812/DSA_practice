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
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                triangle[i][j] += min(triangle[i + 1][j + 1], triangle[i + 1][j]);
            }
        }
        return triangle[0][0];
    }
};