#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeArrayOptimal(vector<int> &arr)
{
    int n = arr.size();

    vector<int> ans;

    int pos = 0;
    int neg = 1;

    for (int i = 0; i < n; i++)
    {
        if( arr[i] > 0)
        {
            ans[pos] = arr[i];
            pos = pos + 2;
        }
        else
        {
            ans[neg] = arr[i];
            neg = neg + 2;
        }
    }

    return ans;

    // TC - O(N)
    // SC - O(1)


}
vector<int> rearrangeArrayBF(vector<int> &arr)
{

    int n = arr.size();

    vector<int> pos;
    vector<int> neg;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        ans[2 * i] = pos[i];
        ans[2 * i + 1] = neg[i];
    }

    return ans;

    // TC - O(N) + O(N / 2)
    // SC - O(N / 2) + O(N / 2) = O(N)
}
int main()
{
    vector<int> arr{3, 1, -2, -5, 2, -4};
    vector<int> ansBF = rearrangeArrayBF(arr);

    for (auto it : ansBF)
    {
        cout << it << " ";
    }

    cout << endl;

    vector<int> ansOptimal = rearrangeArrayOptimal(arr);

    for (auto it : ansOptimal)
    {
        cout << it << " ";
    }

    return 0;
}