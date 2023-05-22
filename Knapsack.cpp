#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int profit, weight;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

static bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

double knapsack(Item arr[], int n, int capacity)
{
    sort(arr, arr + 3, cmp);
    double profit = 0.0d;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight < capacity)
        {
            capacity = capacity - arr[i].weight;
            profit += arr[i].profit;
        }
        else
        {
            profit = profit + (((double)capacity / arr[i].weight) * arr[i].profit);
            break;
        }
    }
    return profit;
}

int main()
{

    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 35;
    int size = sizeof(arr) / sizeof(arr[0]);
    double profit = knapsack(arr, size, capacity);
    cout << profit;
    return 0;
}
