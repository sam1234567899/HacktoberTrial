#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 998244353
using namespace std;
int  n,ar[100005];
int mem[100005][205][2];
ll func(ll,ll,ll);
int main()
{
	cin>>n;
	rep(i,0,n)
	cin>>ar[i];
	rep(i,0,n)
	rep(j,0,205)
	mem[i][j][0]=mem[i][j][1]=-1;
	cout<<func(0,0,1);
}
ll func(ll idx,ll prev,ll set)
{
	//cout<<idx<<" "<<prev<<" "<<set<<"\n";
	if(idx==n)
	{
		if(set==0)
		return 0;
		if(set==1)
		return 1;
	}
	if(mem[idx][prev][set]!=-1)
		return mem[idx][prev][set];
	ll a=0,b=0,c=0;
	if(ar[idx]==-1)
	{
		if(set==1)
		{
			rep(i,1,prev+1)
			{
				a+=func(idx+1,i,1);
				a%=MOD;
			}
			rep(i,prev+1,201)
			{
				b+=func(idx+1,i,0);
				b%=MOD;
			}
			return mem[idx][prev][set]=(int)((a+b)%MOD);
		}	
		if(set==0)
		{
			//if(idx==n-1)


			rep(i,prev+1,201)
			{
				c+=func(idx+1,i,0);
				c%=MOD;
			}
			c+=func(idx+1,prev,1);
			c%=MOD;	
			return mem[idx][prev][set]=(int)c;
		}
	}
	if(ar[idx]<prev&&set==0)
		return mem[idx][prev][set]=0;
	if(ar[idx]>prev&&set==0)
		return mem[idx][prev][set]=func(idx+1,ar[idx],0);
	if(ar[idx]==prev&&set==0)
		return mem[idx][prev][set]=func(idx+1,ar[idx],1);
	return mem[idx][prev][set]=func(idx+1,ar[idx],ar[idx]<=prev);
}