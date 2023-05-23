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

int max( int a, int b) { return (a > b) ? a : b; }

int knapsackIO(Item arr[], int n, int capacity)
{
    if( n == 0 || capacity == 0 ){
        return 0;
    }

    if( arr[n-1].weight > capacity ){
        return knapsackIO(arr, n-1, capacity);
    }
    else
        return max(arr[n-1].profit + knapsackIO(arr, n-1, capacity - arr[n - 1].weight), knapsackIO(arr, n-1, capacity));
}

int main()
{

    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 30;
    int size = sizeof(arr) / sizeof(arr[0]);
    double profit = knapsackIO(arr, size, capacity);
    cout << profit;
    return 0;
}