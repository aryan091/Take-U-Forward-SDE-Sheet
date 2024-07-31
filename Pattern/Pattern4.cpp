// For n = 3

// 1
// 2 2 
// 3 3 3


#include <bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << i << " ";
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