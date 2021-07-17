#include<bits/stdc++.h>

using namespace std;

int dp[1000][1000];

int edit_distance(string s1,string s2,int len1,int len2)
{
    memset(dp,0,sizeof dp);
    for(int i=-1;i<len2;i++)
    {
        for(int j=-1;j<len1;j++)
        {
            if(i==-1 || j==-1)
            {
                if(j==-1)
                    dp[i+1][j+1]=i+1;
                else
                    dp[i+1][j+1]=j+1;
            }
            else
            {
                if(s1[j]==s2[i])
                {
                    dp[i+1][j+1]=dp[i][j];
                }
                else
                    dp[i+1][j+1]=min(dp[i+1][j],min(dp[i][j+1],dp[i][j]))+1;
            }
        }
    }
    return dp[len2][len1];
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<edit_distance(s1,s2,s1.size(),s2.size())<<endl;
    for(int i=0;i<=s2.size();i++)
    {
        for(int j=0;j<=s1.size();j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
