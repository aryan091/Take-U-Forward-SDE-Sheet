#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int findLargestBruteForce(int arr[] , int n)
{
    sort(arr , arr + n);
    return arr[n-1];

    // TC -> O(NlogN) Sorting
    // SC -> O(1)
}

int findLargestOptimal(int arr[] , int n)
{
    int largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if( arr[i]>largest)
        {
            largest = arr[i];
        }
    }
    
    return largest;

    // TC -> O(N) Travesing the Array
    // SC -> O(1)
}

int main()
{
    int arr[] = {100 , 20 , 350 , 540 , 250};
    int n = 5;
    int largestBF = findLargestBruteForce( arr , n);
    cout << largestBF <<" ";
    int largestOptimal = findLargestOptimal(arr , n);
    cout<< largestOptimal;
    return 0;
}