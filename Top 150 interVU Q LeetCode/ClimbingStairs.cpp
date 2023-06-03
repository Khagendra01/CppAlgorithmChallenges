int climbNow(int n, vector<int> &memo)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }
    int result;
    if (n <= 1)
    {
        result = 1;
    }
    else
    {
        result = climbNow(n - 1, memo) + climbNow(n - 2, memo);
    }

    memo[n] = result;
    return result;
}

int climbStairs(int n)
{
    vector<int> memo(n + 1, -1);
    climbNow(n, memo);
    return memo[n];
}