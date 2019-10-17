#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
using namespace std;
ll flag,city[402],trk[250002][4],n,m,max_,full,endc,con;
void func(ll);
void bin(ll,ll);
ll check(ll,ll,ll);
int main()
{
	cin>>n>>m;
	rep(i,1,n+1)
	cin>>city[i];
	rep(i,1,m+1)
	{
		rep(j,0,4)
		cin>>trk[i][j];
		func(i);
	}
	cout<<max_;
}
void func(ll idx)
{
	endc=trk[idx][1];
	con=trk[idx][2];
	if(check(trk[idx][0],max_,trk[idx][3])==0)
	{
		bin(idx,max_);
	}
}
/*void bin(ll idx,ll low)
{
	ll high=(city[trk[idx][1]]-city[trk[idx][0]])*trk[idx][2],mid,ans;
	endc=trk[idx][1];
	con=trk[idx][2];	
	while(low<=high)
	{
		mid=(low+high)/2;
		full=mid;
		flag=0;
		if(check(trk[idx][0],mid,trk[idx][3]))
		{
			high=mid-1;
			max_=mid;
		}
		else
			low=mid+1;
	}
}*/
ll check(ll c,ll fuel,ll r)
{
	if(flag==1||r<0)
		return 0;
	if(fuel<0)
		return 0;
	if(c==endc)
	{
		if(fuel>=0)
		{
			flag=1;
			return 1;
		}	
	}
	return check(c+1,fuel-(city[c+1]-city[c])*con,r)+check(c+1,full-(city[c+1]-city[c])*con,r-1);
}