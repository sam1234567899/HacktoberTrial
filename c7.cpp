#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 998244353
using namespace std;
ll mem[2005][2005],n,m,k;
ll func(ll,ll);
int main()
{
	cin>>n>>m>>k;
	memset(mem,-1,sizeof(mem));
	printf("%lld",m*func(1,k)%MOD);
}
ll func(ll idx,ll k)
{
	if(idx==n&&k==0)
		return 1;
	if(idx==n)
		return 0;
	if(k<0)
		return 0;
	if(mem[idx][k]!=-1)
		return mem[idx][k];
	return mem[idx][k]=((func(idx+1,k-1)*(m-1))%MOD+func(idx+1,k)%MOD)%MOD;
}