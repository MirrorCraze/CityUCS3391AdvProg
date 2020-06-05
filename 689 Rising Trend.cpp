#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
//vector<int> DP;
/*void insertDP(int val)
{
    if(DP.size()==0 || DP[DP.size()-1] < val)
    {
        DP.push_back(val);
        return;
    }
    if(DP[DP.size()-1] > val && (DP.size() == 1 ||DP[DP.size()-2] > val))
    {
       DP[DP.size()-1]= val;
       return;
    }
    if(DP[0] > val)
    {
        DP[0] = val;
        return;
    }
    if(DP[0] < val && (DP.size() == 1 || DP[1] > val))
    {
        DP[1] = val;
        return;
    }
    if(DP.size() == 1)
        return;
    int leftpt = 0;
    int rightpt = DP.size()-1;
    int mid;
    while(leftpt < rightpt)
    {
        int mid = (leftpt + rightpt)/2;
        if(DP[mid] <= val && DP[mid+1] > val )
        {
            DP[mid+1] = val;
            break;
        }
        if(DP[mid] > val)
        {
            rightpt = mid-1;
        }
        else if(DP[mid+1] <= val)
        {
            leftpt = mid+1;
        }
    }
    if(leftpt == rightpt && DP[leftpt+1] >= val)
        DP[leftpt+1] = val;
}*/
main()
{
    int n;
    int temp;
    long long *A, *DP;
    while(cin >> n)
    {
        //DP.clear();
        A = new long long[n+5];
        DP = new long long[n+5];
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
            DP[i] = 1E18;
            //insertDP(temp);
            /*for(int i=0;i<DP.size();i++)
            {
                cout << DP[i] << " ";
            }
            cout << endl;*/
        }
        for(int i=0;i<n;i++)
        {
            *upper_bound(DP,DP+n,A[i]) = A[i];
        }
        cout << lower_bound(DP,DP+n,1E18) - DP << endl;
    }
}
