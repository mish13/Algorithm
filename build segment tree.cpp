#include<cstdio>

using namespace std;

int arr[100],sum[400],pos,u,l,r;

int build(int att,int L,int R)
{
    sum[att]=0;
    if(L==R)
        return sum[att]=arr[L];
    int mid=(L+R)/2;
    build(2*att,L,mid);
    build(2*att+1,mid+1,R);
    sum[att]=sum[2*att]+sum[2*att+1];
}

int update(int att,int L,int R,int pos,int u)
{
    if(L==R)
    {
        return sum[att]=u;
        ;
    }
    int mid=(L+R)/2;
    if(pos<=mid) update(2*att,L,mid,pos,u);
    else update(2*att+1,mid+1,R,pos,u);
    sum[att]=sum[2*att]+sum[2*att+1];
}

int query(int att,int L,int R,int l,int r)
{
    if(r<L || l>R) return 0;
    if(l<=L && R<=r) return sum[att];
    int mid=(L+R)/2;
    int x=query(2*att,L,mid,l,r);
    int y=query(2*att+1,mid+1,R,l,r);
    return x+y;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    build(1,1,n);
    for(i=1;;i++)
    {
        if(sum[i]==0)
            break;
        printf("%d ",sum[i]);
    }
    printf("\n");
    scanf("%d%d",&pos,&u);
    update(1,1,n,pos,u);
    for(i=1;;i++)
    {
        if(sum[i]==0)
            break;
        printf("%d ",sum[i]);
    }
    scanf("%d%d",&l,&r);
    printf("%d",query(1,1,n,l,r));
    printf("\n");
}
