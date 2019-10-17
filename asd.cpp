#include<bits/stdc++.h>

using namespace std;


long long int facto(int n)
{
    long long int ans=1;
    for(long long int i=1;i<=n;i++)
    {
        ans*=i;
    }

    return ans;
}
int nCr(int n, int r)
{
    return facto(n) / facto(n - r);
}
int solve(vector<int> &A, int B, int C) {

    string str=to_string(C);
    sort(A.begin(),A.end());
    //map<int,int> mp;
    if(B==1)
    {
        int count1=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]<C)
            count1++;
        }

        return count1;
    }

    //for(int i=0;i<A.size();i++)
    //{
      //  mp[A[i]]=i+1;
    //}
    if(B<(str.length()))
    {   //cout<<"$$";
        if(A[0]==0)
        {
            return (A.size()-1)*facto(A.size()-1);
        }
        else
        {
            return facto(A.size());
        }
    }
    if(B>str.length())
    return 0;

    long long int ans=0;
    vector<int> removed;
    for(int i=0;i<str.length();i++)
    {
        int no=(int)(str[i]-'0');
       // cout<<no<<" "<<ans<<"\n";
        if(i==0)
        {
            if(A[0]==0)
            {
                ans=ans+(lower_bound(A.begin(), A.end(),no)-A.begin()-1)*(nCr(A.size(),B-i-1));
                //cout<<lower_bound(A.begin(), A.end(),no)-A.begin()<<"\n";

            }
            else
            {
                ans=ans + (lower_bound(A.begin(), A.end(),no)-A.begin())*(nCr(A.size(),B-i-1));
            }
        }
        else
        {
           /* int count=0;
            for(int j=0;j<removed.size();j++)
            {
                if(removed[j]<no)
                count++;
            }*/

            ans=ans+(lower_bound(A.begin(), A.end(),no)-A.begin())*(nCr(A.size(),B-i-1));
        }
       // removed.push_back(no);
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int b;
    cin>>b;
    int c;
    cin>>c;
    cout<<solve(v,b,c)<<"\n";
}
