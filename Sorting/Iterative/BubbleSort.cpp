#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort( int arr[] , int n )
{
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if( arr[ j ] > arr[j + 1])
            {
                swap( arr[ j ] , arr[ j + 1]);
            }
        }
        
    }
    
}

int main()
{
    
    int n = 5;
    
    int arr[]={13 , 46 , 54 , 18 , 9};
    bubbleSort( arr , n );
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    
    return 0;
}