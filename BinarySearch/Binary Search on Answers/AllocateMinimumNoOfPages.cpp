#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> getRange(int A[], int N, int M)
    {
        vector<int> ans;
        int maxi = INT_MIN;
        int sum = 0;
        
        for( int i = 0 ; i < N ; i++ )
        {
            maxi = max( A[i] , maxi);
            sum = sum + A[i];
        }
        
        ans.push_back(maxi);
        ans.push_back(sum);
        
        return ans;
        
    }
    int canAllocateBooks(int A[], int N, int M , int minPages)
    {
        int noOfStudent = 1; 
        int pageAllocated = 0;
        
        for( int i = 0 ; i< N ; i++)
        {
            if(pageAllocated + A[i] <= minPages)
            {
              pageAllocated = pageAllocated + A[i]; 
            }
            else
            {
              noOfStudent++;
              pageAllocated = A[i]; 
            }
        }
        
        return noOfStudent;
        
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        if( M > N)
        {
            return -1;
        }
        int ans = INT_MIN;
        vector<int> range = getRange(A, N ,M);
        int l = range[0];
        int h = range[1];
        
        
        
        while( l <= h)
        {
            int mid = l + ( h - l ) / 2;
            int student = canAllocateBooks( A , N , M , mid);
            
            if (student > M) {
            l = mid + 1;
        }
        else {
            ans = mid;
            h = mid - 1;
        }
    }
        return ans;
    }

    int main()
    {
        int N = 4;
        int A[] = {12,34,67,90};
        int M = 2;

        int minPages = findPages(A , N, M);
        cout << minPages;

        return 0;
    }