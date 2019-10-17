#include<bits/stdc++.h>

using namespace std;

map<long long int,long long int> mp;

void primeFactors(long long int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        mp[2]++;
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (long long int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            mp[i]++;
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        mp[n]++;
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        long long int n;
        cin>>n;
        long long int ans=0;
        long long int c2=0;
        long long int c3=0;
        long long int c5=0;

        while(n%2==0)
        {
            n/=2;
            c2++;
        }
        while(n%3==0)
        {
            n/=3;
            c3++;
        }
        while(n%5==0)
        {
            n/=5;
            c5++;
        }
        if(n!=1)
        cout<<-1<<"\n";
        else
        cout<<c2+2*c3+3*c5<<"\n";

    }
}
