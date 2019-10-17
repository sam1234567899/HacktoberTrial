#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
using namespace std;
ll GCD(ll,ll);
ll t,n,ar[200005],br[200005];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		rep(i,0,n)
		cin>>ar[i];
		sort(ar,ar+n);
		br[0]=ar[n-1];
		rep(i,0,n-1)
		br[i+1]=ar[i];	
		ll flag=0;
		rep(i,2,n)
		{
			if(ar[i]!=(ar[i-1]+GCD(ar[i-1],ar[i-2])))
			{
				flag=1;
			}
		}
		ll gflag=0;	
		rep(i,2,n)
		{
			if(GCD(br[i-1],br[i-2])+br[i-1]!=br[i])
				gflag=1;
		}
		if(n==1)
		{
			cout<<ar[0]<<"\n";
			continue;
		}
		else if(n==2)
		{
			cout<<ar[1]<<" "<<ar[0]<<"\n";
			continue;
		}
		else if(gflag==0)
		{
			rep(i,0,n)
			cout<<br[i]<<" ";
			cout<<"\n";
			continue;
		}
		else if(flag==0)
		{
			rep(i,0,n)
			cout<<ar[i]<<" ";
			cout<<"\n";
		}
		else
			cout<<"-1\n";
	}
}
ll GCD(ll a,ll b)
{
	if(b==0)
		return a;
	return GCD(b,a%b);
}