#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findLongestSubArrayOptimal(vector<int> arr , int target)
{
    int n = arr.size();
    int sum = arr[0] , maxLen = 0;

    int right = 0, left = 0;
    while ( right < n)
    {
        while ( left <= right && sum > target)
        {
            sum = sum - arr[left];
            left++;
        }

        if( sum == target)
        {
            maxLen = max(maxLen , right - left + 1);
        }
        
        right++;
        if( right < n) sum = sum + arr[right];
    }

    return maxLen;

    // TC - O(2N)
    // SC - O(1)
    
}
int findLongestSubArrayBetter(vector<int> arr , int target)
{
    map<int , int> preSum;
    int n = arr.size();
    int sum = 0 , maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if( sum == target)
        {
            maxLen = max(maxLen , i + 1);
        }


        int rem =  sum - target;
        if(preSum.find(rem) != preSum.end())
        {
            int len = i - preSum[rem];
            maxLen = max(maxLen , len);
        }

        if( preSum.find(sum) == preSum.end())
        {
            preSum[sum] = i;
        }

    }

    
    return maxLen;

    // TC - O(N)
    // SC - O(N)

    // Note : This method wont work for postivies and negative
    // Dry run for arr{ 2 , 0 , 0 , 3} and k = 3 
    // But if we put this condition it will work
    // if( preSum.find(sum) == preSum.end()){ preSum[sum] = i;}
    // We are only adding when there is no sum present 
    // We are not updating current sum


    // After this comdition Hashmap contains |  5 , 3  | 5 - 3 == 3 which is K 3 - 0 = 3 Length 
    //                                       |  2 , 0  |
    //                                       ___________

}
int findLongestSubArrayBF( vector<int> arr , int target)
{
    int n = arr.size();
    int sum = 0 , maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n;j++)
        {
            sum = sum + arr[j];
            
            if( sum == target)
            {
                maxLen = max( maxLen , j - i + 1);
            }

        }
        
    }
    
    return maxLen;

    // TC - O(N^2)
    // SC - O(1)
}

int main()
{
    vector<int> arr{ 10, 5, 2, 7, 1, 9 };
    int k = 15;
    int maxLengthBF = findLongestSubArrayBF( arr , k);
    cout << maxLengthBF<<" ";

    int maxLengthBetter = findLongestSubArrayBetter( arr , k);
    cout << maxLengthBetter<<" ";

    int maxLengthOptimal = findLongestSubArrayOptimal( arr , k);
    cout << maxLengthOptimal<<" ";

    return 0;
}