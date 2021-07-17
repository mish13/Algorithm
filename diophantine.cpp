#include<cstdio>

using namespace std;

int egcd(int a,int b,int *x,int *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }
    int x1,y1;
    int extgcd=egcd(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return extgcd;
}

int main()
{
    int a,b,c,d,x,y,mul,i,ansx,ansy;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        d=egcd(a,b,&x,&y);
        mul=c/d;            //if c%d!=0,not possible
        x*=mul;
        y*=mul;
        //printf("%d %d %d %d\n",x,y,mul,d);
        for(i=-2;i<=2;i++)  //finding 4 more soln
        {
            ansx=x+i*(b/d);
            ansy=y-i*(a/d);
            printf("%d*%d + %d*%d = %d\n",ansx,a,ansy,b,c);
        }
    }
}
