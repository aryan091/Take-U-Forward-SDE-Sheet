#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& arr, int target) 
{
    vector<vector<int>> ans;
    int n = arr.size();
    sort( arr.begin() , arr.end() );

    for (int i = 0; i < n; i++)
    {
        if( i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < n; j++)
        {
            if( j != i + 1 && arr[j] == arr[j - 1 ]) continue;

            int k = j + 1;
            int l = n - 1;

            while ( k < l)
            {
                int sum = arr[i];
                sum = sum + arr[j];
                sum = sum + arr[k];
                sum = sum + arr[l];

                if( sum < target)
                {
                    k++;
                }
                else if( sum > target)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = { arr[i] , arr[j] , arr[k] , arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    while( k < l && arr[k] == arr[k - 1]) k++;
                    while( k < l && arr[l] == arr[l + 1]) l--;
                }


            }
            
        }
    }

    return ans;

}
int main()
{
    vector<int> arr{1,0,-1,0,-2,2  };
    int target = 0;
    vector<vector<int>> ans = fourSum(arr , target);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }

}