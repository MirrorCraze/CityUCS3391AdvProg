#include<stdio.h>
#include<stack>
#include<string>
#include<queue>
#include<iostream>
using namespace std;
main()
{
    int t;
    scanf("%d",&t);
    char temp;
    /*freopen("190in.txt","r",stdin);*/
    //freopen("190out.txt","w+",stdout);
    stack <char> S;
    string cmd;
    cin.ignore();
    cin.ignore();
    bool first = true;
    while(t--)
    {
        while(true)
        {
            getline(cin, cmd);
            if(cmd.empty() || cmd.compare("\n") == 0)
            {
                while(!S.empty())
                {
                    cout << S.top();
                    S.pop();
                }
                break;
            }
            temp = cmd[0];
            if(temp == '(')
                S.push(temp);
            else if(temp >='0' && temp <= '9')
                cout << temp;
            else if (temp == '*' || temp == '/')
            {
                if(S.empty() || S.top() == '+' || S.top() == '-' || S.top() == '(')
                {
                    S.push(temp);
                }
                else
                {
                    while(!S.empty() && (S.top() == '*' || S.top() == '/'))
                    {
                        cout << S.top();
                        S.pop();
                    }
                    S.push(temp);
                }
            }
            else if (temp == '+' || temp == '-')
            {
                if(S.empty() || S.top() =='(')
                {
                    S.push(temp);
                }
                else
                {
                    while(!S.empty() && (S.top() != '('))
                    {
                        cout << S.top();
                        S.pop();
                    }
                    S.push(temp);
                }
            }
            else if(temp == ')')
            {
                while(S.top()!='(')
                {
                    cout << S.top();
                    S.pop();
                }

                S.pop();
            }
        }
        //cout << endl;
        cout << endl;
        if(t!=0)
            cout << endl;
    }

}
