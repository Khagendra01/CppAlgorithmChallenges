#include <bits/stdc++.h>
using namespace std;

int **dpMem;

int minED(string f, string s, int fL, int sL)
{
    if (fL == 0)
    {
        return sL;
    }
    if (sL == 0)
    {
        return fL;
    }
    if (f[fL] == s[sL])
    {
        return minED(f, s, fL - 1, sL - 1);
    }

    int ins = 1 + minED(f, s, fL - 1, sL);
    int del = 1 + minED(f, s, fL, sL - 1);
    int rep = 1 + minED(f, s, fL - 1, sL - 1);

    return min(ins, min(del, rep));
}



int main()
{

    string first = "APPLE";
    string second = "BDDLE";

    cout << minED(first, second, first.size(), second.size()) << "\n";
    //cout << recMinEDDyp(first, second, first.size(), second.size());
    return 0;
}