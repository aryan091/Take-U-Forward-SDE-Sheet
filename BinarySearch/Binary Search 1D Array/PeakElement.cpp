#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findPeak( vector<int>& arr)
{
    // size
    int n = arr.size();
    // Edge Cases
    if( n == 1 ) return 0;
    // First element
    if ( arr[0] > arr[1]) return 0;
    // Last Element
    if ( arr[n - 1] > arr[ n - 2]) return n - 1;

    int low = 1 ;
    int high = n - 2;

    while ( low <= high)
    {
        int mid = ( low + high) / 2;

        if( arr[ mid ]> arr[ mid - 1 ] && arr[ mid ] > arr[ mid + 1] )
        {
            return mid;
        }

        if( arr[ mid ] > arr[ mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

    }
    return -1;
}

int main()
{
    vector<int> arr = {  1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 5 , 1 };
    int peakElement = findPeak( arr );
    cout << peakElement ;   
}