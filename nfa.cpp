#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
#define fi first
#define se second
using namespace std;
#define mp make_pair
#define piii pair <pair <ll,ll>,pair <ll,ll>>
ll sie[1000005][12],ar[1000005];
void pre();
int main()
{
	pre();
	ll t,l,r,n;
	cin>>t;
	while(t--)
	{
		cin>>l>>r>>n;
		cout<<sie[r][n]-sie[l-1][n]<<"\n";
	}
}
void pre()
{
	rep(i,2,1000002)
	{
		if(ar[i]==0)
		{
			for(int j=i;j<1000005;j+=i)
			{
				ar[j]++;
			}
		}
	}
	//cout<<"GHG";
	sie[1][0]++;
	rep(i,2,1000002)
	{
		rep(j,0,11)
		{
			if(ar[i]==j)
				sie[i][j]+=sie[i-1][j]+1;
			else
				sie[i][j]=sie[i-1][j];
		}
	}		
}