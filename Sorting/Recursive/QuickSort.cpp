#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int partition(int * arr  , int s , int e)
{
    int pivot = arr[s];
    int i = s;
    int j = e;

    while (i < j) {
        while (arr[i] <= pivot && i <= e ) {
            i++;
        }

        while (arr[j] > pivot && j >= s ) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[s], arr[j]);
    return j;
    
}

void QuickSort(int * arr  , int s , int e)
{
    if( s < e)
    {
        int pivot = partition(arr , s , e);
        QuickSort(arr , s , pivot - 1);
        QuickSort(arr , pivot + 1 , e);
    }
    

}

int main()
{
    
    int n = 1;
    int arr[] = {  18  };
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }

    cout<< endl;
    
    QuickSort( arr  ,  0 , n - 1 );
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    
    return 0;
}