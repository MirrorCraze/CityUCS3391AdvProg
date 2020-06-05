#include<stdio.h>
#include<string>
#define maxDIG 200005
#define bound maxDIG-1
using namespace std;
class bigDouble{
public:
    int intPart[maxDIG];
    int intLen;
    int floatLen;
    int floatPart[maxDIG];
    bigDouble()
    {
        intLen = 0;
        floatLen = 0;
    }
    bigDouble(int before, int after)
    {
        intLen = to_string(before).length();
        floatLen = to_string(after).length();
        for(int i=0;i<intLen;i++)
        {
            intPart[intLen-i-1] = before%10;
            before/=10;
        }
        for(int i=0;i<floatLen;i++)
        {
            floatPart[intLen-i-1] = after%10;
            after/=10;
        }
    }
    void printDouble()
    {
        for(int i=0;i<intLen;i++)
            printf("%d",intPart[i]);
        printf(".");
        for(int i=0;i<floatLen;i++)
            printf("%d",floatPart[i]);
    }
};
int* multSame(int a[],int b[],int aLen, int bLen)
{
    int *c = new int[maxDIG];
    return c;
}
bigDouble mult(bigDouble a, bigDouble b)
{
    bigDouble c;

    multSame(a.intPart,b.intPart,a.intLen,b.intLen,c.intPart,c.intLen,true);
}


main()
{
    bigDouble d(12345,34567);
    d.printDouble();
}
