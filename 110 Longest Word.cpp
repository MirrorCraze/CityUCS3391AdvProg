#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
main()
{
    string S;
    string maxString;
    int maxlen=0;
    int curlen;
    do{
        cin >> S;
        curlen = 0;
        for(int i=0;i<S.length();i++)
        {
            if((tolower(S[i]) >='a' && tolower(S[i]) <='z') || S[i] == '-')
            {
                curlen++;

            }
            else
            {

                if(curlen > maxlen)
                {
                    maxlen = curlen;
                    maxString = S.substr(i-maxlen,maxlen);
                    //cout << "MAX " << maxString << endl;
                }
                curlen = 0;
            }
        }
        if(curlen > maxlen)
        {
            maxlen = curlen;
            maxString = S.substr(S.length()-maxlen,maxlen);
            //cout << "MAX " << maxString << endl;
        }
        curlen = 0;
    }while(S.compare("E-N-D")!=0);
    for(int i=0;i<maxString.length();i++)
    {
        printf("%c",tolower(maxString[i]));
    }
    printf("\n");
}
