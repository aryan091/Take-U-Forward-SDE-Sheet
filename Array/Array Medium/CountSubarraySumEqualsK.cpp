#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int countSubArrayBetter(vector<int> arr , int k)
{
    int n = arr.size();
    map<int , int> mpp;
    int sum = 0;
    int cnt = 0;

    mpp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        int remove = sum - k;

        cnt = cnt + mpp[remove];

        mpp[sum] = mpp[sum] + 1;
    }
    
    

    return cnt;
    
}

int countSubArrayBF(vector<int> arr , int k)
{
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n ; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];

            if( sum == k)
            {
                cnt++;
            }
        }
        
    }
    
    return cnt;
}

int main()
{
    vector<int> arr{ 1 , 2 , 3 , -3 , 1 ,1 ,1, 4 , 2 ,-3  };
    int k = 3;
   // int maxLengthBF = countSubArrayBF( arr , k);
    //cout << maxLengthBF<<" ";

    int maxLengthBetter = countSubArrayBetter( arr , k);
    cout << maxLengthBetter<<" ";

   
    return 0;
}