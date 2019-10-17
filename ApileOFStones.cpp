#include<bits/stdc++.h>
#include<cstring>
#include<iostream>
using namespace std;
int main()
 {

	int t;
	scanf(" %d",&t);

	string str;

	while(t--)
	{

        getline(cin,str);

	    stack<int> s;

	    for(int i=0;str[i]!='\0';i++)
	    {
	        if(str[i]==' ')
	        continue;

	        if(str[i]!='?')
	        {
	            s.push((int)(str[i]-'0'));
	            cout<<(int)(str[i]-'0')<<"\n";
	        }
	        else
	        {
	            int a=s.top();
	            s.pop();
	            cout<<"pop";

	            int b=s.top();
	            s.pop();
                cout<<"pop";

	            s.push(max((a*b),(a+b)));
	        }
	    }


	    cout<<s.top()<<"\n";
	}
	return 0;
}
