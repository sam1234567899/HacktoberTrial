#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define g 9.8
#define MIN(a,b) (a>b?b:a)
#define par 0.5
using namespace std;
ll n,m,ar[405],s,e,con,tot,max_,ans,str[402][402][2];
ll check(ll);
void findmax();
void bin();
int main()
{
	cin>>n>>m;
	rep(i,1,n+1)
	cin>>ar[i];
	rep(i,0,m)
	{
		cin>>s>>e>>con>>tot;
		if(str[s][e][0]==0||(tot<str[s][e][1])||(tot==str[s][e][1]&&con>str[s][e][0]))
		{
			str[s][e][0]=con;
			str[s][e][1]=tot;		
		}
	}
	rep(i,1,401)
	rep(j,i,401)
	{
		if(str[i][j][0]!=0)
		{
			s=i;
			e=j;
			con=str[i][j][0];
			tot=str[i][j][1];
			bin();
			//cout<<"HERE";
		}
	}
	cout<<ans;

}
ll check(ll mid)
{
	ll prev=s;
	ll cnt=0;
	for(int i=s+1;i<=e;i++)
	{
		if(ar[i]-ar[prev]>mid)
		{
			prev=i-1;			
			cnt++;
		}
	}
	if(cnt>tot)
		return 0;
	return 1;
}
void findmax()
{
	ll prev=s;
	max_=0;
	for(int i=s+1;i<=e;i++)
	{
		if(ar[i]-ar[prev]>max_)
			max_=ar[i]-ar[prev];
		prev=i;
	}	
}
void bin()
{
	findmax();
	ll low=max_,high=ar[e]-ar[s],mid;
	//if(e-s<=tot)
	while(low<=high)
	{
		mid=(low+high)/2;
		if(check(mid))
		{
			high=mid-1;
			max_=mid;
		}
		else
			low=mid+1;
	}
	//cout<<"HERE "<<max_<<" "<<con<<"\n";
	if((max_*con)>ans)
		ans=max_*con;
}