#include<cstdio>

using namespace std;

int arr[10][10],dp[10][10],row,col;

int maxy(int m,int n)
{
    if(m>n)
        return m;
    return n;
}

int rock_climb(int x,int y)
{
    if(x>=0 && x<row && y>=0 && y<col)
    {
        if(dp[x][y]!=-1)
            return dp[x][y];
        int ret=-10000000;
        ret=maxy(ret,rock_climb(x+1,y)+arr[x][y]);
        ret=maxy(ret,rock_climb(x+1,y-1)+arr[x][y]);
        ret=maxy(ret,rock_climb(x+1,y+1)+arr[x][y]);
        return dp[x][y]=ret;
    }
    else
        return 0;
}
int main()
{
    int i,j;
    scanf("%d%d",&row,&col);
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            dp[i][j]=-1;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            scanf("%d",&arr[i][j]);
    }
    printf("%d\n",rock_climb(0,0));
}
