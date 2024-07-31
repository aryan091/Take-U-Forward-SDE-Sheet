#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSumOptimal(vector<int> arr, int target)
{
    int n = arr.size();
    sort( arr.begin() , arr.end());
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++)
    {
        if( i > 0 && arr[i] == arr[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;

        while ( j  <  k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if( sum < 0)
            {
                j++;
            }
            else if( sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);

                j++;
                k--;

                while( j < k && arr[j] == arr[j - 1]) j++;
                while( j < k && arr[k] == arr[k + 1]) k--;
            }
        }
        
    }

    return ans;

    // TC - O(NLogN) * O(N*N) ---> Sort and Travesing  
    // SC - O(1)

}
vector<vector<int>> threeSumBetter(vector<int> arr, int target)
{
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {

            int third = -(arr[i] + arr[j]);

            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans{st.begin(), st.end()};
    return ans;

    // TC - O(N^2) * O(log (No of unique triplets)) ---> travesing and Insertion in Set 
    // SC - O(No of unique triplets) * 2 + O(N)

}

vector<vector<int>> threeSumBF(vector<int> arr, int target)
{
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans{st.begin(), st.end()};
    return ans;

    // TC - O(N^3) * O(log (No of unique triplets)) ---> travesing and Insertion in Set 
    // SC - O(No of unique triplets)

}

int main()
{
    vector<int> arr{-1, 0, 1, 2, -1, -4};
    int target = 0;

    // vector<vector<int>> ans = threeSumBF( arr , target);

    // vector<vector<int>> ans = threeSumBetter(arr, target);

    vector<vector<int>> ans = threeSumOptimal(arr, target);

    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}