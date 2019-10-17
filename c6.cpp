#include<bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 998244353
using namespace std;
ll func(ll mid);
ll n;
char str[100005];
int main()
{
	cin>>n;
	scanf("%s",str);
	ll low=0,high=0,mid,ans=0;	
	rep(i,0,n)
	if(str[i]=='G')
		high++;
	//high--;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(func(mid)==1)
		{
			low=mid+1;
			ans=mid;
		}
		else
			high=mid-1;
	}
	printf("%lld",ans);
}
ll func(ll mid)
{
	ll cnt=0;
	rep(i,0,mid)
	if(str[i]=='G')
		cnt++;
	if(cnt>=mid-1)
		return 1;

	rep(i,mid,n)
	{
		if(str[i-mid]=='G')
			cnt--;
		if(str[i]=='G')
			cnt++;
		if(cnt>=mid-1)
			return 1;
	}
	return 0;
}