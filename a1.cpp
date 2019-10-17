#include<bits/stdc++.h>
#define rep(k,n) for(int i=k;i<n;i++)
using namespace std;
int main()
{
	int ar[105],n,ans=0;
	scanf("%d",&n);
	rep(0,n)
	scanf("%d",&ar[i]);
	sort(ar,ar+n);
	//rep(0,n)
	//printf("%d",ar[i]);
	rep(0,n)
	{
		i+=1;
		ans+=ar[i]-ar[i-1];
	}
	printf("%d",ans);
}