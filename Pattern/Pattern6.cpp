// For n = 3

// 1 2 3
// 1 2 
// 1 


#include <bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for (int i = n; i  >= 1; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}

int main()
{
    int n = 3;
    pattern(n);
    return 0;
}