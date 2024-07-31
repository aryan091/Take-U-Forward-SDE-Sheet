#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& a) {
        int size = a.size();
         int count = 0;
        int el;
        for( int i = 0 ; i < size ; i++ )
        {
            if( count == 0)
            {
                el = a[i];
                count  = 1;
            }
            else if( a[i] == el)
            {
                count++;
            }
            else
            {
                count--;
            }

            
        }
        
        return el;
    }
int main()
{
    vector<int> arr{ 2,2,1,1,1,2,2};
    int ans = majorityElement(arr );
    cout << ans;
}