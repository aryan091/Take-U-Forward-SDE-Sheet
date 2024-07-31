
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

void removeDuplicateBruteForce( int arr[] , int n)
{
    set<int> bucket;

        for (int i = 0; i < n; i++)
        {
            bucket.insert(arr[i]);
        }

        int index = 0;
        for( auto it : bucket)
        {
            arr[index++] = it;
        }

        // TC -> O(NlogN) + O(N) Insert into Set & Placing element in Array
        // SC -> O(N) Storing element in Set ( All are Qnique )
}

void removeDuplicateOptimal( int arr[] , int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if( arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }

    // TC -> O(N) Placing element in Array
    // SC -> O(N) Storing element in Set ( All are Qnique )
    
}

int main()
{

    int arr[] = { 1 , 1 , 2 , 2 , 2 , 3 , 3 };
    int n = 7;

    removeDuplicateBruteForce(arr , n);

    // As we know Array is Sorted We can think of much more efficient Solution.
    // Like -> Two Pointer

    removeDuplicateOptimal(arr , n);
    

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

    
}