#include<bits/stdc++.h>

using namespace std;

int dis[100007],low[100007],tym=0,vis[100007],prnt[100007],child,root;
set < pair <int,int> > art_bridge;
vector <int> adj[100007];

void arti(int u)
{
    tym++;
    vis[u]=1;
    low[u]=dis[u]=tym;
    child=0;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        //cout<<u<<" "<<v<<endl;
        if(v==prnt[u])
            continue;
        else
        {
            if(vis[v]==1)
                low[u]=min(low[u],dis[v]);
            else
            {
                prnt[v]=u;
                arti(v);
                low[u]=min(low[u],low[v]);
                //cout<<dis[u]<<".."<<low[v]<<" "<<root<<endl;
                if(dis[u]<low[v])
                {
                    //cout<<"*"<<endl;
                    if(u<v)
                        art_bridge.insert({u,v});
                    else
                        art_bridge.insert({v,u});
                }
                child++;
            }
        }
    }
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,m;
        cin>>n>>m;
        memset(dis,0,sizeof dis);
        memset(low,0,sizeof low);
        memset(vis,0,sizeof vis);
        memset(prnt,0,sizeof prnt);
        for(int i=1; i<100007; i++)
            adj[i].clear();
        art_bridge.clear();
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
                m--;
                if(m==0)
                    break;
            }
            if(m==0)
                break;
        }
        root=1;
        arti(root);
        cout<<(int)art_bridge.size()<<endl;
    }
    return 0;
}
