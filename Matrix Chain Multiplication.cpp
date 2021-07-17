#include<bits/stdc++.h>

using namespace std;

long long row[107],col[107],dp[107][107],vis[107][107];

long long MCM(long long b,long long e)
{
    if(b>=e)
        return 0;
    if(vis[b][e]==1)
        return dp[b][e];
    long long ans=1000000000000000000;
    //cout<<ans<<endl;
    for(long long mid=b;mid<e;mid++)
    {
        long long op_need1=MCM(b,mid);
        long long op_need2=MCM(mid+1,e);
        long long op_need3=row[b]*col[mid]*col[e];
        long long total=op_need1+op_need2+op_need3;
        ans=min(ans,total);
    }
    //cout<<ans<<"*"<<endl;
    vis[b][e]=1;
    dp[b][e]=ans;
    return dp[b][e];
}

int main()
{
    long long n;
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>row[i]>>col[i];
    }
    cout<<"Number of minimum multiplication is "<<MCM(0,n-1)<<endl;
    return 0;
}
