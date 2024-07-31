#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findNonDuplicate(vector<int>& arr)
{
    int n = arr.size();
    
    if( n == 1) return arr[0];

    if( arr[0] != arr[1] ) return arr[0];
    if( arr[ n - 1 ] != arr[ n - 2 ] ) return arr[ n - 1 ];

    int s = 1;
    int e = n - 2;

    while ( s <= e)
    {
        int mid = (s + e) / 2;
        
        if( arr[mid] != arr[ mid + 1] && arr[mid] != arr[ mid - 1])
        {
            return arr[mid];
        }
        
        if( ( mid % 2 == 1 && arr[mid] == arr[mid - 1] ) ||
         ( mid % 2 == 0 && arr[mid] == arr[mid + 1]) )
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        
    }
    
return -1;

}

int main()
{
    vector<int> arr = { 1 , 1 , 2 , 2 , 3 , 3 , 4 , 5 , 5 , 6 , 6};
    int ans= findNonDuplicate( arr );
    cout << ans;
    return 0;
}