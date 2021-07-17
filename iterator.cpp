#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{

    int arr[]={10,10,15,20,20,20,25,30,35,36};
    vector <int> num(arr,arr+10);
    sort(num.begin(),num.end());
    vector <int>::iterator low,up;
    low=lower_bound(num.begin(),num.end(),40);
    up=upper_bound(num.begin(),num.end(),40);
    cout<< (low-num.begin())<<endl;
    cout<< (up-num.begin())<<endl;
}
