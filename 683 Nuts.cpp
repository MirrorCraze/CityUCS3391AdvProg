#include<stdio.h>
#include<cmath>
main()
{
    int sec,nut,div,maxnut;
    bool first = true;
    while(scanf("%d %d %d %d",&sec,&nut,&div,&maxnut)!=EOF)
    {
        int secNeed = ceil(nut/(double)maxnut);
        int divPerBox = sec-1;
        int boxFullDiv = div/divPerBox;
        int boxNeed = ceil(secNeed/(double)sec);
        //printf("secNeed%d\n",secNeed);
        //printf("boxFull%d\n",boxFullDiv);
        if(boxNeed <= boxFullDiv)
        {
            printf("%d",boxNeed);
        }
        else
        {
            secNeed = secNeed - boxFullDiv * sec;
            int divRemain = div%divPerBox;
            //printf("divRemain %d\n",divRemain);
            secNeed = secNeed- divRemain-1;
            if(secNeed <0)
                secNeed = 0;
            int boxAll = boxFullDiv+1;
            //printf("SecRemain %d\n",secNeed);
            printf("%d",boxAll + secNeed);
        }
        printf("\n");
    }
}
