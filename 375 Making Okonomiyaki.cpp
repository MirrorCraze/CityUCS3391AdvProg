#include<stdio.h>
#include<utility>
#include<map>
#include<queue>
int state_id(int a,int b,int c,int d)
{
    return 25*25*25*a+25*25*b+25*c+d;
}
using namespace std;
main()
{
    int cup[4];
    int ans; //aim
    int state[4];
    int step;
    int curr_state;
    int Qsize;
    int new_state;
    int vol;
    int pow[4] = {25*25*25,25*25,25,1};
    bool found;
    /*map <int,int> M; //map id->depth
    queue<int> Q;*/
    while(scanf("%d %d %d %d %d",&cup[0],&cup[1],&cup[2],&cup[3],&ans)!=EOF)
    {
        /*while(!Q.empty())
            Q.pop();

        M.clear();*/
        if(cup[0] < ans && cup[1] < ans&& cup[2] < ans&& cup[3] < ans)
        {
            printf("-1\n");
            continue;
        }
        step = 0;
        map <int,int> M; //map id->depth
        queue<int> Q;
        found = false;
        M[0] = 0;
        Q.push(0);
        while(!Q.empty()&& !found)
        {
            step++;
            Qsize = Q.size();
            //printf("Size : %d\n",Qsize);
            for(int i=0;i<Qsize;i++)
            {
                curr_state = Q.front();
                Q.pop();
                new_state = curr_state;
                //printf("remain %d",Q.size());
                for(int j=3;j>=0;j--)
                {
                    state[j] = curr_state%25;
                    curr_state/=25;
                    if(state[j] == ans)
                    {
                        found = true;
                        break;
                    }
                }
                curr_state = new_state;
                /*printf("%d: ",step);
                for(int j=0;j<=3;j++)
                    printf("%d ",state[j]);
                printf("curr_state:%d\n",curr_state);
                printf("\n\n");*/
                if(found) break;
                for(int j=0;j<=3;j++)
                {
                    //empty cup
                    if(state[j]!=0)
                    {
                        new_state = curr_state - pow[j]*state[j];

                        if(M.find(new_state)==M.end())
                        {
                            M[new_state] = step;
                            Q.push(new_state);
                            //printf("emp %d\n",new_state);
                        }
                    }
                    //fill cup
                    if(state[j]!=cup[j])
                    {
                        new_state = curr_state + pow[j]*(cup[j]-state[j]);
                        if(M.find(new_state)==M.end())
                        {
                            M[new_state] = step;
                            Q.push(new_state);
                            //printf("fill %d\n",new_state);
                        }
                    }
                    for(int k=j+1;k<=3;k++)
                    {
                        //j to k
                        vol = state[j] < cup[k]-state[k]?state[j]:cup[k]-state[k];
                        new_state = curr_state -pow[j]*vol + pow[k]*vol;
                        if(M.find(new_state)==M.end())
                        {
                            M[new_state] = step;
                            Q.push(new_state);
                        }
                        //k to j
                        vol = state[k] < cup[j]-state[j]?state[k]:cup[j]-state[j];
                        new_state = curr_state -pow[k]*vol + pow[j]*vol;
                        if(M.find(new_state)==M.end())
                        {
                            M[new_state] = step;
                            Q.push(new_state);
                        }
                    }
                }
            }
        }
        if(found)
            printf("%d\n",step-1);
        else printf("-1\n");
    }
}
