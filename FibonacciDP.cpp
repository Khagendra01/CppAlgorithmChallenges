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

int fibRec(int n)
{
    fibCache = new int[n];
    for (int i = 0; i <= n; i++)
    {
        fibCache[i] = -1;
    }
    fibDP(n);
    return fibCache[n];
}

int fibIter(int n)
{

    int prev = 0;
    int current = 1;

    int next;

    for (int i = 2; i <= n; i++)
    {
        int next = current + prev;
        prev = current;
        current = next;
    }

    return current;
}

int main()
{
    cout << fibRec(7) << "\n";
    cout << fibIter(7);
    return 0;
}