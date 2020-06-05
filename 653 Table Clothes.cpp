#include<stdio.h>
main()
{
    int n,m;
    int temp;
    scanf("%d %d",&n,&m);
    bool rim = false;
    while(n!=0 || m !=0)
    {
        rim = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&temp);
                if(temp ==1 &&(i==0 || i==n-1 || j==0 || j==m-1))
                    rim = true;
            }
        }
        if(rim)
            printf("2");
        else printf("4");
        printf("\n");
        scanf("%d %d",&n,&m);
    }


}
