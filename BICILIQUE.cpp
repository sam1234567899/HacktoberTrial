#include<bits/stdc++.h>

using namespace std;
vector<int> adj[2000];

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n,m,k;
        cin>>n>>m>>k;
        int a[n+1][n+1];
        int b[n+1][n+1];
        int c[n+1][n+1];
        /*for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                a[i][j]=0;
                b[i][j]=0;
                c[i][j]=0;
            }
        }*/

        memset(a, 0, sizeof(a[0][0]) * (n+1)*(n+1));
        memset(b, 0, sizeof(b[0][0]) * (n+1)*(n+1));

        int x,y;
        while(m--)
        {
            cin>>x>>y;
            a[x][y]=1;
            a[y][x]=1;
            b[x][y]=1;
            b[y][x]=1;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int i, j, kk;
        int flag=0;
        for (i = 1; i < n+1; i++)
        {
            for (j = i+1; j < n+1; j++)
            {
            if(adj[i].size()<k||adj[j].size()<k)
            continue;

            //a[i][j] = 0;
            int count1=0;
            for (kk = 1; kk < n+1; kk++)
               {
                    if(a[i][kk]&&a[kk][j])
                    count1++;

                    if(count1>=k)
                    {
                        flag=1;
                        break;
                    }
                }

                if(flag==1)
                break;

            }
            if(flag==1)
            break;
        }



    if(flag==1)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}
