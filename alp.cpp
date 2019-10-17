#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000000LL
#define INF 0x3f3f3f3f3f3f3f3f
#define g 9.8
#define MIN(a,b) (a>b?b:a)
#define par 0.5
using namespace std;
ll func(ll);
ll ar[2000005];
int main()
{
	rep(i,1,2000005)
	{
		ar[i]=func(i);
		ar[i]+=ar[i-1];
	}
	ll t;
	//cout<<ar[2000000]<<" ";
	cin>>t;
	while(t--)
	{
		ll l,r;
		cin>>l>>r;
		if(l>r)
			swap(l,r);
		cout<<ar[r]-ar[l-1]<<"\n";
	}
}
ll func(ll idx)
{
	ll  v,ans=0;
	while(idx!=0)
	{
		v=idx%16;
		idx/=16;
		if(v>=10)
			ans++;
	}
	return ans;
}