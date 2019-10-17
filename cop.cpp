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

int main()
{
    ll t;
    cin>>t;
    ll n,m;
    cin>>n>>m;
    ll a[n][m],ans[n*m+1] = {0};
    ll i,j;
    for(i=1;i<=n*m;i++)
    {
        for(j=0;j<n*m;j+=i)
        {
            if(a[j/m][j%m]!=i)
                ans[i]++;
            a[j/m][j%m] = i;
            if(a[j%n][j/n]!=i)
                ans[i]++;
            a[j%n][j/n] = i;
        }
    }
    for(i=1;i<=n*m;i++)
    {
        cout<<ans[i]<<" ";
        ans[i] = 0;
    }
    cout<<"\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i][j] = 0;
        }
    }  
    return 0;
}