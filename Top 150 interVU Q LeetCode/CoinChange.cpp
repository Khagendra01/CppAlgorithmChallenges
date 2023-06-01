#include <bits/stdc++.h>
using namespace std;

int coinRecu(vector<int> &coins, int amount, int i)
{
    if (amount == 0)
    {
        return 0;
    }

    if( i < 0 || amount < 0)
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

        if(include == -1 && noInclude == -1)
        {
            return -1;
        }

        if(include == -1)
        {
            return noInclude + 1;
        }

          if(noInclude == -1)
        {
            return include + 1;
        }


        return min(include, noInclude) + 1;
    }
}

int coinChange(vector<int> &coins, int amount)
{
    return coinRecu(coins, amount, coins.size() - 1);
}

int main()
{
    vector<int> coins = {1,2,5};
    cout << coinChange(coins, 11);
    return 0; 
}