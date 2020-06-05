#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
void oper(stack<long long> &numS, stack<char> &operS,unordered_map<char,int> &prior, char op)
{
    int curPrior = prior[op];
    char temp;
    long long num;
    while(!operS.empty() && prior[operS.top()] >=curPrior && (operS.top()!='('))
    {
        temp = operS.top();
        operS.pop();
        if(temp == '*')
        {
            num = numS.top();
            numS.pop();
            //cout << num << " * " << numS.top()<<endl;
            num *= numS.top();
            numS.pop();
            numS.push(num);

        }
        else if(temp == '+')
        {
            num = numS.top();
            numS.pop();
            //cout << num << " + " << numS.top()<<endl;
            num += numS.top();
            numS.pop();
            numS.push(num);
        }
        else if(temp == '(')
        {
            break;
        }
    }
    if(op == ')' && operS.top() == '(')
        operS.pop();
}
main()
{
    char str[105];
    unordered_map <char,int> prior;
    prior['('] = 3;
    prior[')'] = 0;
    prior['*'] = 2;
    prior['+'] = 1;
    prior['e'] = -1;
    while(scanf("%s",str)!=EOF)
    {
        stack<long long> numS;
        stack<char> operS;
        int len = strlen(str);
        char temp;
        for(int i=0;i<len;i++)
        {
            if(str[i] >='A' && str[i]<='F')
            {
                numS.push(str[i]-'A'+10);
            }
            else if(str[i]>='0' && str[i] <='9')
            {
                numS.push(str[i]-'0');
            }
            else if(str[i] == '(')
            {
                operS.push(str[i]);
            }
            else
            {
                oper(numS,operS,prior,str[i]);
                if(str[i]!=')')
                    operS.push(str[i]);
            }
        }

        oper(numS,operS,prior,'e');
        if(!operS.empty() || numS.size()!=1)
            cout << "ERROR";
        //cout << dec << numS.top() << " ";
        cout << hex <<uppercase <<  numS.top() << endl;
        numS.pop();
        while(!operS.empty())
            operS.pop();
    }
}
