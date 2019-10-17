#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long int power(long long int a,long long int n)
{
    long long int ans=1;

    while(n)
    {
        if(n%2==1)
        {
            ans=(ans%mod*a%mod)%mod;
        }

        n=n/2;

        a=(a%mod*a%mod)%mod;
    }

    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k;
        cin>>n>>k;

        string str;
        cin>>str;

        long long int acount=0;
        long long int bcount=0;
        long long int ans=0;
        for(long long int i=0;i<str.length();i++)
        {
            if(str[i]=='A')
            acount++;
            else
            bcount++;

            if(acount>=bcount)
            {
                acount=0;
                bcount=0;
            }
            else if(bcount-acount>k)
            {
                str[i]='A';
                bcount--;
                acount++;

                ans=(ans%mod+power(2,i+1)%mod)%mod;

            }
        }

        cout<<ans<<"\n";
    }
}
