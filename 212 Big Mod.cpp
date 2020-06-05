#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
#define DIG_MAX 100
main()
{
    long long M[DIG_MAX]; //mod val
    int B[DIG_MAX]; //p to binary num
    int digit = 0;
    long long b,p,m;
    long long temp;
    long long ans = 1;
    while(cin >> b >> p >> m)
    {
        ans = 1;
        digit= 0;
        M[0] = b%m;
        for(int i=1;i<DIG_MAX;i++)
        {
            M[i] = ((M[i-1]%m) * M[i-1]) % m;
            //cout <<i << " "  << M[i] << endl;
        }
        while(true)
        {
            if(pow(2,digit) > p)
                break;
            digit++;
        }
        for(int i=0;i<digit;i++)
        {
            B[i] = p%2;
            p = p/2;
            //cout << "p "<< p << endl;
        }
        for(int i=0;i<digit;i++)
        {
            if(B[i])
            {
                ans = (ans* M[i]) % m;
            }
            //cout << "ans " <<  ans  << endl;
        }
        cout << ans << endl;
    }
}
