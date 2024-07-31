#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr , int target) {
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
    
    return ans; 
    }

int upperBound(vector<int>& arr  , int target) {
    int s = 0;
    int e = arr.size() - 1;
	int ans = -1;
    
    while (s<=e)
    {
        int mid = s+(e-s)/2;
        
        if (arr[mid] > target)
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
    
    return ans; 
    }


int main()
{
    vector<int> arr = { 5,7,8,8,8,10 };
    int target = 8;
    int first = lowerBound( arr , target);

        // CASE 1

        // When first will be -1 ?
        // When we dont find any element >= target

        // CASE 2

        // When first not be != target ?
        // When target is not present in array it never be == to target

        // If any of the case CASE1 or ( || ) CASE2 holds true i.e. we are not able to find element


        if( first == -1 || arr[first] != target ) 
        {
            cout << " " <<  -1 << " "<< -1;
            exit;
        }
        else
        {
            int last = upperBound( arr , target) - 1;
            cout << first << " " << last<< endl;
            cout << last - first + 1;
        }

        
        
}