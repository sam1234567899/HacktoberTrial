#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
using namespace std;
#define INF 0x3f3f3f3f3f3f3LL
#define MAX(a,b) (a>b?a:b)
ll mem[202][202][202];
ll n,k,x,ar[205];
ll func(ll,ll,ll);
int main()
{
	rep(i,0,200)
	rep(j,0,200)
	rep(k,0,200)
	mem[i][j][k]=-1;

	cin>>n>>k>>x;
	rep(i,0,n)
	cin>>ar[i];
	printf("%lld",func(0,0,1)>0?func(0,0,1):-1);


}
ll func(ll idx,ll used,ll prev)
{
	if(used>x)
		return -1*INF;	
	if(idx==n)
		return 0;
	
	if(mem[idx][used][prev]!=-1)
		return mem[idx][used][prev];

	if(prev==k)
		return mem[idx][used][prev]=func(idx+1,used+1,1)+ar[idx];

	return mem[idx][used][prev]=MAX(func(idx+1,used+1,1)+ar[idx],func(idx+1,used,prev+1));
}