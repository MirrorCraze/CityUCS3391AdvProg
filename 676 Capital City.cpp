#include<iostream>
#include<iomanip>
#define NODE 100
#define INF 1E9
using namespace std;
//Cost matrix of the graph
int dist[NODE][NODE];
void floydWarshal(int n){
    int cost[n+5][n+5]; //define to store shortest distance from any node to any node
    for(int i = 1; i<=n; i++)
      for(int j = 1; j<=n; j++)
         cost[i][j] = dist[i][j]; //copy costMatrix to new matrix
    for(int k = 1; k<=n; k++)
    {
        for(int i = 1; i<=n; i++)
           for(int j = 1; j<=n; j++)
              if(cost[i][k]+cost[k][j] < cost[i][j])
                 cost[i][j] = cost[i][k]+cost[k][j];
    }
    int city;
    int minDis = INF;
    int sum = 0;
    for(int i = 1; i<=n; i++){
       sum = 0;
        for(int j=1;j<=n;j++)
            sum+=cost[i][j];
        if(sum < minDis)
        {
            minDis = sum;
            city = i;
        }
    }
    printf("%d\n",city);
}
int main()
{
    int n,m;
    int src,sink,dis;
    while(cin >> n >> m)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                    dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }
        for(int i=0;i<m;i++)
        {
            cin >> src >> sink >> dis;
            dist[src][sink] = dis;
            dist[sink][src] = dis;
        }
        floydWarshal(n);
    }

}
