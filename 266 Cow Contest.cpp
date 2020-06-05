#include <cstdio>
#include<iostream>
#define MAXSIZE 105
using namespace std;

main ()
{
    int n,m;
    int total = 0;
    int a, b;
    //freopen("266out.txt","w+",stdout)
    while (cin >> n >> m)
    {
        bool R[MAXSIZE][MAXSIZE];
        total = 0;
        for (int i = 0; i < n; i++)
            R [i][i] = true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(i!=j)
                    R[i][j] = false;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            R[a-1][b-1] = true;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                if (R[i][k])
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (R[k][j])
                            R [i][j] = true;
                    }
                }
            }
        }
        bool allReach = true;
        for (int i = 0; i < n; i++)
        {
            allReach = true;
            for (int j = 0; j < n; j++)
            {
                if (!R [i][j] && !R [j][i])
                {
                    allReach = false;
                    break;
                }
            }
            if (allReach)
                total++;
        }
        cout << total << endl;
    }
}
