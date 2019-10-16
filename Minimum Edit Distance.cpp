#include<bits/stdc++.h>

using namespace std;

int editDistance(string word1, string word2)
{
    reverse(word1.begin(),word1.end());
    word1 = word1+"$";
    reverse(word1.begin(),word1.end());
    reverse(word2.begin(),word2.end());
    word2 = word2+"$";
    reverse(word2.begin(),word2.end());
    int val[word1.size()][word2.size()];
    memset(val,0,sizeof(val));
    for(int i=0; i<word1.size(); i++)
    {
        for(int j=0; j<word2.size(); j++)
        {
            if(word1[i]==word2[j])
            {
                if(i==0 && j==0)
                    val[i][j]=0;
                else
                    val[i][j]=val[i-1][j-1];
            }
            else
            {
                if(i-1>=0 && j-1>=0)
                    val[i][j]=min(val[i-1][j-1],min(val[i-1][j],val[i][j-1]))+1;
                else
                {
                    if(i-1<0)
                        val[i][j]=val[i][j-1]+1;
                    else
                        val[i][j]=val[i-1][j]+1;
                }
            }
        }
    }
    return val[word1.size()-1][word2.size()-1];
}

int main()
{
    string word1,word2;
    cin>>word1>>word2;
    cout<<editDistance(word1,word2)<<endl;
}
