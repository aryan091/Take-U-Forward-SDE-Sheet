#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int longestCommonSubsequenceOptimal( vector<int> arr )
{
    int longest = 0;
    int n = arr.size();
    if(  n == 0) return 0;

    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    for ( auto it : st)
    {
        if( st.find( it  - 1) == st.end())
        {
            int cnt = 1;
            int x = it;

            while( st.find(it + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }

            longest = max(longest , cnt);

        }
    }
    
    return longest;
    
}
int longestCommonSubsequenceBetter( vector<int> arr )
{
    int longest = 1;
    int lastElement = INT_MIN;

    int curCount = 0;

    sort( arr.begin() , arr.end());
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if(arr[i] - 1 == lastElement)
        {
            curCount = curCount + 1;
            lastElement = arr[i];
        }
        else if(arr[i]!= lastElement)
        {
            curCount = 1;
            lastElement = arr[i];
        }

        longest = max(longest , curCount);

    }

    return longest;
    
}
bool ls(vector<int> arr , int target , int n)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            return true;
        }
    }

    return false;
    
}

int longestCommonSubsequenceBF( vector<int> arr)
{
    int longest = INT_MIN;

    int cnt = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        /* code */
        int x = arr[i];
        cnt = 1;
        while (ls(arr , x + 1 , n) == true)
        {
            x = x + 1;
            cnt = cnt + 1;
        }

        longest = max(cnt , longest);
        
    }
    
    return longest;

}
int main()
{
    vector<int> arr{ 100 , 1 , 102 ,4 , 3 , 103 , 2 , 1};

    int lcsBF = longestCommonSubsequenceBF( arr );
    cout << lcsBF << " ";

    int lcsBetter = longestCommonSubsequenceBetter( arr );
    cout << lcsBetter << " ";

    int lcsOptimal = longestCommonSubsequenceOptimal( arr );
    cout << lcsOptimal << " ";

    return 0;
}