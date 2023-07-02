int climbStairs(int n)
{
    int first = 1;
    int second = 2;
    if (n <= 2)
        return n;
    for (int i = 3; i <= n; i++)
    {
        int curr = first + second;
        first = second;
        second = curr;
    }
    return second;
}

// One dimensional array implementation
// fibonacci
// house robber