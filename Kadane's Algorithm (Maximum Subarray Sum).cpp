#include<bits/stdc++.h>

using namespace std;

int maximumSubarraySum(vector <int> vt)
{
    int current_max=0,global_max=0,mx=-1000000000;
    for(int i=0;i<vt.size();i++)
    {
        current_max += vt[i];
        if(mx < vt[i])
            mx = vt[i];
        if(current_max<0)
            current_max = 0;
        if(current_max > global_max)
            global_max = current_max;
    }
    if(global_max == 0)
        global_max = mx;      //if all the elements are negative and we have to take at least one element from the array
    return global_max;
}

int main()
{
    int n,x;
    cin>>n;
    vector <int> vt;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        vt.push_back(x);
    }
    cout<<maximumSubarraySum(vt)<<endl;
}
