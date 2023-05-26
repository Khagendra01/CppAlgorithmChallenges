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
    if (f[fL - 1] == s[sL - 1])
    {
        return minED(f, s, fL - 1, sL - 1);
    }

    int ins = 1 + minED(f, s, fL - 1, sL);
    int del = 1 + minED(f, s, fL, sL - 1);
    int rep = 1 + minED(f, s, fL - 1, sL - 1);

    return min(ins, min(del, rep));
}

int recMinEDDP(string f, string s, int fL, int sL)
{
    if (dpMem[fL][sL] != -1)
    {
        return dpMem[fL][sL];
    }

    if (fL == 0)
    {
        dpMem[fL][sL] = sL;
    }
    else if (sL == 0)
    {
        dpMem[fL][sL] = fL;
    }
    else
    {

        int inst = 1 + recMinEDDP(f, s, fL - 1, sL);
        int del = 1 + recMinEDDP(f, s, fL, sL - 1);
        int mismat = recMinEDDP(f, s, fL - 1, sL - 1) + ((f[fL - 1] == s[sL - 1]) ? 0 : 1);

        dpMem[fL][sL] = min(inst, min(del, mismat));
    }
    return dpMem[fL][sL];
}

int recMinEDDyp(string f, string s, int fL, int sL)
{
    dpMem = new int *[fL + 1];
    for (int i = 0; i <= fL; i++)
    {
        dpMem[i] = new int[sL + 1];
    }

    for (int i = 0; i <= fL; i++)
    {
        for (int j = 0; j <= sL; j++)
        {
            dpMem[i][j] = -1;
        }
    }
    return recMinEDDP(f, s, fL, sL);
}

int main()
{

    string first = "KAPPLE";
    string second = "KBDDLE";

    cout << minED(first, second, first.size(), second.size()) << "\n";
    cout << recMinEDDyp(first, second, first.size(), second.size());
    return 0;
}