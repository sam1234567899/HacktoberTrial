#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    cin>>a[i];

    int mini=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        int mi=max(i-1,n-i);
        if(mini>(a[i]/mi))
        mini=a[i]/mi;
    }
    cout<<mini;


}
