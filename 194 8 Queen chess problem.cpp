#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;
int B[9],line;
bool place(int qNum, int row) //Is this place OK?
{
    for(int i = 1; i <= qNum - 1; i++)
        if(B[i] == row || (abs(B[i] - row) == abs(i - qNum)))
            return false;
    return true;
}

void queen(int qNum,int a,int b)
{
    for(int row = 1; row <= 8; row++){
        if(place(qNum, row)){
            B[qNum] = row;
            if(qNum == 8 && B[b] == a){
                printf("%2d      %d", ++line, B[1]);
                for(int j = 2; j <= 8; j++)
                    printf(" %d", B[j]);
                printf("\n");
            }
            else {
                queen(qNum + 1,a,b);
            }
        }
    }
}
main()
{
    int t;
    int a,b;
    scanf("%d", &t);
    //freopen("194out.txt","w+",stdout);
    while(t--)
    {
        scanf("%d %d", &a, &b);
        for(int i=0;i<9;i++)
            B[i] = 0;
        line = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        queen(1,a,b);
        if(t != 0)
            printf("\n");
    }
}
