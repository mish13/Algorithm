#include<cstdio>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int n,lim;
char line[27];
vector <char> vt;
int chk[27]={0};
void permu(int pos)
{
    int i,j;
    if(pos==lim)
    {
        for(i=0;i<vt.size();i++)
            printf("%c",vt[i]);
        printf("\n");
        return;
    }
    for(j=0;j<n;j++)
    {
        if(chk[j]==0)
        {
            chk[j]=1;
            vt.push_back(line[j]);
            permu(pos+1);
            chk[j]=0;
            vt.pop_back();
        }
    }
}

int main()
{
    int i;
    scanf("%d%d",&n,&lim);
    for(i=0;i<n;i++)
        scanf(" %c",&line[i]);
    permu(0);
    cout<<"done"<<endl;
    return 0;
}
