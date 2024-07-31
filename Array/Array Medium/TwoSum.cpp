#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> ans;
        map< int , int > ds;
        for( int i = 0; i < n ; i++)
        {
            int a = nums[i];
            int more = target - a;
            if( ds.find(more) != ds.end())
            {
                ans.push_back(ds[more]);
                ans.push_back(i);
                return ans;
            }

            ds[a] = i;
        }

        return ans;

        // TC - O(N) MAP WORST CASE - O(logN)
        // SC - O(N)
    }

int main()
{
vector<int> arr{ 2,7,11,15};
int target = 9;
vector<int> ans = twoSum(arr , target);
for(auto it : ans)
{
    cout << it << " ";
}
}