#include <iostream>
#include <math.h>
using namespace std;
/*long long gcd(long long y,long long n, long long &a,long long &b)
{
    long long a1,b1;
    long long ans;
    if(n>y)
        return gcd(n,y,a,b);
    if(n==0)
    {
        a=1;
        b=0;
        return y;
    }
    ans = gcd(n,y%n,a1,b1);
    a = b1;
    b = a1-floor(y/n)*b1;
    return ans;
}*/

long long gcd(long long p, long long q, long long &x, long long &y)
{
	if (p == 0)
	{
		x = 0;
		y = 1;
		return q;
	}
	long long x1, y1;
	long long gcdPQ = gcd(q%p, p, x1, y1);
	x = y1 - (q/p) * x1;
	y = x1;
	return gcdPQ;
}
main()
{
	long long x,y,m,n,L;
	long long A=0,B=0;
	long long gcdAB;
	long long a,b;
	long long ans;
	while(cin>>x>>y>>m>>n>>L)
	{
	    //Ax = B (mod L)
		A=n-m;
		B=x-y;
		if(A <0 && B < 0)
        {
            A *= -1;
            B *= -1;
        }
		gcdAB = 0;
		a = 0;
		b = 0;
		ans = 0;
		while(gcdAB!=1)
		{
			gcdAB=gcd(abs(A),abs(B),a,b);
			gcdAB =gcd(L,gcdAB,a,b);
			A /= gcdAB;
			B /= gcdAB;
			L /= gcdAB;
		}

		gcdAB=gcd(A,L,a,b);
		if(B%gcdAB==0)
		{
			ans=(a*(B/gcdAB))%L;
            cout<<(ans+L)%L;
		}
		else // no sol possible.
			cout<<"Impossible";
        cout << endl;
	}
}
