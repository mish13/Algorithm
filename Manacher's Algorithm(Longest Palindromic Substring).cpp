#include<bits/stdc++.h>

using namespace std;

string longestPalindromicSubstring(string s)
{
    int l=0,r=0;
    string newString = "$";
    for(int i=0;i<s.size();i++)
    {
        newString = newString + s[i] + "$";
    }
    int val[newString.size()];
    memset(val,0,sizeof(val));
    for(int i=0;i<newString.size();)
    {
        while(l>0 && r<newString.size() && newString[l-1]==newString[r+1])
        {
            l--;
            r++;
        }
        val[i]=r-l+1;
        if(r>=newString.size()-1)
            break;
        int newCenter = r;
        if(r%2==0)
            newCenter++;
        for(int j=i+1;j<=r;j++)
        {
            val[j]=min(val[i-(j-i)],2*(r-j)+1);
            if(j+val[i-(j-i)]/2 == r)
            {
                newCenter = j;
                break;
            }
        }
        i = newCenter;
        l = i - val[i]/2;
        r = i + val[i]/2;
    }
    int mx=-1,pos;
    for(int i = 0;i<newString.size();i++)
    {
        if(mx<val[i])
        {
            mx=val[i];
            pos=i;
        }
    }
    string ret = "",left="",right="";
    if(newString[pos]!='$')
        ret = ret + newString[pos];
    for(int i=1;i<val[pos]/2;i++)
    {
        if(newString[pos-i]!='$')
            left+=newString[pos-i];
        if(newString[pos+i]!='$')
            right+=newString[pos+i];
    }
    reverse(left.begin(),left.end());
    ret = left + ret + right;

    return ret;
}

int main()
{
    string s,ans;
    cin>>s;
    ans = longestPalindromicSubstring(s);
    cout<<ans<<endl;
}
