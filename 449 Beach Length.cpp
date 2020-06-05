#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
map<char,int> M;
int counter(vector<string> &V)
{
    /*
        1 2 3 4
         5 6 7 8
        9 A B C
         * * * * * *       0 1 2 3 4 5
        * 1 2 3 4 *        6 7 8 9 A B
         * 5 6 7 8 *
        * 9 A B C *
         * D E F G *
        * * * * * *
    */
    int row = V.size();
    int col = V[0].length();
    int sum = 0;
    char K[row+5][col+5];
    for(int i=0;i<=col+1;i++)
    {
        K[0][i] = 'X';
        K[row+1][i] = 'X';
    }
    for(int i=0;i<=row+1;i++)
    {
        K[i][0] = 'X';
        K[i][col+1] = 'X';
    }
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
            K[i][j] = V[i-1][j-1];
    }
    int id;
    char temp,comp;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            id = i*(col+2)+j;
            temp = K[i][j];
            comp = K[i-1][j];
            if(M[temp] + M[comp] == 1)
                sum++;
            comp = K[i+1][j];
            if(M[temp] + M[comp] == 1)
                sum++;
            comp = K[i][j-1];
            if(M[temp] + M[comp] == 1)
                sum++;
            comp = K[i][j+1];
            if(M[temp] + M[comp] == 1)
                sum++;
            if(i%2==1)
            {
                comp = K[i-1][j-1];
                if(M[temp] + M[comp] == 1)
                    sum++;
                comp = K[i+1][j-1];
                if(M[temp] + M[comp] == 1)
                    sum++;
            }
            else
            {
                comp = K[i-1][j+1];
                if(M[temp] + M[comp] == 1)
                    sum++;
                comp = K[i+1][j+1];
                if(M[temp] + M[comp] == 1)
                    sum++;
            }
        }
    }
    return sum/2;

}
main()
{
    vector <string> V;
    string tmp;
    M['.'] = 0;
    M['#'] = 1;
    M['X'] = 100000;
    while(getline(cin,tmp))
    {
        if(tmp =="")
        {
            cout << counter(V) << endl;
            V.clear();
        }
        else
        {
            V.push_back(tmp);
        }
    }

}
