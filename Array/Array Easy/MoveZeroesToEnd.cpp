#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void move0toleftOptimal(vector<int> &arr)
{
    int n = arr.size();
    int j = -1  , i = 0;
    for ( ; i < n; i++)
    {
        if(arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    
    for ( i = j + 1; i < n; i++)
    {
        if( arr[i] !=  0)
        {
            swap(arr[i] , arr[j]);
            j++;
        }
    }
    
    
}
void move0toleftBF(vector<int> &arr)
{
    // Step 1 : Create a temp vector and store non zero values in it.
    vector<int> temp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if( arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    // Step 2 : Add values back from Temp to Original Array.
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    

    // Step 3 : Add remaining zeroes in Original Array.
    int tempSize = temp.size();
    for (int i = tempSize; i < n; i++)
    {
        arr[i] = 0;
    }
    
    // TC - O(N) + O(N) + O(N - N) = O(2N)
    // SC - O(N) 
    
}
int main()
{

    vector<int> arr{ 1 , 0 , 2 , 3 , 2 , 0 , 0 , 4 , 5 , 1};
    // move0toleftBF(arr);
    move0toleftOptimal(arr);
    for( auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}