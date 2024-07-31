#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int searchMinimum(vector<int>& arr)
{
    int s = 0;
    int e = arr.size() - 1;

    int ans = INT_MAX;

    while ( s <= e )
    {
        int mid = s + ( e - s)/ 2;

        if( arr[s] <= arr[mid])
        {
            ans = min( ans , arr[s]);
            s = mid + 1;
        }
        else
        {
            ans = min( ans , arr[mid]);
            e = mid - 1;
        }
    
    }
    return ans;
}

int main()
{
    vector<int> arr = { 4 , 5 , 6 ,7  , 2 , 3};
    int ans1 = searchMinimum( arr );
    cout << ans1 ;
    return 0;
}