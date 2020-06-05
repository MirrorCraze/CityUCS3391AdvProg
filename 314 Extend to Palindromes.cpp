#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
#define maxLen 100005
using namespace std;
class KMP{
public:
    int PF[maxLen]; //Prefix
    void nextPat(string str)
    {
        int len = str.length();
        PF[1] = 0;
        int j = 0;
        for(int i = 1;i<len;i++)
        {
            while(j!=0 && str[j]!=str[i])
                j = PF[j];
            if(str[j] == str[i])
                j++;
            PF[i+1] = j;
        }
    }
    void findPat(string text, string pat)
    {
        int textLen = text.length();
        nextPat(pat);
        int j=0;
        for(int i=0;i<textLen;i++)
        {
            while(j!=0 && text[i] != pat[j])
                j = PF[j];
            if(text[i] == pat[j])
                j++;
        }
        cout << text << pat.substr(j,pat.length()-j) << endl;
    }
};
main()
{
    KMP kmp;
    string T, revT;
    //freopen("314out.txt","w+",stdout);
    while(cin >> T)
    {
        revT = T;
        reverse(revT.begin(),revT.end());
        kmp.findPat(T,revT);
    }

}
