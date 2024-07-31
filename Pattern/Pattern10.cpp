// For N - 3

// *
// **
// ***
// **
// *

#include <bits/stdc++.h>
using namespace std;

void pattern(int n){

    int stars = 0;

    for(int i = 1; i <= 2 * n - 1 ; i++)
    {
        stars = i;
        if( i > n) stars = 2 * n - i;
        for (int j = 0; j < stars; j++)
        {
            cout << "*" << " ";
        }
        
        cout << endl;

    }
}

int main(){

    int n = 3;
    pattern(n);

    return 0;
}