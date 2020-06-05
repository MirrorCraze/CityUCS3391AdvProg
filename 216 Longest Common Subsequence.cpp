#include<stdio.h>
#include<string>
#include<iostream>
#include<cmath>
main()
{
    using namespace std;
    string A,B;

    while(getline(cin,A))
    {
        getline(cin,B);
        int Alen = A.length();
        int Blen = B.length();
        int LCS[Alen+1][Blen+1];
        for(int i=0;i<=Alen;i++)
        {
            for(int j=0;j<=Blen;j++)
            {
                if(i==0 || j==0)
                    LCS[i][j]=0;
                else
                {
                    LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
                    if(A[i-1] == B[j-1])
                        LCS[i][j] = max(LCS[i][j],LCS[i-1][j-1]+1);
                }
            }
        }
        /*for(int i=0;i<=Alen;i++)
        {
            for(int j=0;j<=Blen;j++)
            {
                printf("%d ",LCS[i][j]);
            }
            printf("\n");
        }*/
        printf("%d\n",LCS[Alen][Blen]);
    }
}
