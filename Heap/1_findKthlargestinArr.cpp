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
        int findKthLargest(vector<int> &arr, int k)
        {
            priority_queue<int> pq;
            int n = arr.size();

            for (int i = 0; i < arr.size(); i++)
            {
                pq.push(arr[i]);
            }

            int f = k - 1;

            while (f > 0)
            {
                pq.pop();
                f--;
            }
            return pq.top();
        }
};