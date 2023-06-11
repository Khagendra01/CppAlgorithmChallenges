#include <bits/stdc++.h>
using namespace std;

int nxt(int i, vector<int> &gas)
{
    return (gas.size() - 1 == i) ? 0 : i + 1;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    if (gas.size() == 1)
    {
        return (gas[0] >= cost[0]) ? 0 : -1;
    }
    int tank = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        int j = i;
        tank = tank + gas[j] - cost[j];
        j = nxt(j, gas);
        while (tank > -1)
        {

            tank = tank + gas[j] - cost[j];

            if (tank < 0 || j == i)
            {
                break;
            }
            j = nxt(j, gas);
        }
        if (j == i)
        {
            return i;
        }

        tank = 0;
    }
    return -1;
}


int canCompleteCircuitII(vector<int> &gas, vector<int> &cost)
{
    int totalTank = 0;
    int currentTank = 0;
    int index = 0;
    for( int i = 0; i < gas.size(); i++)
    {
        totalTank += gas[i] - cost[i];
        if(currentTank < 0)
        {
            currentTank = 0;
            index = i;
        }
        currentTank += gas[i] - cost[i];
    }
    return (totalTank < 0) ? -1: index;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << canCompleteCircuitII(gas, cost);

    return 0;
}