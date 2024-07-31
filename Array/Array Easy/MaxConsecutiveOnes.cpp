#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int consecutiveOnes( vector<int> arr )
{
    int n = arr.size();
    int count = 0 , maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        
        if( arr[i] == 1)
        {
            
            count++;
            maxLen = max( maxLen , count);
        }
        else
        {
            count = 0;
        }
    }
    
    
    return maxLen;
}

int main()
{

    vector<int> arr{1, 1,  0, 1 ,1,1};
    int count1 = consecutiveOnes(arr);
    cout << count1<< " ";
    return 0;
}