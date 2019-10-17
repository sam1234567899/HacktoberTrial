#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 9223372036854775807
#define mini 9223372036854775807
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
pair<ll,ll>s4[4]={{-1,0},{1,0},{0,-1},{0,1}};
pair<ll,ll>s8[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1}};
ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll c=power(a,b/2);
	if(b%2==0)
		return ((c%mod)*(c%mod))%mod;
	else
		return ((((c%mod)*(c%mod))%mod)*a)%mod;
}
ll n;
char ch[55][55];
ll dp[55][55][55];
ll func(ll r1,ll r2,ll c1,ll c2)
{
	if(dp[r1][r2][c1][c2]!=-1)
		return dp[r1][r2][c];
	if(r1==r2 || c1>=c2)
		return 0;
	if(ch[r1][c1]=='.')
	{
		//cout<<"-------...............------"<<endl;
		ll hashed[55];
		memset(hashed,0,sizeof(hashed));
		ll ans=mini;
		ll tr[55];
		ll lc[55];
		for(ll xx=0; xx<55; xx++)
		{
			tr[xx]=mini;
			lc[xx]=mini;
		}
		for(ll i=r1+1; i<=r2; i++)
		{
			for(ll j=c1+1; j<=c2; j++)
			{
				if(ch[i-1][j-1]=='#')
				{
					ashed[j-1]=1;
					tr[j-1]=min(tr[j-1],i-1);
					lc[i-1]=min(lc[i-1],j-1);
				}
				if(j-2>=0)
				{
					hashed[j-1]=max(hashed[j-2],hashed[j-1]);
					tr[j-1]=min(tr[j-1],tr[j-2]);
				}
				if(i-2>=0)
					lc[i-1]=min(lc[i-1],lc[i-2]);
				if(hashed[j-1]>0)
				{
					ll hor=i-tr[j-1];
					ll ver=j-lc[i-1];
					ll val=max(hor,ver);
					ans=min(ans,val+min(func(r1,i,j,c2)+func(i,r2,c1,c2),func(r1,r2,j,c2)+func(i,r2,c1,j)));
				}
				else
					ans=min(ans,func(r1,i,j)+func(i,r2,c));
			}
		}
		return dp[r1][r2][c]=ans;
	}
	else
	{
		ll ans=mini;
		for(ll i=r1+1; i<=r2; i++)
		{
			for(ll j=c+1; j<=n; j++)
			{
				ll hor=i-r1;
				ll ver=j-c;
				ll val=max(hor,ver);
				ans=min(ans,val+func(r1,i,j)+func(i,r2,c));
			}
		}
		return dp[r1][r2][c]=ans;
	}
}
int main()
{
	boost
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(ll i=0; i<n; i++)
		for(ll j=0; j<n; j++)
			cin>>ch[i][j];
	cout<<func(0,n,0)<<endl;
	return 0;
}
