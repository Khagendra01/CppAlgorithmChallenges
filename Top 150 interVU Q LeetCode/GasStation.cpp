#include <bits/stdc++.h>
using namespace std;

int nxt(int i, vector<int> &gas)
{
    return (gas.size() - 1 == i) ? 0 : i + 1;
}

int canCompleteCircuitII(vector<int> &gas, vector<int> &cost)
{
    int tank = 0;
    for(int i = 0; i < gas.size() - 1; i++)
    {
        int j = i;
        tank = tank + gas[j] - cost[j];
        j = nxt(j, gas);
        while(tank > -1)
        {
            
            tank = tank + gas[j] - cost[j];
            j = nxt(j, gas);
            if(tank < 0 || j == i)
            {
                break;
            }
        }
        if( j == i)
        {
            return i;
        }
        
        tank = 0;
    }
    return -1;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << canCompleteCircuitII(gas, cost);

    return 0;
}