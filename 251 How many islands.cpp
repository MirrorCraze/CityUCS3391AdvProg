#include<stdio.h>
#include<iostream>
#include<utility>
#include<queue>
#define pii pair<int,int>
using namespace std;
int I[55][55];
int checked[55][55];
int counter(int width,int height,int spot)
{
    queue<pii> Q;
    pii temp;
    int island = 0;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(I[i][j] == 1 && checked[i][j] == 0)
            {
                island++;
                Q.push(make_pair(i,j));
                while(!Q.empty())
                {
                    temp = Q.front();
                    Q.pop();
                    //cout << "visit(" <<temp.first << "," << temp.second << ")" << endl;
                    if(checked[temp.first][temp.second])
                        continue;
                    checked[temp.first][temp.second] = 1;
                    if(I[temp.first][temp.second+1] == 1 && checked[temp.first][temp.second+1] == 0)
                    {
                        //cout << "PUSH (temp.first,temp.second+1)" << endl;
                        Q.push(make_pair(temp.first,temp.second+1));
                    }
                    if(I[temp.first+1][temp.second+1] == 1&& checked[1+temp.first][temp.second+1] == 0)
                    {
                        //cout << "PUSH (temp.first+1,temp.second+1)" << endl;
                        Q.push(make_pair(temp.first+1,temp.second+1));
                    }
                    if(I[temp.first+1][temp.second] == 1&& checked[temp.first+1][temp.second] == 0)
                    {
                        //cout << "PUSH (temp.first+1,temp.second)" << endl;
                        Q.push(make_pair(temp.first+1,temp.second));
                    }
                    if(temp.first!=0)
                    {
                        if(I[temp.first-1][temp.second+1] == 1&& checked[temp.first-1][1+temp.second] == 0)
                        {
                            //cout << "PUSH (temp.first-1,temp.second+1)" << endl;
                            Q.push(make_pair(temp.first-1,temp.second+1));
                        }
                        if(I[temp.first-1][temp.second] == 1 && checked[temp.first-1][temp.second] == 0)
                        {
                            //cout << "PUSH (temp.first-1,temp.second)" << endl;
                            Q.push(make_pair(temp.first-1,temp.second));
                        }
                        if(temp.second!=0 && I[temp.first-1][temp.second-1] == 1 && checked[temp.first-1][temp.second-1] == 0)
                        {
                            //cout << "PUSH (temp.first-1,temp.second-1)" << endl;
                            Q.push(make_pair(temp.first-1,temp.second-1));
                        }
                    }
                    if(temp.second!=0)
                    {
                        if(I[temp.first][temp.second-1] == 1&& checked[temp.first][temp.second-1] == 0)
                        {
                            //cout << "PUSH (temp.first,temp.second-1)" << endl;
                            Q.push(make_pair(temp.first,temp.second-1));
                        }
                        if(I[temp.first+1][temp.second-1] == 1 && checked[temp.first+1][temp.second-1] == 0)
                        {
                            //cout << "PUSH (temp.first+1,temp.second-1)" << endl;
                            Q.push(make_pair(temp.first+1,temp.second-1));
                        }
                    }
                    //cout << "Qsize" << Q.size() << endl;
                }

            }
        }
    }
    return island;
}
main()
{
    int w,h,spot;
    cin>> w >> h;
    while(w!=0 && h !=0)
    {
        for(int i=0;i<53;i++)
        {
            for(int j=0;j<53;j++)
            {
                I[i][j] = 0;
                checked[i][j] = 0;
            }
        }
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin >> I[i][j];
                if(I[i][j])
                    spot++;
            }
        }
        int island = counter(w,h,spot);
        cout << island << endl;
        cin>> w >> h;
    }
}
