#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        vector<int> ls;
        int cnt1 = 0, cnt2 = 0 , el1 = INT_MIN , el2 = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if(cnt1 == 0 && el2 != nums[i])
            {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2==0 && el1 != nums[i])
            {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i])
            {
                cnt1++;
            }
            else if(el2 == nums[i])
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        int mini = ( n / 3) + 1;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == el1) cnt1++;
            if(nums[i] == el2) cnt2++;
        }

        if(cnt1 >= mini) ls.push_back(el1);
        if(cnt2 >= mini) ls.push_back(el2);


        return ls;
    }
int main()
{
vector<int> arr{ 1,1,1,2,3,7,8,1,6,9};
vector<int> ans = majorityElement(arr );
for(auto it : ans)
{
    cout << it << " ";
}
}