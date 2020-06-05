#include<stdio.h>
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
#define pii pair<int,int>
#define pid pair<int,double>
using namespace std;
double dist(pii a, pii b)
{
    return sqrt((double)(a.first-b.first)*(a.first-b.first) + (double)(a.second-b.second) * (a.second-b.second));
}
struct comp{
    bool operator()(pid &a, pid &b)
    {
        return a.second > b.second;
    }
};

main()
{
    int n;
    int ix,iy,fx,fy,tx,ty;
    double distance;
    map<int, pii> M; //node #k to kx, ky
    int visit = 0;
    pii temp;
    int caseNo = 0;
    //freopen("165out.txt","w+",stdout);
    priority_queue <pid, vector<pid>, comp> PQ;
    while(true)
    {
        visit = 0;
        M.clear();
        while(!PQ.empty())
            PQ.pop();
        scanf("%d",&n);
        //cout << "Receive "<<n<<endl;
        caseNo++;
        double P[n+5];
        bool B[n+5];
        for(int i=1;i<=n;i++)
        {
            B[i] = false;
            P[i] = 1E9;
        }
        if(n == 0)
            break;
        scanf("%d %d %d %d",&ix,&iy,&fx,&fy);
        M[1] = make_pair(ix,iy);
        M[n] = make_pair(fx,fy);
        for(int i=2;i<=n-1;i++)
        {
            scanf("%d %d",&tx,&ty);
            M[i] = make_pair(tx,ty);
        }
        PQ.push(make_pair(1,0));
        P[1] = 0;
        while(visit!=n-1)
        {
            //cout << "Visit" << visit <<endl;
            temp = PQ.top();
            PQ.pop();
            if(B[temp.first])
                continue;
            B[temp.first] = true;
            visit++;

            for(int i=1;i<=n;i++)
            {
                if(!B[i])
                {
                    if(P[i] == 1E9)
                        P[i] = dist(M[temp.first],M[i]);
                    //if(max(dist(M[temp.second],M[i]),P[temp.first]) < P[i])
                    else
                    {
                        P[i] = min(max(dist(M[temp.first],M[i]),P[temp.first]),P[i]);
                        //cout << "DIS" << dist(M[temp.first],M[i])<<endl;
                    }
                    PQ.push(make_pair(i,P[i]));
                }
                //cout << P[i] << " ";
            }
            //cout << endl;

        }
        cout << "Scenario #" << caseNo << endl;
        printf("Frog Distance = %.3f\n\n",P[n]);
        cin.ignore();
        cin.ignore();

    }
}
