#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

bool isSorted( int arr[] , int n)
{
    for (int i = 1; i < n; i++)
    {
        if(arr[i] >= arr[i - 1])
        {

        }
        else
        {
            return false;
        }
    }
    return true;
    // TC -> O(N) Travesing the Array
    // SC -> O(1)
}

int main()
{
    int arr[] = {100 , 20 , 350 , 540 , 250 , 540 , 540};
    int n = 7;
    bool check = isSorted( arr , n);
    cout << check;
    return 0;

}