#include<bits/stdc++.h>

using namespace std;

int dp[1007][1007];
stack <char> st;

int lcs(string s1,string s2,int len1,int len2)
{
    memset(dp,0,sizeof dp);
    for(int i=-1;i<len2;i++)
    {
        for(int j=-1;j<len1;j++)
        {
            if(i+1!=0 && j+1!=0)
            {
                if(s2[i]==s1[j])
                    dp[i+1][j+1]=dp[i][j]+1;
                else
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            }
            else
            {
                dp[i+1][j+1]=0;
            }

        }
    }
    while(!st.empty())
        st.pop();
    return dp[len2][len1];
}

void print(int i,int j,string s1,string s2)
{
    if(i<0 || j<0 || !dp[i+1][j+1])
        return;
    if(s2[i]==s1[j])
    {
        st.push(s1[j]);
        print(i-1,j-1,s1,s2);
    }
    else
    {
        if(dp[i][j+1]==dp[i+1][j+1])
            print(i-1,j,s1,s2);
        else
            print(i,j-1,s1,s2);
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    return;
}

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        cout<<lcs(s1,s2,s1.size(),s2.size())<<endl;
        //print(s2.size()-1,s1.size()-1,s1,s2);
        //cout<<endl;
    }
    return 0;
}
