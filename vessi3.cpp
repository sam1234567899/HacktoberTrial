#include<bits/stdc++.h>
#define ll long long int
//#define mp make_pair
using namespace std;
ll a[300005];
 
int main()
{
	ll t;
	cin>>t;
	ll n;
	while(t--)
	{
		cin>>n;
		string s;
		cin>>s;
		ll i,j,k,num;
		//
		for(i=0;i<n;i++)
			a[i]=s[i]-'0';
		ll ans[n+5]={0};
		bool flag=true;
		for(num=0;num<10;num++)
		{
			string l="";
			string r="";
			char x;
			for(i=0;i<n;i++)
			{
				x=a[i]+'0';
				if(a[i]<num)
				{
					//x=a[i]+'0';
					l+=x;
					ans[i]=1;
				}
				else if(a[i]==num ) 
				{
					//x=a[i]
					ll var=r.size();
					if(r.size()==0){
						r+=x;
						ans[i]=2;
					}
					else if(var>0 && r[var-1]==x){
						r+=x;
						ans[i]=2;
					}
					else {
						l+=x;
						ans[i]=1;
					}
				}
				//else if(a[i]==num &&  r.size()>0 && r[r.size()-1]==x){
				//	r+=x;
				//	a[i]=2;
				//}
				else if(a[i]>num)
				{
					r+=x;
					ans[i]=2;
				}
			}
			l+=r;
			if(is_sorted(l.begin(),l.end())){
				for(k=0;k<n;k++){
					cout<<ans[k];
					flag=false;
				}
				break;
			}
		}
		if(flag)
		cout<<"-";
		cout<<"\n";
	}
