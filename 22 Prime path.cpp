#include<stdio.h>
#include<map>
#include<queue>
#include<math.h>
using namespace std;
main()
{
    int t;
    scanf("%d",&t);
    map<int,bool> PM; //Prime map
    //freopen("22out.txt", "w+",stdout);
    PM[2] = true;
    bool found = false;
    for(int i=3;i<10000;i++)
    {
        found = false;
        for(auto it = PM.begin();it!=PM.end() && !found && sqrt(it->first) <= i;it++)
        {
            if(i%it->first==0)
                found = true;
        }
        if(!found)
        {
            PM[i] = true;
        }
    }
    int src;
    int dest;
    int depth = 0;
    bool destFound = false;
    int queueSize = 0;
    map<int,bool> checker;
    int top;
    queue<int> DFS;
    int newval;
    int tenMult[5];
    tenMult[0] = 1;
    for(int i=1;i<=3;i++)
        tenMult[i] = tenMult[i-1]*10;
    while(t--)
    {
        depth = 0;
        checker.clear();
        destFound = false;
        while(!DFS.empty())
            DFS.pop();
        scanf("%d %d",&src,&dest);
        if(src == dest)
            destFound = true;
        DFS.push(src);
        checker[src] = true;
        while(!destFound)
        {
            queueSize = DFS.size();
            while(queueSize--&&!destFound)
            {
                top = DFS.front();
                DFS.pop();
                for(int i=0;i<=9&&!destFound;i++)
                {
                    for(int j=0;j<=3;j++)
                    {
                        newval = top-(((top/tenMult[j])%10)*tenMult[j])+i*tenMult[j];
                        if(newval < 1000 || newval == top)
                            continue;
                        //printf("NEWVAL %d i %d j %d\n",newval,i,j);
                        if(PM[newval] && checker.find(newval) == checker.end())
                        {
                            DFS.push(newval);
                            //printf("Push %d from %d\n",newval,top);
                            checker[newval] = true;
                        }
                        if(newval == dest)
                        {
                            destFound = true;
                            break;
                        }
                    }
                }
                //printf("OUT OF FOR\n");
            }
            depth++;
        }
        printf("%d\n",depth);
    }
}
