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
    ll n;
    cin>>n;
    ll a[4][4] = {{8,9,1,13},{3,12,7,5},{0,2,4,11},{6,10,15,14}};
    ll b[n][n];
    ll i,j;
    ll c[n/2][n/2];
    ll d = 0;
    for(i=0;i<n/2;i++)
    {
        for(j=0;j<n/2;j++)
        {
            c[i][j] = d++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<n/2&&j>=n/2)
            {
                b[i][j] = c[i][j-n/2];
            }
            else if(i>=n/2&&j<n/2)
            {
                b[i][j] = c[i-n/2][j];
            }
            else if(i<n/2&&j<n/2)
                b[i][j] = c[i][j];
            else
                b[i][j] = c[i-n/2][j-n/2];
            
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j] = 4*b[i][j];
            if(i<n/2&&j<n/2)
            {
                b[i][j]++;
            }
            if(i<n/2&&j>=n/2)
            {
                b[i][j]+=2;
            }
            if(i>=n/2&&j<n/2)
            {
                b[i][j]+=3;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}