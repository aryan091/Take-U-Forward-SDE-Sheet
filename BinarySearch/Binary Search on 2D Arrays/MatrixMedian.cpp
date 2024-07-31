#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr  , int target , int m) {
    int s = 0;
    int e = arr.size() - 1;
	int ans = m;
    
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

int countSmallEqual(vector<vector<int>> &matrix , int n , int m , int x)
{
    int cnt = 0 ;
    for (int i = 0; i < n; i++)
    {
        cnt += upperBound(matrix[i] , x  , m);
    }    
    return cnt;
}

int median(vector<vector<int>> &matrix, int R, int C)
{
    int n = matrix.size();
    int m = matrix[0].size();
  
    int low = 1 , high = 1e9;
    int required = ( n * m ) / 2;

    while (low <= high)
    {
        int mid = ( low + high ) / 2;
        int smallEqual = countSmallEqual(matrix , n , m , mid);
        if(smallEqual <= required)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return low;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 8},
                             {2, 3, 4},
                             {1, 2, 5}};

    int ans = median(matrix,3,3);
    cout << ans;
    return 0;
}