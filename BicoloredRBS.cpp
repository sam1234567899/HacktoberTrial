#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    stack<int> s;
    int start=0;
    int ans[n]={0};
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            ans[i]=start;
            s.push(start);
            start=start^1;
        }
        else
        {
            int top=s.top();
            ans[i]=top;
            s.pop();
            start=top;
        }
    }
    for(int j=0;j<n;j++)
    cout<<ans[j];
}
