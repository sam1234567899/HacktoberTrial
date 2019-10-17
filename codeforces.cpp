#include<bits/stdc++.h>

using namespace std;

long long int primeFactors(long long int n)
{
    // Print the number of 2s that divide n
    map<long long int ,long long int > mp;
    while (n % 2 == 0)
    {
        //cout << 2 << " ";
        mp[2]++;
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            //cout << i << " ";
            mp[i]++;
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        mp[n]++;

      long long int factor=1;
    map<long long int ,long long int >::iterator it;
       for(it=mp.begin();it!=mp.end();it++)
       {
            factor*=((*it).second+1);
       }
       return factor;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int a[n];
        map<long long int,long long int> mp;
        set<long long int> st;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            st.insert(a[i]);

        }
        sort(a,a+n);
        int i=0;
        int j=n-1;
        long long int flag=0;
        long long int temp=a[i]*a[j];
        while(i<j)
        {
            if(temp!=(a[i]*a[j]))
            flag=1;
            i++;j--;
        }
        if(i==j&&(a[i]*a[j])!=temp)
        flag=1;

        if(flag==1)
        cout<<"-1\n";
        else
        {
            long long int sto;
            if((primeFactors(temp))==(st.size()+2))
            cout<<temp<<"\n";
            else
            cout<<"-1\n";
            }


    }
}
