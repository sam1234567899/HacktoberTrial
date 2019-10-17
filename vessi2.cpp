    #include<bits/stdc++.h>
    #define ll long long int 
    #define pb push_back
    using namespace std;
    const int N=1e5+5;
     
    int main()
    {
    	ll n;
    	cin>>n;
    	ll a[n+5];
    	ll b[n+5];
    	ll i;
    	map<ll,ll>mp;
    	for(i=1;i<=n;i++){
    		cin>>a[i];
    		mp[a[i]]=i;
    	}
     
    	//queue<ll>q;
     
    	for(i=1;i<=n;i++){
    		cin>>b[i];
    		//q.push(b[i]);
    	}
     
    	ll j=1;
    	ll ans=0;
    	//ll cnt=1;
    	bool visited[1000005]={0};
    	for(i=1;i<=n && j<=n;i++)
    	{
    		//ll cnt=0;
    		if(visited[a[i]]==true)
    			continue;
    		if(j<=n &&a[i]==b[j]){
    			j++;
    			continue;
    		}
    		else
    		{
    			while(j<=n && a[i]!=b[j])
    			{
    			
    				//cnt++;
    				ans++;
    				visited[b[j]]=1;
    				j++;
    			}
    			j++;
    		}
    		
    		
    		//ans+=cnt;
    	}
    	cout<<ans<<"\n";
    }
