#include <bits/stdc++.h>
using namespace std;
#define N 9

void printBoard(vector<vector<string>> value)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << value[i][j] << "  ";
        }
        cout << "\n";
    }
}

bool isValid(vector<vector<string>>& value, int R, int C, int V)
{
    for (int i = 0; i < N; i++)
    {
        if (value[R][i] == to_string(V))
        {
            return false;
        }
        if (value[i][C] == to_string(V))
        {
            return false;
        }
    }

    int a = R - (R % 3);
    int b = C - (C % 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (value[a + i][b + j] == to_string(V))
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<string>>& value, int R, int C)
{

    if ((C == N) && (R == N - 1))
    {
        return true;
    }

    if (C == N)
    {
        R++;
        C = 0;
    }

    if(value[R][C] != "0")
    {
        return solveSudoku(value, R, C + 1);
    }

    for (int i = 1; i <= N; i++)
    {
        if (isValid(value, R, C, i))
        {
            value[R][C] = to_string(i);
            if (solveSudoku(value, R, C + 1))
            {
                return true;
            }
        }
        value[R][C] = "0";
    }

    return false;
}

int main()
{
    vector<vector<string>> value = {
        {"5", "3", "0", "0", "7", "0", "0", "0", "0"},
        {"6", "0", "0", "1", "9", "5", "0", "0", "0"},
        {"0", "9", "8", "0", "0", "0", "0", "6", "0"},
        {"8", "0", "0", "0", "6", "0", "0", "0", "3"},
        {"4", "0", "0", "8", "0", "3", "0", "0", "1"},
        {"7", "0", "0", "0", "2", "0", "0", "0", "6"},
        {"0", "6", "0", "0", "0", "0", "2", "8", "0"},
        {"0", "0", "0", "4", "1", "9", "0", "0", "5"},
        {"0", "0", "0", "0", "8", "0", "0", "7", "9"}};

    printBoard(value);

    cout << "\n \n \n \n";

    if (solveSudoku(value, 0, 0))
    {
        printBoard(value);
    }
    else
    {
        cout << "No man you suck";
    }

    return 0;
}