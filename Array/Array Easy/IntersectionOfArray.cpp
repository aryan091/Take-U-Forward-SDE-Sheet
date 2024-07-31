#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> findIntersectionOptimal(int a[] , int b[] , int n1 , int n2)
{
    vector<int> intersect;
    int i = 0 ;
    int j = 0;

    while ( i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            i++;
        }
        else if( b[j] < a[i])
        {
            j++;
        }
        else
        {
            intersect.push_back(a[i]);
            i++;
            j++;
        }
    }

    return intersect;

    // TC - O(N1 + N2)
   // SC - O(N2)
}
vector<int> findIntersectionBF(int a[] , int b[] , int n1 , int n2)
{
   vector<int> vis(n2);
   vector<int> intersect;
   for (int i = 0; i < n2; i++)
   {
     vis.push_back(0);
   }

   for (int i = 0; i < n1; i++)
   {
        for (int j = 0; j< n2; j++)
        {
            if( a[i] == b[j] && vis[j] == 0)
            {
                intersect.push_back(a[i]);
                vis[j] = 1;
                break;
            }

            if( b[j] > a[i])
            {
                break;
            }
        }
        
        
   }
   
   return intersect;

   // TC - O(N1 X N2)
   // SC - O(N2) 
    
}
int main()
{

    int arr1[] = {  1 ,2 ,2 ,3 ,3 ,4 ,5 ,6};
    int n1 = 8;
    int arr2[] ={2 , 3, 3, 5, 6, 6, 7 };
    int n2 =7;

    vector<int> intersectionBF = findIntersectionBF(arr1 , arr2 , n1 , n2);
    for (int i = 0; i < intersectionBF.size(); i++)
      {
        cout << intersectionBF[i] << " ";
      }

    cout << endl;
    vector<int> intersectionOptimal = findIntersectionOptimal(arr1 , arr2 , n1 , n2);
    for (int i = 0; i < intersectionOptimal.size(); i++)
      {
        cout << intersectionOptimal[i] << " ";
      }

    return 0;
}