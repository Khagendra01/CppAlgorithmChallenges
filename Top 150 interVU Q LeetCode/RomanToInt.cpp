#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    int n = s.size();
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'M')
        {
            if (i == 0)
            {
                val += 1000;
            }
            else
            {
                if (s[i - 1] == 'C')
                {
                    val += 900;
                    cout << "yes" << val << "\n";
                }
                else
                {
                    val += 1000;
                }
            }
        }

        if (s[i] == 'D')
        {
            if (i == 0)
            {
                val += 500;
            }
            else
            {
                if (s[i - 1] == 'C')
                {
                    val += 400;
                }
                else
                {
                    val += 500;
                }
            }
        }

        if (s[i] == 'C')
        {
            if (i == 0)
            {
                val += 100;
            }
            else
            {
                if (s[i - 1] == 'X')
                {
                    val += 90;
                }
                else
                {
                    val += 100;
                }
            }
        }

        if (s[i] == 'L')
        {
            if (i == 0)
            {
                val += 50;
            }
            else
            {
                if (s[i - 1] == 'X')
                {
                    val += 40;
                }
                else
                {
                    val += 50;
                }
            }
        }

        if (s[i] == 'X')
        {
            if (i == 0)
            {
                val += 10;
            }
            else
            {
                if (s[i - 1] == 'I')
                {
                    val += 9;
                }
                else
                {
                    val += 10;
                }
            }
        }

        if (s[i] == 'V')
        {
            if (i == 0)
            {
                val += 5;
            }
            else
            {
                if (s[i - 1] == 'I')
                {
                    val += 4;
                }
                else
                {
                    val += 5;
                }
            }
        }
        if (s[i] == 'I')
        {
            val += 1;
        }
    }
}

int romanToIntII(string s)
{
    map<char, int> myMap;
    myMap['I'] = 1;
    myMap['V'] = 5;
    myMap['X'] = 10;
    myMap['L'] = 50;
    myMap['C'] = 100;
    myMap['D'] = 500;
    myMap['M'] = 1000;

    int val = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if( i > 0 && myMap[s[i]] > myMap[s[i-1]])
        {
            val += myMap[s[i]] - (2 * myMap[s[i - 1]]);
            continue; 
        }
        val += myMap[s[i]];
    }
    return val;
}

int main()
{
    cout << romanToIntII("MCMXCIV");
    return 0;
}