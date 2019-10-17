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
ll n,ar[300005],c=100005,k,x;
int main()
{
	cin>>n>>k;
	k+=c;
	rep(i,0,n)
	{
		cin>>x;
		ar[x+c]=1;
	}
	ll ans=0;
	rep(i,0,300005 )
	{
		if(ar[i])
			ans++;
	}	
	ll flag=0,a=-1,b=-1;
	rep(i,0,k)
	if(ar[i])
		a=max(a,(ll)i);
	rep(i,k+1,300005)
		if(ar[i]==1)
		{
			b=i;
			break;
		}
	if(ar[k]==0&&(k-a)==(b-k))
		flag=1;
	cout<<ans-flag;
}