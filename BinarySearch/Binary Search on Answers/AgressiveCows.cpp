#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
    bool canPlaceCows(vector<int> &stalls , int cows , int minDist)
    {
        int n = stalls.size();
        
        int cowCount = 1;
        int lastCoordinate = stalls[0];
        
        for( int i = 1 ; i < n ; i++)
        {
            if( stalls[i] - lastCoordinate >= minDist)
            {
                cowCount++;
                lastCoordinate = stalls[i];
            }
            
            if( cowCount == cows)
            {
                return true;
            }
        }
        return false;
    }

    int getMinDist( vector<int> &stalls , int k , int n) {
    
        // Write your code 
        sort(stalls.begin() , stalls.end());
        
        int l = 1;
        int h = stalls[ n - 1 ] - stalls[ 0 ];
        int ans = INT_MIN;
        
        while( l<= h )
        {
            int mid = l + (h - l ) / 2;
            if(canPlaceCows( stalls , k , mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
            
        }
        return ans;
        
    }

int main()
{
    vector<int> coordinates = { 1 , 2 , 4 , 8 , 9};
    int cows = 3;
    int minDist = getMinDist( coordinates , cows , 5);
    cout << minDist;
    return 0;
}