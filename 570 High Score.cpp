#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int ans = 0;
        string name;
        vector<int> APos;
        vector<int> strIndex;
        vector<char> str;
        int left = 0;
        int right = 0;
        int leftRight = 0;
        int minLeftRight;
        cin >> name;
        int len = name.length();
        minLeftRight = len-1;
        for(int i=0;i<len;i++)
        {
            int shiftFor = name[i] - 'A';
            ans += min(shiftFor,26-shiftFor);
            if(name[i] == 'A')
                APos.push_back(i);
        }
        for(auto it = APos.begin();it!=APos.end();it++)
        {
            str.clear();
            strIndex.clear();
            left = 0;
            right = 0;
            int pos = *it;
            for(int i=0;i<pos;i++)
            {
                str.push_back(name[i]);
                strIndex.push_back(i);
            }
            for(int i=len-1;i>pos;i--)
            {
                str.push_back(name[i]);
                strIndex.push_back(i);
            }
            while (!str.empty()&&str[str.size()-1] == 'A')
            {
                str.pop_back ();
                strIndex.pop_back ();
            }
            int indexSize = strIndex.size();
            for(int i=0;i<indexSize;i++)
            {
                if(strIndex[i] <= pos)
                    left++;
                else right++;
            }
            if(left > right)
                leftRight = right*2 + left-1;
            else
                leftRight = right + (left-1)*2;
            if(leftRight<0)
                minLeftRight = 0;
            else if (leftRight < minLeftRight)
                minLeftRight = leftRight;
        }
        ans += minLeftRight;
        cout << ans << endl;
    }
}
