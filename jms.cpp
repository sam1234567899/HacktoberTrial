#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int aa[n+1][n+1];
    memset(aa,sizeof(aa),0);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        aa[a][b]=1;
        aa[b][a]=1;

    }
    int c,d,k,sum=0,flag=0;
     for (c = 1; c < n+1; c++) {
      for (d = 1; d < n+1; d++) {
        for (k = 1; k < n+1; k++) {
          sum = sum + aa[c][k]*aa[k][d];


        }

        if(sum>=k&&c!=d)
          {
          flag=1;
          break;
          }
        aa[c][d] = sum;
        sum = 0;
      }
      if(flag==1)
          break;
    }

    if(flag==1)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}
