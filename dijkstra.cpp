#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int dis[100],vis[100];
vector <pair <int,int> > adj[100];
priority_queue < pair<int,int> ,vector <pair <int,int> >, greater <pair <int,int> > > pq;

int dijkstra(int s,int des)
{
    int i;
    for(i=0;i<100;i++)
        dis[i]=1000000000;
    dis[s]=0;
    vis[s]=1;
    pair <int,int> tp;
    tp.first=0;
    tp.second=s;
    pq.push(tp);
    printf("-\n");
    while(!pq.empty())
    {
        printf("*\n");
        tp=pq.top();
        pq.pop();
        vis[tp.second]=1;
        printf("%d-> %d\n",tp.second,tp.first);
        int u=tp.second;
        printf("%d--\n",(int)adj[u].size());
        for(i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].second;
//            printf("%d*-> %d\n",adj[u][i].second,adj[u][i].first);
            if(!vis[v])
            {
                if(dis[u]+adj[u][i].first<dis[v])
                {
                    dis[v]=dis[u]+adj[u][i].first;
                    pair <int,int> nw;
                    nw.first=dis[v];
                    nw.second=v;
                    pq.push(nw);

                }
            }
        }
    }
    return dis[des];
}

int main()
{
    int v,i,j,p,c,w,b,e;
    pair <int,int> cw;
    scanf("%d",&v);
    while(scanf("%d%d%d",&p,&c,&w)!=EOF)
    {
        cw.first=w;
        cw.second=c;
        adj[p].push_back(cw);
        cw.first=w;
        cw.second=p;
        adj[c].push_back(cw);
    }
    for(i=1;i<=v;i++)
    {
        printf("\n%d->\n",i);
        for( j=0;j<adj[i].size();j++)
        {
            printf("%d %d\n",adj[i][j].second,adj[i][j].first);
        }
    }
    scanf("%d%d",&b,&e);
    printf("%d",dijkstra(b,e));
}

/*
input-

9
1 2 4
1 8 8
2 8 11
2 3 8
8 7 1
8 9 7
3 4 7
3 9 2
3 6 4
9 7 6
7 6 2
4 6 14
4 5 9
6 5 10

1 5

output- 21

*/
