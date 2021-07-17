#include<cstdio>

using namespace std;

int arr[100],toggle[400];


void update(int att,int L,int R,int l,int r)
{
    if(r<L || l>R) return;
    if(l<=L && R<=r) {toggle[att]^=1; return;}
    int mid=(L+R)/2;
    update(2*att,L,mid,l,r);
    update(2*att+1,mid+1,R,l,r);
}

int query(int att,int L,int R,int pos)
{
    int x,y;
    if(pos<L || pos>R) return 0;
    if(L<=pos && pos<=R) return arr[pos]^toggle[att];
    int mid=(L+R)/2;
    if(pos<=mid)
        x= query(2*att,L,mid,pos);
    else
        y= query(2*att+1,mid+1,R,pos);
    return (x^y)^toggle[att];
}

int main()
{
    int n,i,l,r,q;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    scanf("%d%d",&l,&r);
    update(1,1,n,l,r);
    for(i=1;i<16;i++)
        printf("%d ",toggle[i]);
    scanf("%d",&q);
    printf("%d",query(1,1,n,q));
}
