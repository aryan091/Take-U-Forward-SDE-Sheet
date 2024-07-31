#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr , int target , int m) {
    int s = 0;
    int e = arr.size() - 1;
	int ans = m;
    
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

int findMaxRowOptimal(vector<vector<int>>& matrix , int n , int m)
{
    int maxInd = -1;
    int maxCol = -1;

    for (int i = 0; i < n; i++)
    {
        int intOne = m - lowerBound(matrix[i] , 1 , m);
        if(intOne > maxCol)
        {
            maxCol = intOne;
            maxInd = i;
        }
        
    }
    return maxInd;
}

int findMaxRowBF(vector<vector<int>>& matrix , int n , int m)
{
    int maxInd = -1;
    int maxCol = -1;

    for (int i = 0; i < n; i++)
    {
        int intOne = 0;
        for (int j = 0; j < m ; j++)
        {
            intOne+=matrix[i][j];
        }
        if(intOne > maxCol)
        {
            maxCol = intOne;
            maxInd = i;
        }
        
    }
    return maxInd;
}

int main()
{

    vector<vector<int>> matrix = {{0, 0, 0}, {0, 0, 1}, {1, 1, 1}};
    int n = 3, m = 3;
    cout << findMaxRowBF(matrix , n , m)<<endl;
    cout << findMaxRowOptimal(matrix , n , m)<<endl;
    return 0;
}