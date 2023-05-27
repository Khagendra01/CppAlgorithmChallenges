#include <bits/stdc++.h>
using namespace std;

int trapEm(int *heights, int n)
{
    int *left = new int[n + 1];
    int *right = new int[n + 1];

    left[0] = heights[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], heights[i]);
    }

    right[n - 1] = heights[n - 1];
    for (int j = n - 2; j >= 0; j--)
    {
        right[j] = max(right[j + 1], heights[j]);
    }
    int water = 0;

    for (int k = 0; k < n; k++)
    {
        water += (min(left[k], right[k])) - heights[k];
    }

    return water;
}

int main()
{
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int water = trapEm(height, sizeof(height) / sizeof(height[0]));

    cout << water;
    return 0;
}