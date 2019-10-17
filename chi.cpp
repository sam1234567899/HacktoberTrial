#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
using namespace std;
ll mem[25002][402][2];
ll func(ll,ll,ll);
	ll n,k;
int main()
{
	memset(mem,-1,sizeof(mem));

	cin>>n>>k;
	if(n<k)
		cout<<"0";
	else
	{
		cout<<func(0,0,0)%MOD;
	}
}
ll func(ll idx,ll tot,ll set)
{
	if(tot==k)
		set=1;
	if(idx==n)
	{
		if(set==1)
			return 1;
		else
			return 0;
	}
	if(mem[idx][tot][set]!=-1)
		return mem[idx][tot][set];
	if(set==1)
		return mem[idx][tot][set]=(k*func(idx+1,tot,set)%MOD)%MOD;
	else
		{
			if(tot!=0)
			return mem[idx][tot][set]=(((k-tot)*func(idx+1,tot+1,set)%MOD)%MOD+func(idx+1,1,set)%MOD)%MOD;
			return mem[idx][tot][set]=(k*func(idx+1,tot+1,set)%MOD)%MOD;
		}	
}