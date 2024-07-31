#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int findSecondLargestBruteForce( int arr[] , int n)
{
    sort(arr , arr + n);
    int largest = arr[n-1];
    int secondLargest = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if(arr[i] != largest)
        {
            secondLargest = arr[i];
            break;
        }
    }

    return secondLargest;

    // TC -> O(NlogN) + O(N) Sorting & For Travesal on Array
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

int findSecondLargestBetter( int arr[] , int n)
{
    int largest = findLargestOptimal(arr , n);

    int secondLargest = -1;
    for (int i = 0; i < n; i++)
    {
        if( arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }
    
    return secondLargest;

    // TC -> O(N) + O(N) Finding Largest Element && Travesing the Array
    // SC -> O(1)
}

int findSecondLargestOptimal( int arr[] , int n)
{
    int largest = arr[0];
    int secondLargest = -1;

    for (int i = 1; i < n; i++)
    {
        if( arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if( arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }
    
    return secondLargest;

    // TC -> O(N) Travesing the Array
    // SC -> O(1)
}

int findSecondSmallestOptimal( int arr[0] , int n)
{
    int smallest = arr[0];
    int secondSmallest = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if( arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if( arr[i] != smallest && arr[i] < secondSmallest)
        {
            secondSmallest = arr[i];
        }
    }
    
    return secondSmallest;

    // TC -> O(N) Travesing the Array
    // SC -> O(1)
}


int main()
{
    int arr[] = {100 , 20 , 350 , 540 , 250 , 540 , 540};
    int n = 7;

    int secondLargestBF = findSecondLargestBruteForce( arr , n);
    cout << secondLargestBF <<" ";

    int secondLargestBetter = findSecondLargestBetter( arr , n);
    cout << secondLargestBetter<<" ";

    int secondLargestOptimal = findSecondLargestOptimal( arr , n);
    cout << secondLargestOptimal<<" ";

    int secondSmallestOptimal = findSecondSmallestOptimal( arr , n);
    cout << secondSmallestOptimal;


    
    return 0;
}