#include<bits/stdc++.h>

using namespace std;
vector<int> adj[500001];
int color[500001];
int visited[500001];

int bfs(int u,int c)
{
    queue<pair<int,int> > q;
    q.push(make_pair(u,0));

    while(!q.empty())
    {   //cout<<"bb";
        pair<int,int> k=q.front();
        q.pop();
        if(color[k.first]==c)
        return k.second;
        visited[k.first]=1;
        for(int i=0;i<adj[k.first].size();i++)
        {
            if(visited[adj[k.first][i]]==0)
            {
                q.push(make_pair(adj[k.first][i],k.second+1));
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    int node=1;
    for(int i=0;i<500001;i++)
    {
        color[i]=-1;
    }
    while(t--)
    {
        for(int i=0;i<=node;i++)
        {
            visited[i]=0;
            color[i]=-1;
            adj[i].clear();
        }
        int q,c0;
        cin>>q>>c0;
        int a=-1;
        node=1;
        color[node]=c0;
        char tt;
        int u,c;
        while(q--)
        {
            scanf(" %c",&tt);
            cin>>u>>c;
            if(tt=='+')
            {
                node++;
                u=u^(a+1);
                c=c^(a+1);
                adj[u].push_back(node);
                adj[node].push_back(u);
                color[node]=c;
                //cout<<"added\n";
            }
            else
            {
            // for(int i=1;i<=node;i++)
             //{
             //cout<<color[i]<<" ";
             //}
                u=u^(a+1);
                c=c^(a+1);
                //cout<<"ans\n";
                a=bfs(u,c);
                cout<<a<<"\n";
                for(int i=0;i<=node;i++)
                {
                    visited[i]=0;
                }

            }

        }
    }
}
