#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>
#include<iostream>
using namespace std;
vector <int> prime;
map <int, bool> priMap;
int QSCirPrime[1000005];
map<int,bool> CirPrime;
int tenPow[10] = {(int)1E0,(int)1E1,(int)1E2,(int)1E3,(int)1E4,(int)1E5,(int)1E6,(int)1E7,(int)1E8,(int)1E9};
void makePrime(int n)
{
    prime.push_back(2);
    prime.push_back(3);
    bool div = false;
    for(int i=4;i<=n;i++)
    {
        div = false;
        for(int j=0;j<prime.size();j++)
        {
            if((double)sqrt(i)< prime[j])
                break;
            if(i % prime[j] == 0)
            {
                div = true;
                break;
            }
        }
        if(!div)
        {
            prime.push_back(i);
            priMap[i] = true;
        }
    }
}
int digit(int val)
{
    int tenth = 10;
    int dig = 1;
    while(tenth <= val)
    {
        dig++;
        tenth*=10;
    }
    return dig;
}
int rotated(int val,int dig)
{
    return val/10 + tenPow[dig-1] * (val%10);
}
int circularcheck(int val)
{
    if(priMap.find(val) == priMap.end())
        return 0;
    vector<int> V;
    V.push_back(val);
    int digval = digit(val);
    int newVal;
    //printf("HERE");
    for(int i=1;i<=digval;i++)
    {
        //printf("OLD %d\n",val );
        newVal = rotated(val, digval);
        //printf("V[i] %d ROT %d\n",V[0],newVal);
        if(priMap.find(newVal) == priMap.end())
            return 0;
        V.push_back(newVal);
        val = newVal;
    }
    for(auto it : V)
    {
        CirPrime[it] = true;
    }
    return 1;
}
void makeCirQS(int n)
{
    bool cirP = false;
    int tmp;
    for(int i=1;i<=n;i++)
    {
        if(CirPrime.find(i) != CirPrime.end())
        {
            cirP = true;
        }
        else
        {
            tmp = circularcheck(i);
            if(tmp == 1)
                cirP = true;
            else cirP = false;
        }
        QSCirPrime[i] = QSCirPrime[i-1];
        if(cirP)
        {
            QSCirPrime[i]++;
            //printf("CPR : %d\n",i);
        }
    }
}
main()
{
    //printf("%d",rotated(101,3));
    makePrime(1000002);
    for(int i=0;i<1000004;i++)
        QSCirPrime[i] = 0;
    /*for(auto it = prime.begin();it!=prime.end();it++)
        printf("%d ",*it);*/
    makeCirQS(1000002);
    int left, right,ans;
    scanf("%d",&left);
    //freopen("436out.txt","w+",stdout);
    while(left!=-1)
    {
        scanf("%d",&right);
        ans = QSCirPrime[right] - QSCirPrime[left-1];
        if(ans==0)
        {
            printf("No Circular Primes.");
        }
        else if(ans == 1)
        {
            printf("1 Circular Prime.");
        }
        else
            printf("%d Circular Primes.",ans);
        printf("\n");
        scanf("%d",&left);
    }


}
