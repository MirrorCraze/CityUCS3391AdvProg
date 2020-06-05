#include<iostream>
#include<string>
#define MAXSIZE 50
using namespace std;
string a,b;
int DP[MAXSIZE][MAXSIZE], OP[MAXSIZE][MAXSIZE];
void conOp(int i, int j) {
    if(i == 0 && j == 0)    return;
    if(OP[i][j] == 1)
        conOp(i-1, j-1);
    else if(OP[i][j] == 2) {
        conOp(i-1, j);
        printf("D%c%02d", a[i-1], j+1);
    }
    else if(OP[i][j] == 3) {
        conOp(i, j-1);
        printf("I%c%02d", b[j-1], j);
    } else {
        conOp(i-1, j-1);
        printf("C%c%02d", b[j-1], j);
    }

}
int main() {
    int Alen, Blen;
    cin >> a;
    while(a!="#")
    {
        cin >>b;
        Alen = a.length();
        Blen = b.length();
        for(int i=0;i<=Alen;i++)
        {
            for(int j=0;j<=Blen;j++)
                DP[i][j] = MAXSIZE;
        }
        DP[0][0] = 0;
        for(int i = 0; i <= Alen; i++) {
            for(int j = 0; j <= Blen; j++) {
                if(a[i] == b[j] && DP[i+1][j+1] > DP[i][j])
                    DP[i+1][j+1] = DP[i][j], OP[i+1][j+1] = 1;
                if(DP[i+1][j] > DP[i][j]+1)
                    DP[i+1][j] = DP[i][j]+1, OP[i+1][j] = 2;
                if(DP[i][j+1] > DP[i][j]+1)
                    DP[i][j+1] = DP[i][j]+1, OP[i][j+1] = 3;
                if(DP[i+1][j+1] > DP[i][j]+1)
                    DP[i+1][j+1] = DP[i][j]+1, OP[i+1][j+1] = 4;
            }
        }
        conOp(Alen, Blen);
        cout << "E\n";
        cin >> a;
    }
    return 0;
}
