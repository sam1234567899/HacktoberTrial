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
    //ll x[2*n+2] = {0};
    //ll y[2*n+2] = {0};
    vector <ll> x[2*n+1],y[2*n+1];
    ll a,b;
    vector <pair<ll,ll>> v;
    ll i;
    for(i=1;i<=2*n+1;i++)
    {
        cin>>a>>b;
        v.push_back({a,b});
        x[a].pb(i);
        y[b].pb(i);
    }
    ll vis[2*n+1] = {0};
    ll j;
    ll total = 0;
    for(i=1;i<=2*n+1;i++)
    {   
        ll c1 = 0;
        ll c2 = 0;
        if(x[i].size()>1)
        {
            for(j=0;j<x[i].size();j++)
            {
                if(vis[x[i][j]]==0)
                {
                    vis[x[i][j]] = 1;
                    c1++;
                }
            }
        }
        if(y[i].size()>1)
        {
            for(j=0;j<y[i].size();j++)
            {
                if(vis[y[i][j]]==0)
                {
                    vis[y[i][j]] = 1;
                    c2++;
                }
            }
        }
        total += c1/2+c2/2;
    }
    cout<<total<<"\n";
    /*for(i=0;i<v.size();i++)
    {
        a = v[i].first;
        b = v[i].second;
        ll c1 = 0;
        ll c2 = 0;
        if(x[a]%2==0)
        {
            c1++;
        }
        if(y[b]%2==0)
        {
            c2++;
        }
        if((total-(c1+c2))<n)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"OK\n";
        }
    }*/
    return 0;
}