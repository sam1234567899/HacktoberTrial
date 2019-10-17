#include<bits/stdc++.h>
using namespace std;
#define mod                   1000000007
#define ll                    long long
#define Author                std::ios_base::sync_with_stdio(0);
#define NIKHIL_SETHI          cout.tie(0);
#define MNNIT_ALLAHABAD       cin.tie(0);
#define umii                  unordered_map<ll,ll>
#define mii                   map<ll,ll>
#define pii                   pair<ll,ll>
#define all(v)                v.begin(),v.end()
#define forP(i,j,k)           for(i=j; i<k; i++)
#define forN(i,j,k)           for(i=j; i>k; i--)
#define pb(a)                 push_back(a)
#define lb(v,t)               lower_bound(all(v),t)-v.begin()
#define ub(v,t)               upper_bound(all(v),t)-v.begin()
#define inf 1e18
 
//mainly used functions
bool prime[10000001];
ll abst(ll a){if(a<0)return -a; return a;}
ll power(ll a, ll b){ll res=1;while(b){if(b&1)res=res*a;a=a*a;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
ll lcm(ll a, ll b){return a*b/__gcd(a,b);}
ll ncr(ll n, ll r){ll p=1;ll i;for(i=1; i<=r; i++){p*=(n-i+1);p*=i;}return p;}
void sieve(){ll i;ll j;memset(prime,true,10000000);prime[0]=prime[1]=false;for(i=2; i*i<=10000000; i++){if(prime[i]){for(j=2*i; j<=10000000; j+=i){prime[j]=false;}}}}


bool isprime(ll p)
{
	ll i;
	for(i=2;i*i<=p;i++)
	{
		if(p%i==0)
			return false;
	}
	return true;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k,x;
		cin>>n;
		ll a[n],i,ans = 0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			ans += a[i];
		}
		cin>>k>>x;
		vector <ll> v;
		for(i=0;i<n;i++)
		{
			ll b = a[i]^x;
			b = b-a[i];
			v.pb(b);
		}
		sort(v.begin(),v.end(),greater <ll>());
		ll c1 = 0,sum = 0;
		for(i=0;i<v.size();i++)
		{
			if(v[i]>=0)
			{
				c1++;
				sum += v[i];
			}
			else
				break;
		}
		ll index = i;
		if(k<c1)
		{
			if((k^c1)%2==0)
			{
				cout<<ans+sum<<"\n";
			}
			else
			{
				if(index==n)
				{
					cout<<ans+sum-v[index-1]<<"\n";
				}
				else
				{
					if(v[index-1]>abst(v[index]))
						cout<<sum+ans<<"\n";
					else
						cout<<ans+sum-v[index-1]<<"\n";
				}
			}
		}
		else if(k==c1)
		{
			cout<<ans+sum<<"\n";
		}
		else
		{
			ll c = 0;
			while(c<(k-c1))
			{
				sum += v[index];
				index++;
				c++;
			}
			if(sum>0)
				cout<<ans+sum<<"\n";
			else
				cout<<ans<<"\n";
		}
	}
}