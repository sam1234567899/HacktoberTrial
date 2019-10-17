#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 12345678123456
#define MIN(a,b) (a>b?b:a)
using namespace std;
#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define MIN(a,b) (a>b?b:a)
#define fi first
#define se second
using namespace std;
#define mp make_pair
#define pii pair <ll,ll>
#define piii pair <pair <ll,ll>,pair <ll,ll>>
ll n,ar[300005],ans[300005],tot,size_;
set <ll> s;
int main()
{
	cin>>n;
	rep(i,1,n+1)
	{
		cin>>ar[i];
	}
	s.insert(ar[1]);
	ans[ar[1]]=1;
	rep(i,2,n+1)
	for(auto itr=s.begin();itr!=s.end();itr++)
	{
		ll x=*itr;
		if(ar[i]*x<=300005&&ans[ar[i]*x]==0)
		{
			ans[ar[i]*x]=i;
			s.insert(ar[i]*x);
		}
		if(ans[ar[i]]==0)
		{
			s.insert(ar[i]);
			ans[ar[i]]=i;
		}
	}
	rep(i,1,n+1)
	cout<<ans[ar[i]]<<" ";
}