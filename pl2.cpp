#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
using namespace std;
char grid[1000][1000],ar[1005];
ll check(ll,ll);
ll n;
int main()
{
	cin>>n;
	rep(i,0,n)
	rep(j,0,n)
	scanf(" %c",&grid[i][j]);
	ll cnt=0,max=0;
	for(int i=0;i<n;i++)
	{
		if(ar[i]!=-1)
		for(int j=0;j<n;j++)
		{
			if(grid[i][j]=='T')
			{

				if(i!=j&&check(i,j)==1)
				{
					cnt=0;
					break;
				}	
				else
				{
					cnt++;
					ar[j]=-1;
				}	
				//cout<<j<<" "<<cnt<<"\n";
			}
		}	
		if(cnt>max)
		{
			max=cnt;
			cnt=0;
		}		
	}
	printf("%lld",max);

}
ll check(ll i,ll j)
{
	rep(k,0,n)
	if(grid[i][k]!=grid[j][k])
		return 1;
	return 0;
}