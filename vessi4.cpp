    #include<bits/stdc++.h>
    #define ll long long int
     
    using namespace std;
    const int mod=1e8;
    ll n1,n2,k1,k2;
    //
    ll dp[101][101][11][11];
     
    ll fun(ll x1,ll x2,ll c1,ll c2)
    {
    	ll &ans=dp[x1][x2][c1][c2];
     
    	if(x1==0 && x2==0)
    		return 1;
     
    	if(ans!=-1)
    		return ans;
    	ans=0;
    	if(x1>0 && c1<k1)
    		ans=(ans+fun(x1-1,x2,c1+1,0))%mod;
    	if(x2>0 && c2<k2)
    		ans=(ans+fun(x1,x2-1,0,c2+1))%mod;
    //	cout<<ans<<"\n";
    	return ans%mod;
    }
     
    int main()
    {
    	cin>>n1>>n2>>k1>>k2;
    	memset(dp,-1,sizeof(dp));
     
    	cout<<fun(n1,n2,0,0)<<"\n";
    }
