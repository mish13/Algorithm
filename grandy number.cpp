#include<bits/stdc++.h>

using namespace std;

int grandy_val[1000];

int mex(set <int> G)
{
    int ret=0;
    while(G.find(ret)!=G.end())
        ret++;
    return ret;
}

int grandy(int num,int n,int arr[])
{
    if(num<arr[1])
        return 0;
    if(grandy_val[num]!=-1)
        return grandy_val[n];
    set <int> G;
    for(int i=1;i<=n;i++)
    {
        G.insert(grandy(num-arr[i],n,arr));
    }
    return arr[num]=mex(G);
}

int main()
{
    int n,num;
    cin>>n;
    int arr[n+7];
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cin>>num;
    memset(grandy_val,-1,sizeof grandy_val);
    cout<<grandy(num,n,arr)<<endl;
    return 0;
}
