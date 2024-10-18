// For N - 4

// 1      1
// 12    21
// 123  321
// 12344321

#include <bits/stdc++.h>
using namespace std;

void pattern(int n){

for (int i = 1; i <= n; i++)
{
    // numbers 
    for (int j = 1; j <= i; j++)
    {
        cout << j ;
    }


    


    // space
   int space = 2 * (n - i);
    for (int j = 1; j <= space; j++)
    {
        cout << " ";
    }


    // number
     for (int j = i; j >= 1; j--)
    {
        cout << j ;
    }


        cout << endl;
        space= space-2;


}

    
}

int main(){

    int n = 4;
    pattern(n);

    return 0;
}