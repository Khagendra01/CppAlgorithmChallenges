#include <bits/stdc++.h>
using namespace std;

int *fibCache;

int fibDP(int n)
{
    if (fibCache[n] != -1)
    {
        return fibCache[n];
    }

    int result;

    if (n <= 1)
    {
        result = n;
    }
    else
    {
        result = fibDP(n - 1) + fibDP(n - 2);
        fibCache[n] = result;
        return result;
    }
}

int fibPrint(int n)
{
    fibCache = new int[n];
    for (int i = 0; i <= n; i++)
    {
        fibCache[i] = -1;
    }
    fibDP(n);
    return fibCache[n];
}

int main()
{
    cout << fibPrint(7);
    return 0;
}