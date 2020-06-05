#include<iostream>
#include<utility>
#include<algorithm>
#define pii pair<int,int>
using namespace std;
class vect
{
public:
    int xVect;
    int yVect;
    vect(pii a,pii b)
    {
        xVect = b.first - a.first;
        yVect = b.second - b.second;
    }
};
int crossVect(vect a, vect b)
{
    return a.xVect * b.yVect - a.yVect * b.xVect;
}
int dotVect(vect a, vect b)
{
    return a.xVect * b.xVect + a.yVect * b.yVect;
}
bool inLine(pii a, pii b, pii c) //C in AB
{
    if(crossVect(vect(a,b),vect(a,c))==0)
    {
        if(dotVect(vect(a,b),vect(a,c)) > 0 && dotVect(vect(a,b),vect(a,c))  < dotVect(vect(a,b),vect(a,b))
           return true;
    }
    return false;
}
main()
{

}
