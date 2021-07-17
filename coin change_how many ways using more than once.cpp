#include<bits/stdc++.h>

using namespace std;

int dp[100000],coin[100];

void coin_change(int n,int k)
{
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i>=coin[j])
            {
                dp[i]+=dp[i-coin[j]];
            }
        }
    }
}

int main()
{
    int make,k;
    cin>>make>>k;
    for(int i=1;i<=k;i++)
        cin>>coin[i];
    coin_change(make,k);
    if(dp[make]!=0)
    {
        cout<<dp[make]<<" ways"<<endl;
    }
    else
        cout<<"impossible"<<endl;
    return 0;
}
