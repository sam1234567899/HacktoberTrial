#include<bits/stdc++.h>
#include<math.h>
#define rep(k,n) for(int i=k;i<n;i++)
#define ll long long
using namespace std;
ll ar[1000005];
int main()
{
	/*long long n,ans=0,max=0,num=1,c;
	cin>>n;
	c=n;
	if(n%2==0)
	{
		num=2;
		while(n%2==0)
			{
				max++;
				n/=2;
			}	
	}
	for(int i=3;i<=sqrt(n);i+=2)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				n/=i;
				ans++;
			}
			num*=i;
			if(ans>max)
				max=ans;
		}
	}
	if(n!=1)
	{
		num*=n;
	}
	ans=0;
	printf("%d",num);
	long long x=num,sqr;
	sqr=num;
	while(sqr<c)
	{
		sqr*=sqr;
	}
	if(sqr!=c)
	ans++;
	x=sqr;
	//printf("S%d %d",(int)sqrt(x),(int)pow(x,0.5));
	long long m=sqrt(x);
	while(x!=1&&(m*m==x))
	{
	//printf("S%lld ",x);		
		x=sqrt(x);

		ans++;
		m=sqrt(x);
	}
	printf(" %d",ans);*/
	ll n,num=1,c,ans=0,l=0;
	cin>>n;
	c=n;
	for(int i=0;i<=n;i++)
	ar[i]=1;
	for(int i=2;i<=n;i++)
	{
		if(ar[i]==1)
		{
			for(int j=2*i;j<=n;j++)
				ar[j]=0;
		}
	}

	//printf("X%lld ",ar[0]);
	for(int i=2;i<=c;i++)
	{
		ar[i]=0;
		if(n%i==0)
		{
			while(n%i==0)
			{
				ar[i]++;
				n/=i;
			}
			num*=i;
		}
	}
	n=c;

	ll flag=0,max=-1,sqr=2;
	rep(2,n+1)
	{
		//printf("Z%lld ",ar[i]);
		if(max<ar[i])
		{
			if(max>0)
				flag=1;
			max=ar[i];	
		}				
		if(ar[i]!=0&&max!=ar[i])
		{
			//printf("M%lld ",i);
			flag=1;		
		}
	

	}
	if(max==1||max==0||max==-1)
		printf("%lld %lld",n,0LL);
	else
	{
		ans=0;
		while(sqr<max)
			sqr*=2;
		if(flag!=0||max!=sqr)
			ans++;
		//printf("A%lld %lld %lld ",max,sqr,flag);
		while(sqr!=1)
			{
				sqr/=2;
				ans++;
			}
		printf("%lld %lld",num,ans);	
	}
}














