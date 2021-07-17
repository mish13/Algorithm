
#include<cstdio>
#include<vector>

using namespace std;

int n;
char line[20];
vector <char> vt;
int chk[20]={0};
void permu(int pos)
{
    int i,j;
    char prev='\0';
    if(pos==n)
    {
        for(i=0;i<vt.size();i++)
            printf("%c",vt[i]);
        printf("\n");
        return;
    }
    for(j=0;j<n;j++)
    {
        if(chk[j]==0 && prev!=line[j])
        {
            prev=line[j];
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
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %c",&line[i]);
    permu(0);
    return 0;
}
