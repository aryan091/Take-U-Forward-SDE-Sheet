#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int binarySearch( vector<int> arr , int target )
{
    int ans = -1;
    int s = 0;
    int e = arr.size() - 1;

    while ( s <= e)
    {
        int mid = ( s + e) / 2;

        if( arr[mid] == target)
        {
            ans = mid;
            return ans;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    
    return ans;
}

int main()
{
    vector<int> arr = { 1 , 3 , 5 , 9 , 14 , 16 , 18};
    int ans1 = binarySearch( arr , 14);
    int ans2 = binarySearch( arr , 15);
    cout << ans1 << " " << ans2;
}