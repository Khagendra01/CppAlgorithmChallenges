#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    int l = 0;
    int last;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            l++;
        }
        else
        {
            if (l != 0)
            {
                last = l;
            }
            l = 0;
        }
    }
    return (l != 0) ? l : last;
}

int main()
{
    cout << lengthOfLastWord("Length of last word");
    return 0;
}