#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[] , int n)
{
    int j = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        j = i;
        while ( j > 0 && arr[ j - 1] > arr[j])
        {
            swap(arr[ j - 1] , arr[j]);
            j--;
        }
        
    }
    
}

int main()
{

    int n = 5;
    int arr[] = { 13 , 46 , 54 , 18 , 9 };
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }

    cout<< endl;
    
    insertionSort( arr , n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    
    return 0;
}