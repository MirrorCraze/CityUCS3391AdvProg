#include<iostream>
#include<sstream> //istringstream
#include<string>
#include<iomanip>
#include<cmath>
#include<stdio.h>
using namespace std;
main()
{
    string S;

    long double sum;
    long double temp;
    bool first = true;
    //freopen("222out.txt","w+",stdout);
    while(getline(cin,S))
    {

        sum = 0.0000;
        istringstream iss(S);
        temp = 0;
        while(iss >> temp)
        {
            sum +=temp;
        }
        if(first)
            first = false;
        else
            cout << endl;
        cout << fixed<< setprecision(4)  << sum <<endl;
    }
}
