#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findMissingNumOptimal( vector<int>& arr , int k)
{
    int n = arr.size();
    int l = 0;
    int h = n - 1;

    while ( l <= h )
    {
        int mid = ( l + h) / 2;
        int missing = arr[mid] - ( mid + 1);

        if( missing < k)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }

    }
    return k + h + 1;
}

int findMissingNumBF( vector<int>& arr , int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if( arr[i] <= k)
        {
            k++;
        }
        else
        {
            return k;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = { 2 , 3, 4 , 7 , 11};
    int k = 5;
    int missingNumBF = findMissingNumBF( arr , k);
    cout << missingNumBF<<" ";

    int missingNumOptimal = findMissingNumOptimal( arr , k);
    cout << missingNumOptimal;

    return 0;
}