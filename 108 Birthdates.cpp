#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
#include<iostream>
using namespace std;
bool comparator(pair<string,int> pa, pair<string,int> pb)
{
    return pa.second > pb.second;
}
main()
{
    int n;
    scanf("%d",&n);
    vector<pair<string,int> > V;
    string name;
    int d,m,y;
    for(int i=0;i<n;i++)
    {
        cin >> name >> d >> m >> y;
        V.push_back(make_pair(name, 370*y+35*m+d));
    }
    sort(V.begin(),V.end(),comparator);
    cout << V[0].first << endl << V[V.size()-1].first<<endl;
}
