#include <bits/stdc++.h>
using namespace std;

// this is not correct method
int coinRecu(vector<int> &coins, int amount, int i)
{
    if (amount == 0)
    {
        return 0;
    }

    if (i < 0 || amount < 0)
    {
        return -1;
    }

    if (coins[i] > amount)
    {
        return coinRecu(coins, amount, i - 1);
    }
    else
    {
        int include = coinRecu(coins, amount - coins[i], i);
        int noInclude = coinRecu(coins, amount, i - 1);

        if (include == -1 && noInclude == -1)
        {
            return -1;
        }

        if (include == -1)
        {
            return noInclude + 1;
        }

        if (noInclude == -1)
        {
            return include + 1;
        }

        return min(include, noInclude) + 1;
    }
}

int coinDP(vector<int> &coins, int amount, vector<int> &DP)
{
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return -1;
    }
    if (DP[amount] != -1)
    {
        return DP[amount];
    }

    int n = INT_MAX;
    for (int coin : coins)
    {
        if (amount >= coin)
        {
            int val = coinDP(coins, amount - coin, DP);
            if (val != -1)
            {
                n = min(val + 1, n);
            }
        }
    }
    DP[amount] = (n == INT_MAX) ? -1 : n;
    return DP[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    vector<int> DP(amount + 1, -1);
    return coinDP(coins, amount, DP);
}

int coinChangeIte(vector<int> &coins, int amount)
{
    vector<int> DP(amount + 1, amount + 1);

    DP[0] = 0;

    for(int i = 1; i<= amount; i++)
    {
        for(int coin: coins)
        {
            if(coin <= i)
            {
                DP[i] = min(DP[i], DP[i-coin] + 1) ;
            }
        }
    }
    return amount < DP[amount] ? -1: DP[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    cout << coinChangeIte(coins, 11);
    return 0;
}