#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string armstrong(int num)
{
    int number = num;
    int sum = 0;
    while (num != 0)
    {
        int digit = num % 10;
        num = num / 10;
        sum = sum + (digit * digit * digit);
    }
        
    if (sum == number)
    {
        return "Armstrong Number";
    }
    else
    {
        return "Not Armstrong Number";
    }
}

int main()
{

    int n = 3701;
    
    cout << armstrong(n) << endl;

    return 0;
}