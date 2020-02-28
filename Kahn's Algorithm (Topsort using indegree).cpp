#include<bits/stdc++.h>

using namespace std;

int main()
{
    int dependencies;
    vector <int> adj[107],ans;
    int tasks;
    int vis[107],indegree[107];
    cin>>tasks>>dependencies;
    memset(vis,0,sizeof(vis));
    memset(indegree,0,sizeof(indegree));
    for(int i=1;i<=dependencies;i++)
    {
        int p,n,c;
        cin>>c>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p;
            adj[p].push_back(c);  //child is dependent on parent
            indegree[c]++;
        }
    }

    priority_queue <int, vector<int>, greater<int>> nxt,neybr;

    for(int i=1;i<=tasks;i++)
    {
        if(indegree[i]==0)
        {
            nxt.push(i);
        }
    }
    while(!nxt.empty())
    {
        int u = nxt.top();
        nxt.pop();
        ans.push_back(u);
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            neybr.push(v);
            if(!vis[v])
                indegree[v]--;
        }
        while(!neybr.empty())
        {
            int v = neybr.top();
            neybr.pop();
            if(indegree[v]==0)
            {
                nxt.push(v);
            }
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        if(i!=ans.size()-1)
            cout<<ans[i]<<' ';
        else
            cout<<ans[i]<<endl;
    }
    return 0;
}

//input 

//5 4
//3 2 1 5
//2 2 5 3
//4 1 3
//5 1 1

//output

//1 5 3 2 4
