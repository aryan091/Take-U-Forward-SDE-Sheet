#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int kthElement(int nums1[], int nums2[], int n1, int n2, int k)
    {

    if( n1 > n2)
    {
        return kthElement(nums2 , nums1,n2,n1,k);
    }

    int te = n1 + n2;
    int low = max(0 , k - n2 );
    int high = min( k ,n1);


    while (low <= high)
    {
        int mid1 = ( low + high ) >> 1;
        int mid2 = k - mid1;

        int l1 = INT_MIN , l2 = INT_MIN;
        int r1 = INT_MAX , r2 = INT_MAX;

        if( mid1 < n1 ) r1 = nums1[mid1];
        if( mid2 < n2 ) r2 = nums2[mid2];
        if( mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if( mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        if( l1 <= r2 && l2<= r1)
        {
                return max( l1 , l2);
            
        } 
        else if ( l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    
    return 0;

    }

int main()
{
    int array1[] = {2,3,6,7,9};
    int array2[] = {1,4,8,10};
    int m = sizeof(array1)/sizeof(array1[0]);
    int n = sizeof(array2)/sizeof(array2[0]);
    int k = 5;
    cout<<kthElement(array1,array2,m,n,k);
    return 0;
}