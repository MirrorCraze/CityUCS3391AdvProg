#include<stdio.h>
#include<iostream>
#include<utility>
#include<queue>
using namespace std;
#define pni pair<node*, int>
class node
{
public:
    int wLeft;
    int wRight;
    node* left;
    node* right;
    int disLeft;
    int disRight;
    bool ended;
    node(int wLeft, int wRight, int disLeft, int disRight)
    {
        this->wLeft = wLeft;
        this->wRight = wRight;
        this->disLeft = disLeft;
        this->disRight = disRight;
        if(wLeft!=0 && wRight !=0)
            ended = true;
        else ended = false;
        if(wLeft != 0)
            left = NULL;
        if(wRight != 0)
            right = NULL;

    }
};
pni constructTree()
{
    int wLeft, wRight, disLeft, disRight;
    cin >> wLeft  >> disLeft >> wRight >> disRight;
    node* head = new node(wLeft,wRight, disLeft, disRight );
    pni temp;
    if(head->wLeft == 0)
    {
        temp = constructTree();
        head->left = temp.first;
        head->wLeft = temp.second;

    }
    if(head->wRight == 0)
    {
        temp = constructTree();
        head->right = temp.first;
        head->wRight = temp.second;
    }
    pni nodeAndWeight = make_pair(head,head->wLeft+head->wRight);
    return nodeAndWeight;
}
main()
{
    //freopen("192in.txt","r+",stdin);
    //freopen("192out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    bool cont = true;
    queue <node*> DFS;
    bool ans = true;
    node* temp;
    while(t--)
    {
        ans = true;
        node* head = constructTree().first;
        DFS.push(head);
        while(!DFS.empty() && ans)
        {
            temp = DFS.front();
            DFS.pop();
            //cout << "considering " << temp->wLeft <<" "<< temp->disLeft << " "<<temp-> wRight <<" "<< temp-> disRight << endl;
            if(temp->wLeft * temp->disLeft != temp-> wRight * temp-> disRight)
            {
                ans = false;
            }
            else
            {
                if(temp->left !=NULL)
                    DFS.push(temp->left);
                if(temp->right !=NULL)
                    DFS.push(temp->right);
            }
        }
        if(ans)
            cout << "YES" << endl;
        else cout << "NO" << endl;
        if(t!=0)
        cout  << endl;
    }
}
