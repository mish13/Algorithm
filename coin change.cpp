#include<bits/stdc++.h>

using namespace std;

int n,coins[10],make,dp[12][107];

int coin_chng(int i,int amnt)
{
    if(i>=n)
    {
        if(amnt==make)
            return 1;
        return 0;
    }
    if(dp[i][amnt]!=-1)
        return dp[i][amnt];
    int ret1=0,ret2=0;
    if(coins[i]+amnt<=make)
        ret1=coin_chng(i,coins[i]+amnt);
    else
        ret1=0;
    ret2=coin_chng(i+1,amnt);
    return dp[i][amnt]=ret1|ret2;

}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&coins[i]);
    }
    for(i=0;i<11;i++)
    {
        for(j=0;j<102;j++)
            dp[i][j]=-1;
    }
    scanf("%d",&make);
    if(coin_chng(0,0))
        printf("Yes\n");
    else
        printf("No\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=make;j++)
        {
            cout<<j<<":"<<dp[i][j]<<' ';
        }
        cout<<endl<<endl;
    }
    return 0;
}
