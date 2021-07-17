#include<cstdio>
#include<vector>

using namespace std;

int n,chk[25],diag1[50],diag2[50],brd[25][25],col[25],cnt;
void nqueen(int pos,int n)
{
    int i,j;
    if(pos==n+1)
    {
        cnt++;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                brd[i][j]=0;
            }
        }
        printf("..\n");
        for( i=1;i<=n;i++)
            brd[i][chk[i]]=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%d ",brd[i][j]);
            }
            printf("\n");
        }
        return;
    }
    for(int j=1;j<=n;j++)
    {
//        printf("**\n");
        if((col[j]||diag1[pos+j]||diag2[n+j-pos])==0)
        {
            chk[pos]=j;
            col[j]=diag1[pos+j]=diag2[n+j-pos]=1;
            nqueen(pos+1,n);
            col[j]=diag1[pos+j]=diag2[n+j-pos]=0;
            //chk[pos]=0;
        }
    }
}

int main()
{
    while(scanf("%d",&n) && n)
    {
        cnt=0;
        nqueen(1,n);
        printf("\nsoln: %d\n",cnt);
    }
    return 0;
}
