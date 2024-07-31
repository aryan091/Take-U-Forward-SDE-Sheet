#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maximumSubarrayFollowUp(vector<int> arr)
{
    int maxi = INT_MIN;
    int n = arr.size();


    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if( sum > maxi)
        {
            maxi = sum;
        }

        if(sum < 0)
        {
            sum = 0;
        }

    }
    
    return maxi;
}

int maximumSubarrayOptimal(vector<int> arr)
{
    int maxi = INT_MIN;
    int n = arr.size();

    int start = 0 , ansStart = -1 , ansEnd = -1;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if( sum == 0) start = i;
        sum = sum + arr[i];
        if( sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0)
        {
            sum = 0;
        }

    }
    

    cout << endl;

    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    

    cout << endl;
    return maxi;

}

int maximumSubarrayBetter(vector<int> arr)
{
    int maxi = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if (sum > maxi)
            {
                maxi = sum;
            }
        }
    }

    return maxi;

    // TC - O(N^2)
    // SC - O(1)
}

int maximumSubarrayBF(vector<int> arr)
{
    int maxi = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {

                sum = sum + arr[k];
            }

            if (sum > maxi)
            {
                maxi = sum;
            }
        }
    }

    return maxi;

    // TC - O(N^3)
    // SC - O(1)
}
int main()
{
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int lcsBF = maximumSubarrayBF(arr);
    cout << lcsBF << " ";

    int lcsBetter = maximumSubarrayBetter(arr);
    cout << lcsBetter << " ";

    int lcsOptimal = maximumSubarrayOptimal( arr );
    cout << lcsOptimal << " ";

    int followUp = maximumSubarrayFollowUp(arr);
    cout << followUp;
    return 0;
}