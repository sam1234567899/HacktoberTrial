    #include<bits/stdc++.h>
    #define ll long long int
    using namespace std;
    const int N=2e5+5;
    ll dp[N];
    string s;
    //basically i am storing the lis from back for a string 
    //from behind intution is if dp[i]==dp[i+1]+1 your answer will be updated to 0 if its 1;
     
    int main()
    {
    	cin>>s;
    	ll i;
    	ll cnt=0;
    	memset(dp,0,sizeof(dp));
    	ll n=s.size();
    	for(i=n-1;i>=0;i--)
    	{
    		if(s[i]=='1'){
    			cnt++;
    			dp[i]=max(dp[i+1],cnt);
    		}
    		else
    			dp[i]=dp[i+1]+1;
    	}
     
    	for(i=n-1;i>=0;i--)
    	{
    		if(s[i]=='1' && dp[i]==dp[i+1]+1)
    			s[i]='0';
    	}
    	cout<<s<<"\n";
    }
