#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
#define pii pair <ll,ll>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define piii pair<double,pair<ll,ll>>
ll q,a,b,m,ar[100],two[55],size_;
ll pos();
ll bin(ll,ll);
ll c,temp,mul,idx,ext,tot;
void print_();
int main()
{
	two[0]=1;
	rep(i,1,55)
	two[i]=(2*two[i-1]);
	cin>>q;
	while(q--)
	{
		cin>>a>>b>>m;
		c=a,temp=a,mul=0;
		if(!pos())
		{
			cout<<"-1\n";
		}
		else
		{
			print_();
			rep(i,0,size_)
				cout<<ar[i]<<" ";
			cout<<"\n";
		}
	}
}

ll pos()
{
	ll flag=0,c=a,temp=a,mul=0;
	size_=0;
	for(int i=0;i<=1000;i++)
	{
		//cout<<temp<<" "<<mul<<"\n";
		if(b>=temp+mul&&b<=temp+mul*m)
		{
			idx=i+1;
			ext=b-temp;
			tot=mul;
			return 1;
		}
		if(b<=temp+mul)
			return 0;
		temp=(c*two[i]);
		mul=two[i];
	}
}
void print_()
{
	ll c=a,temp=a,mul=0,b=0;
	for(int i=0;i<idx;i++)
	{
		ar[size_++]=temp+b;
		temp=c*two[i];
		b=bin((tot+1)/2,ext);
		ext-=((tot+1)/2)*b;
		tot/=2;
	}	
}
ll bin(ll mul,ll tot)
{
	ll low=1,high=m,mid,ans;
	while(low<=high)
	{
		mid=(low+high)/2;
		ll rem=tot-mid*m;
		if(mul<=rem&&rem<=mul*m)
		{
			return mid;
		}
		else if(rem<mul)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
}