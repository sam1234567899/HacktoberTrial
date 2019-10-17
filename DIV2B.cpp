#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];

    int flag=0;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=0)
        {
            a[i]=-a[i]-1;
            if(a[i]!=-1)
            flag=1;
        }
    }


    if(flag==1)
    {
        if(n%2==0)
        {
            for(int i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
        }
        else
        {
            vector<int> v;
            for(int i=0;i<n;i++)
            {
                if(a[i]!=-1)
                v.push_back(a[i]);

            }

            sort(v.begin(),v.end());
            int last=v[v.size()-1];
            int g=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]==last&&g==0)
                {
                    a[i]=-a[i]-1;
                    g=1;
                }

                cout<<a[i]<<" ";
            }
        }

    }
    else
    {
        if(n%2==0)
        {
            for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        }
        else
        {
            cout<<0<<" ";
            for(int i=1;i<n;i++)
            cout<<a[i]<<" ";
        }
    }
}
