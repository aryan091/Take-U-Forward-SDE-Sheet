#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void allDivisors(int num)
{
    vector<int> v;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            v.push_back(i);
            if (num / i != i)
                v.push_back(num / i);
        }
    }
    
    for (auto i : v)
        cout << i << " ";
}

int main()
{

    int n = 36;
    
    allDivisors(n) ;

    return 0;
}