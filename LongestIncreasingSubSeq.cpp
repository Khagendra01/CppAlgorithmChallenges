#include <bits/stdc++.h>
using namespace std;

map<int, int> myMap;

int getMax(int a, int b) { return (a > b) ? a : b; }

int LISMEM(int* arr, int n, int i)
{
    if (myMap.find(i) != myMap.end())
    {
        return myMap[i];
    }

    myMap[i] = 1;

    for( int j = 0; j < i; j++)
    {
        if(arr[i] > arr[j])
        {
            myMap[i] = getMax(myMap[i], 1 + LISMEM(arr, n, j));
        }
    }

    return myMap[i];
}

int LIS(int* arr, int n)
{
    myMap[0] = 1;
    int max = 1;
    for (int i = 1; i < n; i++)
    {
        max = getMax(max, LISMEM(arr, n, i));
    }
    return max;
}

int main()
{
    int arr[] = {1, 2, 3, 4 ,5, 6 ,7 , 1, 8};


    cout << LIS(arr, sizeof(arr)/ sizeof(arr[0]));//expected output = 8
}