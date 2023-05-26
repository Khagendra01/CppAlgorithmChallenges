#include <bits/stdc++.h>
using namespace std;

int trapEm(int *heights, int n)
{
    return 0;
}

int main()
{
    int height[] = { 0,1,0,2,1,0,1,3,2,1,2,1};

    int water = trapEm(height, sizeof(height)/sizeof(height[0]));

    cout << water;
    return 0;
}