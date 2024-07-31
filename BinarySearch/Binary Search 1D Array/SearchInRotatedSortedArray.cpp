#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray(vector<int>& arr, int target)
{
    int s = 0 , e = arr.size() - 1;

    while ( s <= e)
    {
        int mid = s + ( e - s )/ 2;

        // Check if mid element == target
        if( arr[mid] == target)
        {
            return mid;
        } 

        // Check for duplicate condition
        if( arr[s] == arr[mid] && arr[mid] == arr[e] )
        {
            s = s + 1;
            e = e - 1;
            continue;
        }
        // Check if left is sorted
        if ( arr[s] <= arr[mid] )
        {
            // Check if its present in s to mid area
            if( arr[s] <= target && target <= arr[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            
        }
        // Check if Right is sorted
        else
        {
            // Check if its present in s to mid area
            if( arr[mid] <= target && target <= arr[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
 
        }

    }

    return -1;
    
}

int main()
{
    vector<int> arr = {  3 , 3 , 1 , 3 , 3 , 3 , 3 };
    int ans1 = searchInRotatedSortedArray( arr , 1);
    int ans2 = searchInRotatedSortedArray( arr , 30);
    cout << ans1 << " " << ans2;
}