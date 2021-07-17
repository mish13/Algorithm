#include<cstdio>
#include<vector>

using namespace std;
int n,chk[20]={0};
char line[20];
vector <char> vt;

void combi(int pos)
{
    if((int)vt.size()==2)
    {for(int i=0;i<vt.size();i++)
        printf("%c",vt[i]);
    printf("\n");}
    for(int j=pos;j<n;j++)
    {
        if(chk[j]==0)
        {
            chk[j]=1;
            vt.push_back(line[j]);
            combi(j+1);
            chk[j]=0;
            vt.pop_back();
        }
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %c",&line[i]);
    combi(0);
    return 0;
}
