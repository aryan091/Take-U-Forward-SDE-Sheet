#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingandRepeating( vector<int> arr , int n)
{
    long long SN = (n * ( n + 1)) / 2;
    long long S2N = ( n * ( n + 1) * (2 * n + 1))/6;

    long long S = 0;
    long long S2 = 0;

    for (int i = 0; i < n; i++)
    {
        S+= (long long)arr[i];
        S2+= (long long)arr[i] * (long long)arr[i];
    }
    
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2/val1;

    long long x = ( val1 + val2 ) / 2;
    long long y = x - val1;

    return {(int)x  , (int)y};

    
}

int main()
{
    vector<int> arr{ 3, 1 ,2 ,5 ,4 ,6 ,7 ,5};
    int n = arr.size();
    vector<int> ans = findMissingandRepeating( arr , n);
    for( auto it : ans)
    {
        cout << it<<" ";
    }
    return 0;
}