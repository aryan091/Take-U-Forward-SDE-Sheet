#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> findUnionOptimal( int a[] , int b[] , int n1 , int n2)
{
    vector<int> unionArr;
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if( a[i] <= b[j])
        {
            if(unionArr.size()== 0 || unionArr.back()!= a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if(unionArr.size()== 0 || unionArr.back()!= b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    
    while (i < n1)
    {
        if(unionArr.size()== 0 || unionArr.back()!= a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
    }

    while ( j < n2)
    {
        if(unionArr.size()== 0 || unionArr.back()!= b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
    }
    
    

    return unionArr;

    // TC - O( N1 + N2)
    // SC - O( N1 + N2) || O(1)
}
vector<int> findUnionBF( int arr1[] , int arr2[] , int n1 , int n2)
{
    vector<int> unionArr;
    
    set<int> bucket;
    for (int i = 0; i < n1; i++)
    {
        bucket.insert(arr1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        bucket.insert(arr2[i]);
    }
    
    for( auto it : bucket)
    {
        unionArr.push_back(it);
    }

    return unionArr;

    // TC - O( N1logN) Where N is the size of set + O(N2logN) + O(N1 + N2)
    // SC - O(N1 + N2)
}
int main()
{
      int arr1[] = {1 , 1 , 2 , 3 , 5};
      int arr2[] = {2 , 3 , 4 , 4 , 5};
      int n1 = 5 , n2 = 5; 
      vector<int> unionArrBF = findUnionBF(arr1 , arr2 , n1 , n2);
      for (int i = 0; i < unionArrBF.size(); i++)
      {
        cout << unionArrBF[i] << " ";
      }
      cout << endl;
      vector<int> unionArrOptimal = findUnionOptimal(arr1 , arr2 , n1 , n2);
      for (int i = 0; i < unionArrOptimal.size(); i++)
      {
        cout << unionArrOptimal[i] << " ";
      }
      

}