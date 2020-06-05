#include<iostream>
#include<set>
#include<string>
#include<stdio.h>
using namespace std;
main()
{
    string tmp;
    set<string> S;
    //freopen("185in.txt","r+",stdin);
    //freopen("185out.txt","w+",stdout);
    S.clear();
    while(cin >> tmp)
    {

        //cout << "word " <<tmp << endl;
        int len = tmp.length();
        string word = "";
        for(int i=0;i<len;i++)
        {
            if(tolower(tmp[i])>='a' && tolower(tmp[i]) <='z')
                word += tolower(tmp[i]);
            else if(word!="")
            {
                //cout<<"INSERT" << endl;
                S.insert(word);
                word = "";
            }
        }
        if(word!="")
        {
            //cout<<"INSERT" << endl;
            S.insert(word);
        }

    }
    for(auto it = S.begin();it!=S.end();it++)
        cout << *it << endl;
}
