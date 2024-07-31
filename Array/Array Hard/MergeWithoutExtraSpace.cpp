#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if(arr1[left] > arr2[right])
        {
            swap(arr1[left] , arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1 , arr1 + n);
    sort(arr2 , arr2 + m);
    
} 
int main()
{

    int n = 4;
    long long arr1[] = {1, 3, 5, 7}; 
    int m = 5;
    long long arr2[] = {0, 2, 6, 8, 9};
    merge(arr1 , arr2 , n , m);
    return 0;

    for(auto it : arr1)
    {
        cout << it << " ";
    }

    cout << endl;

    for(auto it : arr2)
    {
        cout << it << " ";
    }
}