#include<bits/stdc++.h>

using namespace std;

int coin[100],make;

int dp[100000];

void coin_change(int n,int k)
{
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i>=coin[j])
            {
                dp[i]|=dp[i-coin[j]];
            }
        }
    }
}

int main()
{
    int k,make;
    cin>>make>>k;
    for(int i=1;i<=k;i++)
        cin>>coin[i];
    coin_change(make,k);
    if(dp[make])
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
