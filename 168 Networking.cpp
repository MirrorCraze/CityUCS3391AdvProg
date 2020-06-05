#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
using namespace std;
class path{
public:
    int len;
    int src;
    int sink;
    path()
    {

    }
    path(int len,int src,int sink)
    {
        this->len = len;
        this-> src = src;
        this->sink = sink;
    }
};
class comparator{
public:
    bool operator()(path &a, path&b)
    {
        return a.len > b.len;
    }
};
class Node{
public:
    int link;
    int ranks;
    Node()
    {
        link = 0;
        ranks = 1;
    }
};
int topFind(int leaf, Node *UF)
{
    //cout << "Find from " << leaf << "found" << UF[leaf].link << endl;
    if(UF[leaf].link == leaf)
    {
        //cout << "End";
        return leaf;
    }
    else return UF[leaf].link = topFind(UF[leaf].link,UF);
}
void merger(Node &a,Node &b)
{
    if(a.ranks > b.ranks)
    {
        a.ranks+=b.ranks;
        b.link = a.link;
    }
    else
    {
        b.ranks+=a.ranks;
        a.link = b.link;
    }
}
int MST(priority_queue<path,vector<path>,comparator> &PQ,int n)
{
    int edge = 0;
    int cost = 0;
    Node UF[n+5];
    path tempPath;
    for(int i=0;i<=n;i++)
    {
        UF[i].link = i;
    }
    while(!PQ.empty() && edge <n-1)
    {
        tempPath = PQ.top();
        PQ.pop();
        //cout << "Link" << tempPath.src << " to " << tempPath.sink << " len " << tempPath.len << endl;
        //cout << "Link from" <<  M[tempPath.src] << " to " << M[tempPath.sink] << endl;
        if(topFind(tempPath.src,UF) != topFind(tempPath.sink,UF))
        {
            //cout << topFind(M[tempPath.src],UF) <<" "<< topFind(M[tempPath.sink],UF) << endl;
            merger(UF[topFind(tempPath.src,UF)],UF[topFind(tempPath.sink,UF)]);
            edge++;
            cost += tempPath.len;
        }
        /*for(int i=0;i<n;i++)
        {
            cout << UF[i].link << " ";
        }
        cout << endl;*/
    }
    return cost;
}
main()
{
    int p,r;
    int src,sink,dist;
    cin >> p;
    priority_queue<path,vector<path>,comparator> PQ;

    while(p!=0)
    {
        while(!PQ.empty())
            PQ.pop();
        cin >> r;
        for(int i=0;i<r;i++)
        {
            cin >> src >> sink >> dist;
            PQ.push(path(dist,src,sink));
        }
        cout << MST(PQ,p) << endl;
        cin >> p;

    }
}
