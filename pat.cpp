#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 163577857
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
using namespace std;
ll ar[75][75],n,q,t;
void rev_();
void func1();
void func2(char,ll,ll);
int main()
{
	func2('C',0,0);
	cin>>t;
	while(t--)
	{
		cin>>q>>n;
		if(q==2)
		{
			func1();
			rep(i,0,n)
			{
				rep(j,0,n)
				cout<<ar[i][j]<<" ";
				cout<<"\n";
			}
		}
		if(q==1)
		{
			func2('C',0,0);
			if(n%2==1)
				ar[n/2][n/2]=n*n;
			rep(i,0,n)
			{
				rep(j,0,n)
				cout<<ar[i][j]<<" ";
				cout<<"\n";
			}			
		}
	}
}
void func1()
{
	ll t=0,b=n-1;
	ll tot=1,j;
	rep(k,0,n)
	{
		j=0;
		for(int i=t;i>=0;i--,j++)
		{
			ar[j][i]=tot;
			tot++;
		}
		if(tot!=n*n+1)
		{
			j=0;
			for(int i=t;i>=0;i--,j++)
			{
				ar[n-i-1][n-j-1]=tot;
				tot++;
			}
			t++;
		}	
	}
}
void func2(char ch,ll a,ll m)
{
	if(a==(n/2))
		return;
	if(ch=='C')
	{
		ll tot=0;
		rep(i,a,n-1-a)
		{
			ar[a][i]=4*tot+m+1;
			tot++;
		}
		tot=0;
		rep(i,a,n-1-a)
		{
			ar[i][n-1-a]=m+2+4*tot;
			tot++;
		}
		tot=0;
		for(int i=n-1-a;i>a;i--)
		{
			ar[n-1-a][i]=m+3+4*tot;
			tot++;
		}			
		tot=0;
		for(int i=n-1-a;i>a;i--)
		{
			ar[i][a]=m+4+4*tot;
			tot++;
		}
		func2('A',a+1,m+(n-1-2*a)*4);
	}
	if(ch=='A')
	{
		//cout<<"sfdff ";
		rev_();
		ll tot=0;
		rep(i,a,n-1-a)
		{
			ar[i][a]=m+4*tot+1;
			tot++;
		}
		tot=0;
		rep(i,a,n-1-a)
		{
			ar[n-1-a][i]=m+2+4*tot;
			tot++;
		}
		tot=0;
		for(int i=n-1-a;i>a;i--)
		{
			ar[i][n-1-a]=m+3+4*tot;
			tot++;
		}			
		tot=0;
		for(int i=n-1-a;i>a;i--)
		{
			ar[a][i]=m+4+4*tot;
			tot++;
		}
		rev_();
		func2('C',a+1,m+(n-1-2*a)*4);
	}
}
void rev_()
{
	rep(i,0,n)
	{
		rep(j,0,n)
		{
			ll temp=ar[i][j];
			ar[i][j]=ar[j][i];
			ar[j][i]=temp;
		}
	}		
}