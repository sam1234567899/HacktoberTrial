#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
using namespace std;
ll func(ll,ll);
void GCD(ll a,ll b);
ll fac[100005],n,m,k,x,y,a,b;
ll inv[100005];
int main()
{
	cin>>n>>m>>k;
	fac[0]=1;
	rep(i,1,100005)
	fac[i]=(fac[i-1]*i)%MOD;
	
	inv[0]=1;
	rep(i,1,100004)
	{
		GCD(i,MOD);
		inv[i]=x;
	}
	rep(i,1,100004)
	{
		inv[i]=(inv[i-1]*inv[i])%MOD;
	}
	ll ans=0;
	rep(i,0,k)
	{
		cin>>a>>b;
		ans+=(((((fac[n-a+b-1]*inv[n-a])%MOD)*inv[b-1])%MOD)*((((fac[a-1+m-b]*inv[a-1])%MOD)*inv[m-b])%MOD))%MOD;
		ans%=MOD;
	}
	printf("%lld",(((((fac[n+m-2]*inv[n-1])%MOD)*inv[m-1])%MOD-ans)%MOD+MOD)%MOD);
}

void GCD(ll a,ll b)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	GCD(b,a%b);
	ll temp=x;
	x=y;
	y=temp-(a/b)*y;
}