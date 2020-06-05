#include<iostream>
#include<utility>
#include<queue>
#define pii pair<int,int>
using namespace std;
char board[15][15];
main()
{
    int t;
    cin >>t;
    pii black,white;
    pii temp;
    //freopen("688out.txt", "w+", stdout);
    queue<pii> Q;
    int Qsize;
    int depth;
    int x,y;
    int visited[15][15];
    bool found= false;
    for(int l=1;l<=t;l++)
    {
        while(!Q.empty())
            Q.pop();
        found = false;
        for(int i=0;i<13;i++)
        {
            for(int j=0;j<13;j++)
            {
                board[i][j] = 'X';
                visited[i][j] = -1;
            }
        }
        for(int i=2;i<10;i++)
        {
            scanf("%s",board[i]);
            for(int j=2;j<10;j++)
            {
                board[i][11-j] = board[i][9-j];
                if(board[i][11-j] == '#')
                    black = make_pair(i,11-j);
                if(board[i][11-j] == '@')
                    white = make_pair(i,11-j);
            }
            for(int j=0;j<=1;j++)
            {
                board[i][j] = 'X';
            }
        }
        /*for(int i=0;i<12;i++)
            printf("%s\n",board[i]);
        cout << "White" << white.first << " , " << white.second << endl;*/
        Q.push(black);
        depth = 0;
        while(!Q.empty() && !found)
        {
            //cout << "NEW LOOP" << endl;
            Qsize = Q.size();
            for(int i=0;i<Qsize;i++)
            {
                temp = Q.front();
                Q.pop();
                x = temp.first;
                y = temp.second;
                //cout << "POS X: " << x << " Y :" << y <<endl;
                if(white.first == x && y == white.second)
                {
                    found = true;
                    break;
                }
                if(visited[x][y] == -1)
                {
                    visited[x][y] = depth+1;
                    for(int k =1;k<=2;k++)
                    {
                        if(visited[x-k][y+k-3] == -1 &&(board[x-k][y+k-3] == '-' || board[x-k][y+k-3] == '@'))
                            Q.push(make_pair(x-k,y+k-3));
                        if(visited[x-k][y+3-k] == -1 &&(board[x-k][y+3-k] == '-' || board[x-k][y+3-k] == '@'))
                            Q.push(make_pair(x-k,y+3-k));
                        if(visited[x+k][y+k-3] == -1 &&(board[x+k][y+k-3] == '-' || board[x+k][y+k-3] == '@'))
                            Q.push(make_pair(x+k,y+k-3));
                        if(visited[x+k][y+3-k] == -1 &&(board[x+k][y+3-k] == '-' || board[x+k][y+3-k] == '@'))
                            Q.push(make_pair(x+k,y+3-k));
                    }
                }
                //cout << "Size" << Q.size() << endl;
            }
            if(!found)
                depth++;
        }
        cout << "Case " << l << ": ";
        if(!found)
            cout << "IMPOSSIBLE";
        else cout << depth;
        cout << endl;

    }
}
