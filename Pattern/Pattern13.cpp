// For N - 4

// 1   
// 2 3
// 4 5 6   
// 7 8 9 10 

#include <bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    int start = 1;  

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << start << " ";
            start++;
        }
        cout << endl;
    }

    
}

int main(){

    int n = 4;
    pattern(n);

    return 0;
}