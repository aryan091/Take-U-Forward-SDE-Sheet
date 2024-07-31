
\



#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findMissingOptimalXOROnePass(vector<int> arr , int n)
{
    int xor1 = 0 , xor2 = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ ( i + 1);
    }
    xor1 = xor1 ^ n;
    
    return xor1 ^ xor2;

    // TC - O(N) 
    // SC - O(1)
}

int findMissingOptimalXORTwoPass(vector<int> arr , int n)
{
    int xor1 = 0 , xor2 = 0;
    for (int i = 1; i <= n; i++)
    {
        xor1 = xor1 ^ i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i];
    }
    
    return xor1 ^ xor2;

    // TC - O(N) + O(N) = O(2N)
    // SC - O(1)
}

int findMissingBetter(vector<int> arr , int n)
{
    int sumSoFar = 0;
    int sumByFormula = n * ( n + 1) / 2;

    for (int i = 0; i < n - 1; i++)
    {
        sumSoFar = sumSoFar + arr[i];
    }
    
    return sumByFormula - sumSoFar;

    // TC - O(N)
    // SC - O(1)
    
}

int findMissingBF(vector<int> arr , int n)
{
    int flag ;
    for (int i = 1; i <= n; i++)
    {
        flag = 0;
        for (int j = 0; j < n-1; j++)
        {
            if(arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            return i;
        }
        
    }

    return -1;

    // TC - O(N^2)
    // SC - O(1)
    
}



int main()
{

    vector<int> arr{ 1 , 2 , 3 ,5 , 6 };
    int n = 6;

    int missingNoBF = findMissingBF(arr , n);
    cout << missingNoBF << " ";

    int missingBetter = findMissingBetter(arr , n);
    cout << missingBetter << " ";

    int missingNumberOptimal1 = findMissingOptimalXORTwoPass(arr , n);
    cout << missingNumberOptimal1<< " ";

    int missingNumberOptimal2 = findMissingOptimalXOROnePass(arr , n);
    cout << missingNumberOptimal2;

    return 0;
}