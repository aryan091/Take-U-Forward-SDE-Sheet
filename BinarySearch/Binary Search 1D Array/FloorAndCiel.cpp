#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int floor( vector<int>& arr, int target )
{
    int s = 0;
    int e = arr.size() - 1;
	int ans = -1;
    
    while (s<=e)
    {
        int mid = s+(e-s)/2;
        
        if (arr[mid] <= target)
        {
			ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        
       // mid = s+(e-s)/2;
    }
    
    return arr[ans];
}

int ceil( vector<int>& arr, int target )
{
    int s = 0;
    int e = arr.size() - 1;
	int ans = -1;
    
    while (s<=e)
    {
        int mid = s+(e-s)/2;
        
        if (arr[mid] >= target)
        {
			ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        
       // mid = s+(e-s)/2;
    }
    
    return arr[ans];
}

int main()
{
    vector<int> arr = { 1 , 3 , 5 , 9 , 14 , 16 , 18};
    int ans1 = floor( arr , 15);
    int ans2 = ceil( arr , 15);
    cout << ans1 << " " << ans2;
}