#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findMax( vector<int>& piles )
{
    int maxi = INT_MIN;
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        if( piles[i] > maxi)
        {
            maxi = piles[i];
        }
    }

    return maxi;
    
}

int calculateTotalHours( vector<int>& piles , int hourlySpeed)
{
    int totalHours = 0;
    int n = piles.size();

    for (int i = 0; i < n; i++)
    {
        totalHours += ceil( (double)(piles[i]) / (double)hourlySpeed);
    }

    return totalHours;
    

}

int minimumRateToEatBananas( vector<int>& piles , int hours )
{
    int maxi = findMax( piles );
    
    for (int speed = 1; speed <= maxi; speed++)
    {
        int requiredTime  = calculateTotalHours( piles , speed );
        if( requiredTime <= hours)
        {
            return speed;
        }
    }
    
    return maxi;
}

int minimumRateToEatBananasBS( vector<int>& piles , int hours )
{
    int low = 1 , high = findMax( piles );
    int ans = INT_MIN;

    while ( low <= high)
    {
        int mid = low + ( high - low ) / 2 ;
        int totalH = calculateTotalHours(piles , mid);

        if( totalH <= hours)
        {
            // Return the minimum integer k such that she can eat all the bananas within h hours
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

    }
    
    return ans;
}

int main()
{
    vector<int> arr = {  3 , 6 , 7 , 11 };
    int h = 8;
    int miniSpeed = minimumRateToEatBananasBS( arr , h );
    cout << miniSpeed;
    return 0;
}