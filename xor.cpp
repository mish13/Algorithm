#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int i,j,n,mx=-1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d %d -> %d\n",i,j,i^j);
            if(mx<(i^j))
                mx=(i^j);
        }
    }
    printf("*%d*\n",mx);
    printf("%lld\n",pow(2,31));
    return 0;
}
