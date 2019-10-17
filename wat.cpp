#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
using namespace std;
ll func(ll);
ll t,n,ar[100005],low,high,mid,k,gap,mingap,ans;
int main()
{
	cin>>t;
	while(t--)
	{
		mingap=INF;
		cin>>n;
		rep(i,0,n)
		cin>>ar[i];
		low=0;
		high=ar[n-1];

		while(low<=high)
		{
			mid=(low+high)/2;
			gap=INF;
			if(func(mid)==1)
			{
				ans=mid;
				mingap=gap;
				low=mid+1;
			}
			else
				high=mid-1;
		}
		if(n!=1)
		cout<<ans<<" "<<mingap+1<<"\n";
		else
			cout<<ar[0]-1<<" "<<ar[0]<<"\n";

	}
}
ll func(ll mid)
{
	ll s=1;
	rep(i,0,n)
	{
		if(ar[i]<s)
			return 0;
		if((ar[i]-s)<gap)
			gap=ar[i]-s;

		s+=mid;
	}
	return 1;
}