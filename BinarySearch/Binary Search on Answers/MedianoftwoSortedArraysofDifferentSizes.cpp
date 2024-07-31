#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArraysOptimal(vector<int>& nums1, vector<int>& nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    if( n1 > n2)
    {
        return findMedianSortedArraysOptimal(nums2 , nums1);
    }

    int te = n1 + n2;
    int low = 0;
    int high = n1;
    int left = ( te + 1) / 2;

    while (low <= high)
    {
        int mid1 = ( low + high ) >> 1;
        int mid2 = left - mid1;

        int l1 = INT_MIN , l2 = INT_MIN;
        int r1 = INT_MAX , r2 = INT_MAX;

        if( mid1 < n1 ) r1 = nums1[mid1];
        if( mid2 < n2 ) r2 = nums2[mid2];
        if( mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if( mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        if( l1 <= r2 && l2<= r1)
        {
            if( te % 2 == 1)
            {
                return max( l1 , l2);
            }
            else
            {
                return ((double)(max( l1 , l2) + min(r1 , r2)))/ 2.0;
            }
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


double findMedianSortedArraysBetter(vector<int>& nums1, vector<int>& nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int N = n + m ;
    int i = 0, j = 0 ;

    int cnt = 0;
    
    int ind2 = N / 2;
    int ind1 = ind2 - 1;

    int ind1el = -1 , ind2el = -1;

    while (i < n  && j < m )
    {
        if( nums1[i] < nums2[j] )
        {
            if( cnt == ind1) ind1el = nums1[i];
            if( cnt == ind2) ind2el = nums1[i];
            i++;
            cnt++;
        }
        else 
        {
            if( cnt == ind1) ind1el = nums2[j];
            if( cnt == ind2) ind2el = nums2[j];
            j++;
            cnt++;
        }
        
    }

    while ( i < n)
    {
        if( cnt == ind1) ind1el = nums1[i];
            if( cnt == ind2) ind2el = nums1[i];
            i++;
            cnt++;
    }

    while (j < m)
    {
       if( cnt == ind1) ind1el = nums2[j];
            if( cnt == ind2) ind2el = nums2[j];
            j++;
            cnt++;
    }
    
    
    if (N % 2 == 1) {
         return (double) ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
    
    
    // TC - O( N1 + N2)
    // SC - O(1)
}

double findMedianSortedArraysBF(vector<int>& nums1, vector<int>& nums2) 
{
    int n = nums1.size();
    int m = nums2.size();
    vector<int> nums3( n + m , 0);
    int i = 0, j = 0 , k = 0;
    while (i < n  && j < m )
    {
        if( nums1[i] < nums2[j] )
        {
            nums3[k] = nums1[i];
            i++;
            k++;
        }
        else if( nums1[i] > nums2[j] )
        {
            nums3[k] = nums2[j];
            j++;
            k++;
        }
        else
        {
            nums3[k] = nums1[i];
            i++;
            j++;
            k++;
        }
    }

    while ( i < n)
    {
        nums3[k] = nums1[i];
            i++;
            k++;
    }

    while (j < m)
    {
       nums3[k] = nums2[j];
            j++;
            k++;
    }
    
    int N = n + m;
    if (n % 2 == 1) {
        return (double)nums3[N / 2];
    }

    double median = ((double)nums3[N / 2] + (double)nums3[(N / 2) - 1]) / 2.0;
    return median;
    
    // TC - O( N1 + N2)
    // SC - O( N1 + N2)
    
}

int main()
{
    vector<int> nums1 = { 1, 4, 7, 10, 12};
    vector<int> nums2 = { 2, 3, 6, 15};

    double medianBF = findMedianSortedArraysBF( nums1 , nums2);
    cout<< medianBF<<" ";
    // In Better -> We will try to optimize Space 
    double medianBetter = findMedianSortedArraysBetter( nums1 , nums2);
    cout<< medianBetter<<" ";

    double medianOptimal = findMedianSortedArraysOptimal( nums1 , nums2);
    cout<< medianOptimal;


    return 0;
}