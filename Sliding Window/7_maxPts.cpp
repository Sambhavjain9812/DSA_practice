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
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += cardPoints[i];
        }
        int maxSum = sum;
        for (int i = k - 1, j = n - 1; i >= 0; i--, j--)
        {
            sum += cardPoints[j] - cardPoints[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};