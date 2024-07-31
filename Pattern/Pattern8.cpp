// For N = 3

//  *****
//   ***
//    *

#include <bits/stdc++.h>
using namespace std;

void pattern(int n){

    int space = 0;
    int star = 0;

    for(int i = n-1; i >= 0; i--)
    {
       space = n - i - 1;
       star = i * 2 + 1;

       for(int j = 0; j < space; j++)
       {
           cout << " ";
       }

       for(int j = 0; j < star; j++)
       {
           cout << "*"; 
       }

        cout << endl;
    }
}

int main(){

    int n = 3;
    pattern(n);

    return 0;
}