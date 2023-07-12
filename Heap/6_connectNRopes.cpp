#include <queue>;
using namespace std;
int minCost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    int ans = 0;
    while (pq.size() >= 2)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        int z = x + y;
        ans += z;
        pq.push(z);
    }
    return ans;
}