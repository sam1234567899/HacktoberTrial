#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
using namespace std;
typedef struct NODE
{
	ll enm,size_,par;
}NODE;
void initialise();
ll Find(ll);
void Union(ll,ll);
void enemy(ll,ll);
NODE ar[100005];
ll n,m,x,y;
int main()
{
	cin>>n>>m;
	initialise();
	rep(i,0,m)
	{
		cin>>x>>y;
		Union(x,y);
	}
	cin>>m;
	rep(i,0,m)
	{
		cin>>x>>y;
		enemy(x,y);
	}
	ll max_=0;
	rep(i,1,n+1)
	{
		if(ar[i].par==i&&max_<ar[i].size_&&ar[i].enm==0)
			max_=ar[i].size_;
	}
	// rep(i,1,n+1)
	// {
	// 	cout<<ar[i].par<<" "<<ar[i].size_<<" "<<ar[i].enm<<"\n";
	// }
	cout<<max_;
}
void initialise()
{
	rep(i,0,n+1)
	{
		ar[i].par=i;
		ar[i].size_=1;
	}
}
ll Find(ll idx)
{
	if(ar[idx].par==idx)
		return idx;
	return ar[idx].par=Find(ar[idx].par);
}
void Union(ll x,ll y)
{
	ll px=Find(x);
	ll py=Find(y);
	if(px==py)
		return;
	if(ar[px].size_>ar[py].size_)
	{
		ar[py].par=px;
		ar[px].size_+=ar[py].size_;
	}
	if(ar[px].size_<=ar[py].size_)
	{
		ar[px].par=py;
		ar[py].size_+=ar[px].size_;
	}
}
void enemy(ll a,ll b)
{
	ll pa=Find(a);
	ll pb=Find(b);
	if(pa==pb)
	{
		ar[pa].enm=1;
	}
}