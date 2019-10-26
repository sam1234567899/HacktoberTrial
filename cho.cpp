#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
using namespace std;
ll l[55],x,ar[100005];
ll func(ll);
ll n,m,t;
int main()
{
 
	cin>>t;
	ll ans=0;
	while(t--)
	{
		ans=0;
		rep(i,0,52)
		l[i]=0;
		cin>>n>>m;
		rep(i,0,n)
		{
			char c;
			scanf("  %c",&c);
			ar[i]=c;
			if(ar[i]<90)
				ar[i]-=65;
			else
				ar[i]=ar[i]-97+26;
		}
		ll mid,low=0,high=n;
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
		//rep(i,0,6)
		//cout<<l[i]<<" ";
		cout<<ans<<"\n";
	}
}
ll func(ll mid)
{
	ll flag=0,max=0;
	
	rep(i,0,52)
	l[i]=0;		
	
	rep(i,0,mid)
	l[ar[i]]++;
	
	rep(i,0,52)
	if(l[i]>max)
		max=l[i];
 
	if((mid-max)<=m)
		return 1;
 
	rep(i,mid,n)
	{
		l[ar[i-mid]]--;
		l[ar[i]]++;
		
		rep(i,0,52)
		if(l[i]>max)
			max=l[i];
 
		if((mid-max)<=m)
			return 1;		
	}
	return 0;
}