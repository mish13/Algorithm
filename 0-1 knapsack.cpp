#include<bits/stdc++.h>

using namespace std;

int wt[100],val[100],dp[100][100],cap,n;

int knapsack(int pos,int w)
{
    if(pos>n)
        return 0;
    int &ret = dp[pos][w];
    ret = knapsack(pos+1, w);
    if(wt[pos] <= w)
        ret = max(ret, val[pos] + knapsack(pos+1, w - wt[pos]));
    return ret;
}

int main()
{
    cin>>n>>cap;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    cout<<knapsack(1,cap)<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

/*
4 10
1 120
4 280
3 150
4 200

output 600
*/
