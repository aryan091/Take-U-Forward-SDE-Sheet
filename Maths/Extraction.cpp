#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 6794;
    int count  = 0 ;

while( n > 0)
   {

        int digit = n % 10;
        n = n / 10;
        cout << digit << " ";
        count++;
    }

    cout << endl;

    cout << count << endl;
        int num = 6794;

    cout << (int)(log10(num) + 1 )<< endl;

    return 0;
}