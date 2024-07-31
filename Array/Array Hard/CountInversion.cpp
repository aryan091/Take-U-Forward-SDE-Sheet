#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> arr , int low , int mid , int high)
{
    int cnt = 0;
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while ( left <= mid && right <= high)
    {
        if(arr[left] <= arr[right] )
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt+= mid - left + 1;
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    
    return cnt;
    
}

int MergeSort(vector<int> arr , int low , int high)
{
    int cnt = 0;
    if( low >= high)
    {
        return cnt;
    }

    int mid = ( low + high ) / 2;

    cnt+= MergeSort( arr , low , mid );
    cnt+= MergeSort( arr , mid + 1 , high );
    cnt+= merge( arr , low , mid , high);
    return cnt;
}
int countPairsOptimal(vector<int> arr , int n)
{
    return MergeSort(arr , 0 , n - 1);

    // TC - O(NlogN)
    // SC - O(1)
}

int countPairsBF(vector<int> arr , int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if( arr[i] > arr[j])
            {
                cnt++;
            }
        }
        
    }
    return cnt;

    // TC - O(N^2)
    // SC - O(1)
}

int main()
{
    vector<int> arr{ 5 , 4 ,3 , 2 , 1};
    int n = arr.size();
    int numOfPairsBF = countPairsBF(arr , n);
    int numOfPairsOptimal = countPairsOptimal(arr , n);
    cout << numOfPairsOptimal<<" "<< numOfPairsBF;

    return 0;
}