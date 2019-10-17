    #include<bits/stdc++.h>
    #define ll long long int 
    using namespace std;
    int main()
    {
    	ll n;
    	cin>>n;
     
    	ll a[n+5];
    	ll hsh[150005]={0};
    	
    	ll i;
    	ll maxi=0;
    	for(i=0;i<n;i++)
    	{
    		cin>>a[i];
    		maxi=max(maxi,a[i]);
    		//hsh[a[i]]++;
    	}
    	ll ans=0;
    	sort(a,a+n);
    	for(i=0;i<n;i++)
    	{
    		if(a[i]==1)
    		{
    			if(hsh[a[i]]==0)
    			{
    				ans++;
    				hsh[a[i]]=1;
    			}
    			else if(hsh[a[i]+1]==0)
    			{
    				ans++;
    				hsh[a[i]+1]=1;
    			}
    		}
    		else
    		{
    			for(ll j=-1;j<2;j++)
    			{
    				if(hsh[a[i]+j]==0)
    				{
    					ans++;
    					hsh[a[i]+j]=1;
    					break;
    				}
    			}
     
    		}
    	}
    	cout<<ans<<"\n";
    }
