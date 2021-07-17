#include<bits/stdc++.h>

using namespace std;

long long tree[100007],n;

long long query(int index)
{
    long long sum=0;
    while(index>0)
    {
        sum+=tree[index];
        index-= index & (-index);
    }
    return sum;
}

void update(int index,int val)
{
    while(index<=n)
    {
        tree[index]+=val;
        index+= index & (-index);
    }
}

int main()
{
    cin>>n;
    int qry,x,in,v;
    cin>>qry;
    for(int i=1;i<=qry;i++)
    {
        cin>>x;
        if(x==1)
        {
            cin>>in;
            cout<<query(in)<<endl;
        }
        else if(x==2)
        {
            cin>>in>>v;
            update(in,v);
        }
    }
    return 0;
}
