#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> findMinMax(vector<int> &arr)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        mini = min(arr[i], mini);
        maxi = max(arr[i], maxi);
    }

    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);

    return ans;
}

int makeBouquets(vector<int> &bloomDay, int day, int flower)
{
    int n = bloomDay.size();
    int cntConsFlowers = 0;
    int numOfBuckets = 0;
    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= day)
        {
            cntConsFlowers++;
        }
        else
        {
            numOfBuckets += (cntConsFlowers / flower);
            cntConsFlowers = 0;
        }
    }
    numOfBuckets = numOfBuckets + (cntConsFlowers / flower);

    return numOfBuckets;
}

int minDays(vector<int> &bloomDay, int m, int k)
{


    int n = bloomDay.size();

    // Case 1 : if m and k have small value we can multiply it directly.

    // if (m * k > n)
    // {
    //     return -1;
    // }

    // Case 2

    // If we see the constraints are
    // 1 <= m <= 10^6
    // 1 <= k <= 10^5

    // Suppose k and m have their max values if we mupltiply it the int datatype can overflow.
    // So we will use long long datatype to avoid overflow issues
    // long long can store nearly 10 ^ 18 n from above contraints we can get max of 10^11.

    long long val = m * 1ll * k * 1ll;

    if( val > n)
    {
        return -1;
    }


    vector<int> minmax = findMinMax(bloomDay);
    int low = minmax[0];
    int high = minmax[1];
    int ans = INT_MIN;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int noOfBouquets = makeBouquets(bloomDay, mid, k);
        if (noOfBouquets >= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> bloomDay = { 1 , 10 , 3 , 10 , 2};
    int m = 3 , k = 1;
    int minDay = minDays(bloomDay , m , k);
    cout << minDay;
    return 0;

}