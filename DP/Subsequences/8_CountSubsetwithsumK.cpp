#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
using namespace std;

#define MOD 1000000007

int findWays(vector<int>& arr, int k)
{
    // Let 'n' be the size of the array.
    int n = arr.size();

    // Initialize a 2d matrix 'dp' of size ('n' + 1) * ('k' + 1) with value 0.
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Here dp[i][j] is the number of ways we can get sum 'j' using
    // first 'i' numbers in 'arr' (from arr[0] to arr[i - 1]).


    // Base case: When we have not chosen any number:
    // Number of ways to get sum equal to 0 = 1
    // Number of ways to get sum greater than 0 = 0

    dp[0][0] = 1;
    // dp[0][i] for i > 0 is already initialized to 0.


    // Run a loop from 'i' = 1...'n':
    for (int i = 1; i <= n; i++) {

        // Run a loop from 'j' = 0...'k':
        for (int j = 0; j <= k; j++) {

            // Choice 1: Don't choose i'th number (arr[i - 1])
            // The sum 'j' remains the same.
            dp[i][j] = dp[i - 1][j];

            // Choice 2: Choose i'th number (arr[i - 1])
            // This is only possible when the sum before choosing
            // arr[i - 1] is not negative.
            if (arr[i - 1] <= j) {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
                dp[i][j] %= MOD;
            }
        }
    }

    // Return the value of 'dp[n][k]'.
    return dp[n][k];
}
