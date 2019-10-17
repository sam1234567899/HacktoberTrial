#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
using namespace std;
ll func(ll,ll,ll,ll);
ll GCD(ll,ll);
ll inv[55],fact[55],n,r; //n total no. of '-1', r remaining sum to be full filled
int main()
{
	fact[0]=1;
	rep(i,1,52)
	{
		fact[i]=(i*fact[i-1])%MOD;
		inv[i]=i;
	}	
	ll t;
	cin>>t;
	while(t--)
	{
		ll s,sum=0,t,ar[55];
		n=0;
		cin>>t>>s;
		rep(i,0,t)
		{
			cin>>ar[i];
			if(ar[i]==-1)
				n++;
			else
				sum+=ar[i];
		}
		s-=sum;
		ll ans=1;
		rep(i,0,s-n+1)
		{
			ans+=func(1,i,1,r-i);
		}
		cout<<ans<<"\n";
	}

}
/*ll inverse_(ll n)
{

}*/
ll GCD(ll a,ll b)
{
	if(b==0)
		return a;
	else
		return GCD(b,a%b);
}
ll func(ll idx,ll prev,ll cnt,ll r)
{
	if(r<0)
		return 0;
	if(idx==n)
		{
			cout<<"\n";
			return inv[cnt];
		}	
	ll ans=0,mul;
	if(r-prev<=r-(n-idx)+1)
	ans+=func(idx+1,prev,cnt+1,r-prev);

	rep(i,prev+1,r-(n-idx)+2)
	{
		mul=cnt;
		ans+=(func(idx+1,i,0,r-i)*inv[cnt])%MOD;
	}	
	return ans;
}