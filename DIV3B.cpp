#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int m0=0,m1=0,m2=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%3==0)
            m0++;
            else if(a[i]%3==1)
            m1++;
            else
            m2++;


        }

        if(m1>m2)
        {
            m1=m1-m2;
            cout<<m0+m2+m1/3<<"\n";
        }
        else
        {
            m2=m2-m1;
            cout<<m0+m1+m2/3<<"\n";
        }


    }
}
