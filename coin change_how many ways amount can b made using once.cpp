
#include<bits/stdc++.h>

using namespace std;

int dp_n2[1000][1000],coin[100],dp_n[100000];

void coin_change_On2(int n,int k)
{
    dp_n2[0][0]=1;
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dp_n2[j-1][i]>0)
                dp_n2[j][i]+=dp_n2[j-1][i];
            if(i>=coin[j] && dp_n2[j-1][i-coin[j]]>0)
                dp_n2[j][i]+=dp_n2[j-1][i-coin[j]];
        }
    }
}

void coin_change_On(int n,int k)
{
    dp_n[0]=1;
    for(int j=1;j<=k;j++)
    {
        for(int i=n;i>=1;i--)
        {
            if(dp_n[i]>0)
                dp_n[i]=dp_n[i];
            if(i>=coin[j] && dp_n[i-coin[j]]>0)
            {
                dp_n[i]+=dp_n[i-coin[j]];
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
    coin_change_On(make,k);
    if(dp_n[make]!=0)
    {
        cout<<dp_n[make]<<" ways"<<endl;
    }
    else
        cout<<"impossible"<<endl;
    return 0;
}
