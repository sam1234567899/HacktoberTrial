#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,q;
    cin>>n>>q;

    long long int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    long long int find1[n];
    long long int max1=a[0];

    long long int maxi=0;
    long long int maxe=a[0];

    for(int i=0;i<n;i++)
    {
        max1=max(max1,a[i]);
        find1[i]=max1;

        if(a[i]>maxe)
        {
            maxe=a[i];
            maxi=i;
        }
    }
int b[n];
copy(a,a+n,b);
 for(int i=0;i<maxi;i++)
    {
        if(b[i]>b[i+1])
        {
            int temp=b[i];
            b[i]=b[i+1];
            b[i+1]=temp;
      }
      }
    vector<long long int> v;
    for(int i=(maxi+1)%n;i!=maxi;i=(i+1)%n)
    {
        v.push_back(b[i]);
    }

    long long int m;


    //for(int j=0;j<v.size();j++)
    //cout<<v[j]<<" ";
    while(q--)
    {
        cin>>m;

        if(m<=maxi)
        {
            cout<<find1[m-1]<<" "<<a[m]<<"\n";
        }
        else
        {
            m=m-maxi-1;
            m=(m%(n-1));
            cout<<maxe<<" "<<v[m]<<"\n";
        }
    }

}
