#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f
#define MIN(a,b) (a>b?b:a)
using namespace std;
int main()
{
	ll t,odd[1005],even[1005],n,x,zero,two[63];
	two[0]=0;
	rep(i,1,63)
	two[i]=(two[i-1]+1)+two[i-1];
	//cout<<two[60];

	cin>>t;
	while(t--)
	{
		zero=1;
		cin>>n;
		ll even=0,odd=0;
		ll make_even=two[62],make_odd=two[62];
		rep(i,0,n)
		{
			cin>>x;
			if(x%2==0)
			{
				even++;
				if(x!=0)
					make_odd=1;
			}	
			else
			{
				odd++;
				if(x!=1)
				{
					rep(i,1,63)
					{
						if((x-(x/(two[i]+1))*(two[i]+1)+1<(two[i]+1))&&(two[i]<x))
						{
							ll ans=x-(x/(two[i]+1))*(two[i]+1)+1;
							make_even=MIN(ans,make_even);
							break;
						}	
					}

				}
			}	
		}
		//cout<<make_even<<" ";
		if((even+odd)%2==0)
			cout<<"0\n";
		else
		{
			if((make_even==two[62])&&(make_odd==two[62]))
				cout<<"-1\n";
			else
				printf("%lld\n",(make_even>make_odd?make_odd:make_even));
		}
	}
}