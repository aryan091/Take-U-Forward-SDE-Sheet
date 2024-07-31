#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maxElementFromRow(vector<vector<int>>& mat , int n , int m , int col)
{
    int maxEle = -1;
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if( mat[i][col] > maxEle)
        {
            maxEle = mat[i][col];
            index = i;
        }
    }

    return index;
    
}

vector<int> findPeakGrid(vector<vector<int>>& mat) 
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0 , high = m - 1;

    while ( low <= high)
    {
        int mid = ( high + low) / 2;
        int row = maxElementFromRow(mat , n , m , mid);
        int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;

        if(mat[row][mid] > left && mat[row][mid] > right)
        {
            return { row , mid};
        }
        else if( mat[row][mid] < left )
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return { -1 , -1};
}

int main()
{
    vector<vector<int>> matrix = {{10,20,15}, {21,30,14}, {7,16,32}};
    vector<int> ans = findPeakGrid(matrix);
    cout << ans[0] << " " << ans[1];
    return 0;
}