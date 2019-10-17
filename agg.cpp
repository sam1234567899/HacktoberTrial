#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007LL
#define ROD 100000000ll
#define INF 123456789123456ll
#define MIN(a,b) (a>b?b:a)
using namespace std;
#define mp make_pair
#define  piii pair<pair<ll,ll>,pair<ll,ll>>
#define pii pair<ll,ll>
#define fi first
#define se second
ll n,k,mr[200005],one,zero;
char c;
void mark(ll),unmark(ll);
ll ans[200005],ar[200005];
int main()
{
	scanf("%lld %lld",&n,&k);
	rep(i,0,n)
	{
		scanf(" %c",&c);
		ar[i]=(c=='W');
	}

	if(2*k+1>n)
	{
		ll f=1;
		rep(i,0,n)
		if(ar[i]==0)
			zero++;
		rep(i,0,n)
		cout<<(zero<=one-zero)?'W':'B';
	}
	else
	{
		ll l=0,r=0;
		mark(0);
		rep(i,0,k)
		{
			l--;
			r++;
			mark(l);
			mark(r);
		}
		rep(i,0,n)
		{
			//cout<<i<<" "<<one<<" "<<zero<<"\n";
			cout<<(one>zero?'W':'B');
			unmark(l);
			l++;
			r++;
			mark(r);
		}
	}

}
void unmark(ll idx)
{
	idx%=n;
	idx=(idx+n)%n;
	if(ar[idx])
		one--;
	else
		zero--;
}
void mark(ll idx)
{
	idx%=n;
	idx=(idx+n)%n;
	if(ar[idx])
		one++;
	else
		zero++;
}