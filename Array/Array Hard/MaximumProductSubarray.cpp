#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int getMaxProd(vector<int> &nums, int n)
{
    int pre = 1, suf = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;

        pre *= nums[i];
        suf *= nums[n - i - 1];

        maxi = max(maxi, max(pre, suf));
    }
    return maxi;

    // TC - O(N)
    // SC - O(1)

}

int main()
{
    vector<int> arr{1, 2, -3, 0, -4, -5};
    int n = arr.size();

    int maxProd = getMaxProd(arr, n);
    cout << maxProd;

    return 0;
}