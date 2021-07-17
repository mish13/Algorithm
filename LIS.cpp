#include<bits/stdc++.h>

using namespace std;

struct pr
{
    int own,pr,val;
};

pr tmp;

bool cmp(pr a,int x)
{
    return a.val<x;
}

int parent[1000];

void print(int o,vector <int> vt)
{
    if(parent[o]==-1)
        return;
    print(parent[o],vt);
    cout<<vt[o]<<' ';
}

int main()
{
    int n,x;
    cin>>n;
    vector <int> vt;
    vector <pr> ans;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        vt.push_back(x);
        vector <pr>::iterator it;
        it=lower_bound(ans.begin(),ans.end(),x,cmp);
        while(it!=ans.end() && ans[it-ans.begin()].val==ans[it-ans.begin()+1].val)
            it++;
        if(it==ans.end())
        {
            if(ans.size()==0)
            {
                tmp.val=x;
                tmp.pr=-1;
                tmp.own=i;
                parent[i]=-1;
            }
            else
            {
                tmp.val=x;
                tmp.pr=ans[(int)ans.size()-1].own;
                tmp.own=i;
                parent[i]=ans[(int)ans.size()-1].own;
            }
            ans.push_back(tmp);
        }
        else
        {
            if(ans[it-ans.begin()].val!=x)
            {
                tmp.val=x;
                if(it!=ans.begin())
                {
                    tmp.pr=ans[it-ans.begin()-1].own;
                    parent[i]=ans[it-ans.begin()-1].own;
                }
                else
                {
                    tmp.pr=-1;
                    parent[i]==-1;
                }
                tmp.own=i;
                ans[it-ans.begin()]=tmp;
            }
            else
            {
                tmp.val=x;
                tmp.pr=ans[it-ans.begin()].own;
                tmp.own=i;
                parent[i]=ans[it-ans.begin()].own;
                ans.insert(it,tmp);
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<parent[i]<<' ';
    cout<<ans.size()<<endl;
    print(ans[(int) ans.size()-1].own,vt);
    return 0;
}
