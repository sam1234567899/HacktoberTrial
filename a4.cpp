#include<bits/stdc++.h>
#include<math.h>
#define rep(k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
using namespace std;
ll ar[1000005];
int main()
{
	int n,q,x,y;
	int ar[100005];
	char str[100005];
	scanf("%d %d",&n,&q);
	getchar();
	ar[0]=0;
	rep(1,n+1)
	{
		str[i]=getchar();
		if(str[i]=='1')
			ar[i]=1;
		else
			ar[i]=0;
		ar[i]+=ar[i-1];
	}
	long long ans,po[100005];
	po[0]=1;
	for(int i=1;i<=n;i++)
			po[i]=(2*po[i-1])%MOD;
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&x,&y);
		ans=(((po[ar[y]-ar[x-1]]-1)*(po[y-x+1-(ar[y]-ar[x-1])])))%MOD;
		printf("%lld\n",ans);
	}
}