#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
using namespace std;
ll hun,fif;
int main()
{
	ll n,flag=0,x;
	cin>>n;
	while(n--)
	{
		cin>>x;
		if(x==50)
			fif++;
		if(x==100)
		{
			if(fif<=0)
				flag=1;
			fif--;
			hun++;
		}
		if(x==200)
		{

			if(hun>0)
			{
				if(fif<=0)
					flag=1;				
				hun--;
				fif--;
			}
			else
			{
				if(fif<3)
					flag=1;
				fif-=3;
			}
		}
	}
	if(flag==0)
		cout<<"YES";
	else
		cout<<"NO";
}