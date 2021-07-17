#include<bits/stdc++.h>

using namespace std;

vector <int> adj[100];
queue <int> q;
int vis[100];

int bicoloring(int src)
{
    vis[src]=1;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(vis[v]==0)
            {
                if(vis[u]==1)
                    vis[v]=2;
                else
                    vis[v]=1;
                q.push(v);
            }
            else if(vis[v]==vis[u])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<bicoloring(1)<<endl;
//    for(int i=1;i<=node;i++)
//        cout<<vis[i]<<' ';
//    cout<<endl;
    return 0;
}
