#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> overlappedIntervalOptimal(vector<vector<int>>& intervals)
{
    
    int n =intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin() , intervals.end());

    for (int i = 0; i < n; i++)
    {
        if( ans.size() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1] , intervals[i][1] );
        }
    }

    return ans;
}

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin() , intervals.end());

    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if( !ans.empty() && end <= ans.back()[1] ) continue;

        for (int j =  i + 1; j < n; j++)
        {
            if( intervals[j][0] <= end)
            {
                end = max(end , intervals[j][1]);
            } 
            else
            {
                break;
            }
        }
        
        ans.push_back({start , end});
        
    }
    
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1,3},{2,4},{6,8},{9,10}};
    vector<vector<int>> ansBf = overlappedInterval(arr);
    // for( auto it : ansBf)
    // {
    //     cout<< "(" << it[0] << " " << it[1] << ")"<<endl;
    // }
    vector<vector<int>> ansOptimql = overlappedIntervalOptimal(arr);
    for( auto it : ansOptimql)
    {
        cout<< "(" << it[0] << " " << it[1] << ")"<<endl;
    }
    return 0;
}