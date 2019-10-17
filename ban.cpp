#include<bits/stdc++.h>
#include<fstream>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
#define pii pair<ll,ll>
#define piii pair<pair<ll,ll>,ll>
using namespace std;
#define mp make_pair
#define fi first
#define se second
bool mark[100005];
ll visit[100005],pr[100005],sr[100005],dr[100005];
ll n,x,y;
vector <ll> vr[100005];
vector <pii> cr[100005];
ll cent(ll),getcent(ll,ll,ll);
void dfs(ll,ll,ll),prt(ll,ll);
multiset <ll> ms[100005];
int main()
{
	scanf("%lld",&n);
	rep(i,0,n-1)
	{
		scanf("%lld %lld",&x,&y);
		vr[x].push_back(y);
		vr[y].push_back(x);
	}
	ll p=cent(1);
	ll t;
	scanf("%lld",&t);
	while(t--)
	{	
		ll q,x;
		scanf("%lld %lld",&q,&x);
		if(q==0)
		{
			qr[x]=!qr[x];
			if(qr[x])
			ins(x);
			else
			del(x);
		}
		else
			pri(x);
	}
}
void del(ll x)
{

}	
void ins(ll x,ll d)
{
	ms.insert(ar[])
}
void prt(ll idx,ll p)
{
	ll size_=cr[idx].size();
	cout<<idx<<"  ";
	rep(i,0,size_)
	{
		if(cr[idx][i].fi==p)
			continue;
		cout<<cr[idx][i].fi<<" "<<cr[idx][i].se<<"    ";
	}
	cout<<"\n";
	rep(i,0,size_)
	{
		if(cr[idx][i].fi==p)
			continue;
		prt(cr[idx][i].fi,idx);
	}
}
ll cent(ll s)
{
	dfs(s,-1,1);
	ll v=getcent(s,-1,sr[s]);
	mark[v]=true;
	ll size_=vr[v].size();
	rep(i,0,size_)
	{
		if(mark[vr[v][i]])
			continue;
		ll x=cent(vr[v][i]);
		cr[v].push_back(mp(x,dr[x]));
		pr[x]=v;
	}
	return v;
}
ll getcent(ll s,ll p,ll tot)
{
	ll size_=vr[s].size();
	rep(i,0,size_)
	{
		if(vr[s][i]==p)
			continue;
		if(mark[vr[s][i]])
			continue;
		if(sr[vr[s][i]]>tot/2)
			return getcent(vr[s][i],s,tot);
	}
	return s;
}
void dfs(ll idx,ll p,ll d)
{
	ll size_=vr[idx].size();
	sr[idx]=1;
	dr[idx]=d;
	rep(i,0,size_)
	{
		if(vr[idx][i]==p)
			continue;
		if(mark[vr[idx][i]])
			continue;
		dfs(vr[idx][i],idx,d+1);
		sr[idx]+=sr[vr[idx][i]];
	}
}