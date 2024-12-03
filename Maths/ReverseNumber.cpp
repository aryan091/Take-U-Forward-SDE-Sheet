#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int reverse(int num)
{
    int number = 0;
    while (num != 0)
    {
        int digit = num % 10;
        num = num / 10;
        number = (number * 10) + digit;
    }
    
    return number;
}

int main()
{

    int n = 10400;
    
    cout << reverse(n) << endl;

    return 0;
}