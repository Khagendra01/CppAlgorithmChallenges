#include <bits/stdc++.h>
using namespace std;

void printEm(int x)
{
    cout << x << " ";
    return;
}

void heapify(int *arr, int n, int p)
{
    int largest = p;
    int l = 2 * p + 1;
    int r = 2* p + 2;

    if(l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
     if(r < n && arr[l] > arr[largest])
    {
        largest = r;
    }

    if( largest!= p ){
        
    }

}

  

void heapSort(int *arr, int n)
{
   for(int i = n/2 -1; i >=0; i ++ )
    buildTheHeap(arr, n, 1);


    return;
}

int main()
{
    int arr[] = {6, 3, 4, 1, 5, 2};

    int size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, size);
    for_each(arr, arr + size, printEm);
    return 0;
}