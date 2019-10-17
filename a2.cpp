#include<bits/stdc++.h>
#define rep(k,n) for(int i=k;i<n;i++)
using namespace std;
int main()
{
	long long n,ar[200005],max=-1,sum=0,flag=0;
	cin>>n;
	rep(0,n)
	cin>>ar[i];
	rep(0,n)
	{
		if(ar[i]>max)
			max=ar[i];
		sum+=ar[i];
	}
	if((max*n-sum)%2==1)
	{
		if(n%2==1)
			max++;
		else
			flag=1;
	}
	rep(0,n)
	{
		if((max-ar[i])%2==0)
			continue;
		else
		{
			if((ar[i]-ar[i+1])%2==0)
				ar[i+1]++;
			else
				flag=1;
		}
	}
	if(flag==0)
		printf("YES");
	else
		printf("NO");
}