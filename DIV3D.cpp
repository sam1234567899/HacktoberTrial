#include<bits/stdc++.h>

using namespace std;
int sieve[2750132];
int main()
{
    int n;
    cin>>n;
    int a[2*n];
    for(int i=0;i<2*n;i++)
    cin>>a[i];

    vector<int> v;


    sieve[0]=1;
    sieve[1]=1;

    for(int i=2;i<=sqrt(2750131);i++)
    {
        if(sieve[i]==0)
        {
            for(int j=i;j*i<2750132;j++)
            sieve[i*j]=1;
        }
    }
    sort(a,a+2*n);
    vector<int> prime;

    for(int i=0;i<2*n;i++)
    {
        if(sieve[a[i]]==0)
        prime.push_back(a[i]);
    }

    int maxp=prime.size()/2;
    //int countp=0;

    for(int i=2;i<=2750131;i++)
    {
        if(sieve[i]==0)
        v.push_back(i);
    }

    int i=0;
    int j=0;

    vector<int> primetp;
    while(i<prime.size()&&j<v.size())
    {
        if(j>=maxp)
        break;

        if(v[j]==prime[i])
        {
            i++;
            j++;
        }
        else if(v[j]>prime[i])
        {
            primetp.push_back(prime[i]);
            i++;
        }
        else
        {
            break;
        }
    }

    int count1=min(maxp,j)-primetp.size();
    //int total=i;

    while(count1>0)
    {
        primetp.push_back(prime[i]);
        i++;
        count1--;
    }



    for(int k=0;k<2*n;k++)
    {

        if(sieve[a[k]]==1)
        primetp.push_back(a[k]);
    }

    while(i<prime.size())
    {
        if(n==primetp.size())
        break;

        primetp.push_back(prime[i]);
        i++;
    }

    for(int k=0;k<primetp.size();k++)
    cout<<primetp[k]<<" ";


}
