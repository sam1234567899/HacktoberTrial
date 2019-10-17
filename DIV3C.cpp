#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    map<int,int> mp;
    mp[4]=0;
    mp[8]=0;
    mp[15]=0;
    mp[16]=0;
    mp[23]=0;
    mp[42]=0;
    int remove1=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==4)
        mp[4]++;
        else if(a[i]==8)
        {
            if(mp[8]>=mp[4])
            {
                remove1++;
            }
            else
            {
                mp[8]++;
            }
        }
        else if(a[i]==15)
        {
            if(mp[15]>=mp[8])
            {
                remove1++;
            }
            else
            {
                mp[15]++;

            }
        }
        else if(a[i]==16)
        {
            if(mp[16]>=mp[15])
            remove1++;
            else
            mp[16]++;
        }
        else if(a[i]==23)
        {
            if(mp[23]>=mp[16])
            remove1++;
            else
            mp[23]++;
        }
        else
        {
            if(mp[42]>=mp[23])
            remove1++;
            else
            mp[42]++;
        }




    }

    int min1=INT_MAX;
        map<int,int> :: iterator it;

        for(it=mp.begin();it!=mp.end();it++)
        {
            min1=min(min1,it->second);
        }

        for(it=mp.begin();it!=mp.end();it++)
        {
            remove1+=(it->second-min1);
        }

        cout<<remove1<<"\n";
}

