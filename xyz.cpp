#include<bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ll n;
	string s;
	cin>>n>>s;
	//


	ll i,j;
	vector<ll>bc;
	ll ans=n*(n-1)/2;

	for(i=0;i<n;)
	{
		j=i;

		while(j<n && s[i]==s[j]){
			j++;
		}
		bc.pb(j-i);
		i=j;
	}
	ll val=0;
	for(i=0;i<bc.size()-1;i++)
	{
		val=val+bc[i]+bc[i+1]-1;
	//	cout<<bc[i]<<" "<<bc[i+1]<<"\n"
		//ek jyada minus kar diya usko plus kiya :)
	}
	cout<<ans-val<<"\n";
}
