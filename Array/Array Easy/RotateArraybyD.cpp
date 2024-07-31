#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &arr, int s, int e)
{
    while (s<=e)
    {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
    
}

void rotateOptimal(vector<int> &arr, int k, int n)
{
    k = k % n;

    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k , arr.begin()+n);
    reverse(arr.begin() , arr.begin()+n);

    // TC - O(K) + O(N - K) + O(K)
    // SC - O(1)

}

void rotateBF(vector<int> &arr, int k, int n)
{
    vector<int> temp;
    k = k % n;

    int i = 0;
    for (; i < k; i++)
    {
        temp.push_back(arr[i]);
    }

    for (; i < n; i++)
    {
        arr[i - k] = arr[i];
    }

    int index = 0;
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[index];
        index++;
    }

    // TC - O(K) + O(N - K) + O( K )
    // SC - O(K)

    // Interviewer
    // Q->   Can you reduce the time complexity?
    // Ans-> Yes we can think about reversing in parts hence our SC will be O( 1 )
}
int main()
{

    vector<int>arr{1, 2, 3, 4, 5};
    int k = 3;
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    //rotateBF(arr, k, n);
    cout << endl;
    // TC - O(K) + O(N - K) + O( K )
    // SC - O(K)

    rotateOptimal(arr , k , n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}