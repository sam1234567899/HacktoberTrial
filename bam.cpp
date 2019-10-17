#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 1e19
#define MIN(a,b) (a>b?b:a)
using namespace std;
void func();
void tot(ll);
ll ar[50005][2],mem[50005],n,b,size_,lim;
int main()
{
	lim=log(1e19);
	cin>>n>>b;
	func();
	rep(i,0,size_)
	tot(i);
	ll min_=(ll)INF;
	rep(i,0,size_)
	{
		min_=min(min_,mem[i]/ar[i][1]);
	}
	cout<<min_;
}
void func()
{
	ll cnt=0;
	while(b%2==0)
	{
		b/=2;
		cnt++;
	}
	if(cnt!=0)
	{
		ar[size_][0]=2;
		ar[size_++][1]=cnt;
	}
	cnt=0;
	for(ll i=3;i<=sqrt(b);i+=2)
	{
		cnt=0;
		// if(i==5)
		// cout<<" "<<b%i<<"XYZ ";
		if(b%i==0)
		{
			while(b%i==0)
			{
				cnt++;
				b/=i;
			}
			ar[size_][0]=i;
			ar[size_++][1]=cnt;		
		}
	}
	if(b>1)
	{
		ar[size_][0]=b;
		ar[size_++][1]=1;
	}
}
void tot(ll idx)
{
	ll i=1,mul=ar[idx][0];
	while((log(mul)*i)<=lim&&((n>=ar[idx][0])))
	{
		mem[idx]+=n/(ar[idx][0]);
		ar[idx][0]*=mul;
		i++;

	}
}