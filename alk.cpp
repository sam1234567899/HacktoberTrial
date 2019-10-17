#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define ROD 1000000009
#define INF 12345678
#define MIN(a,b) (a>b?b:a)
using namespace std;
#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define mp make_pair
#define  pii pair <ll,ll> 
ll n,m,x;
int mem[1004][1004][6][2];
char ar[1005][1005];
ll func(ll,ll,ll,ll);
int main()
{
	cin>>n>>m>>x;
	x++;
	rep(i,0,n)
	{
		scanf(" %s",ar[i]);
	}
	ll cnt=0;
	memset(mem,-1,sizeof(mem));
	if(n==1)
	{
		ll ans=0;
		rep(i,0,m)
		{
			if(ar[0][i]=='#')
			{
				ans=-1;
				break;
			}
			if(ar[0][i]=='*')
				ans++;
		}
		if(m<=x)
			cout<<ans;
		else
			cout<<"-1";
		return 1;
	}
	ll ans=func(0,0,0,0);
	if(ans<0)
		cout<<"-1\n";
	else
	cout<<ans;
}
ll func(ll row,ll entr,ll exit,ll type)
{
	//cout<<row<<" "<<entr<<" "<<exit<<"\n";
	if(exit>=x)
		return -1*INF;
	exit=entr+(type==1?1:-1)*exit;
	if(mem[row][entr][exit][type]!=-1)
		return mem[row][entr][exit][type];
	if(row>=n)
		return -1*INF;
	if(row==n-1)
	{
		if(exit!=m-1||(m-1-entr)>=x)
			return -1*INF;
		ll cnt=0;
		rep(i,entr,m)
		{
			if(ar[row][i]=='*')
			cnt++;
			if(ar[row][i]=='#')
			return -1*INF;
		}	
		return cnt;
	}	
	if(row==0)
	{
		ll p=0;
		rep(i,0,min(x,m))
		{
			if(ar[row][i]=='#')
				break; 
			p++;		
		}	
		ll temp,cnt=0,ans=-1*INF;
		rep(i,0,p)
		{
			if(ar[row][i]=='*')
				cnt++;
			temp=cnt;
			rep(j,0,p)
			{
				if(j>i&&ar[row][j]=='*')
					cnt++;
				//cout<<cnt<<"SS\n";
				ans=max(ans,func(1,i,abs(j-i),j>i)+cnt);
			}	
			cnt=temp;
		}	
		return mem[row][entr][exit][type]=ans;
	}
	ll cnt1=0,cnt2=0,ans=-1*INF;
	for(int i=entr;i<min(min(x+entr,x+exit),m);i++)
	{
		if(ar[row][i]=='#')
			break;
		if(ar[row][i]=='*')
			cnt1++;
		cnt2=0;
		for(int j=exit;j<min(min(x+entr,x+exit),m);j++)
		{
			if(ar[row][j]=='#')
				break;
			if(j>i&&ar[row][j]=='*')
				cnt2++;
			ans=max(ans,func(row+1,i,abs(j-i),j>i)+cnt1+cnt2);
			// if(cnt1+cnt2>1)
			// cout<<cnt1<<"XXXXXXX"<<cnt2<<"\n";
		}
		return mem[row][entr][exit][type]=ans;
	}
}