#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    vector<pair<long double,pair<int,int>>> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        long double dist = sqrtl(x*x + y*y);
        v.push_back({dist,{x,y}});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<"\n";
    return 0;
}
