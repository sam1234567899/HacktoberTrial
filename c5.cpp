#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 998244353
using namespace std;
ll mem[10][10][1005],p[1005],s[1005],st[1005],ct[1005],t,n,k;
ll func(ll,ll,ll);
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		rep(i,0,n)
		cin>>p[i];
		rep(i,0,n)
		cin>>s[i];
		rep(i,0,n)
		cin>>st[i];
		rep(i,0,n)
		cin>>ct[i];	
		ll min=0x3f3f3f3f,ans=-1;
		rep(i,0,10)
		rep(j,0,10)
		rep(k,0,1005)
		mem[i][j][k]=-2;
		rep(i,0,n)
		{
			if(p[i]==0)
			{
				ans=func(i,ct[i]-1,s[i]);
				if(ans<min)
				min=ans;
			}	
		}
		printf("%lld\n",min<=1000?min:-1);
	}
}
ll func(ll idx,ll left,ll pos)
{
	//cout<<idx<<" "<<left<<" "<<pos<<"\n";
	if(left<0)
	return 0x3f3f3f3f;
	
	if(mem[idx][left][pos]!=-2)
	return mem[idx][left][pos];
	
	ll time_=st[idx]+(pos-p[idx])/s[idx];
	ll ans=0x3f3f3f3f,min=0x3f3f3f3f;
	ll flag=1;
	
	if(pos>=k)
	return 0;
	
	if(ct!=0)
	min=func(idx,left-1,pos+s[idx]);

	rep(i,0,n)
	{
		if(i!=idx&&st[i]<=time_&&pos==p[i]+(time_-st[i])*s[i])
		{
			ans=1+func(i,ct[i]-1,pos+s[i]);
			if(ans<min)
				min=ans;			
		}
	}
	return mem[idx][left][pos]=min;
}