#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{
    vector<pair<long double,pair<int,int>>> vec;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int w,v;
        cin>>v>>w;
        long double the_ratio = (v*(1.0))/(w*(1.0));
        pair<int,int> val = {w,v};
        vec.push_back({the_ratio,val});
    }
    sort(vec.begin(),vec.end(),greater<pair<int,pair<int,int>>>());
    int W;
    cin>>W;
    long double ans=0;
    int rem = W;
    for(auto i:vec)
    {
        if(rem >= i.second.first)
        {
            ans += i.second.second;
            rem -= i.second.first;
        }

        else
        {
            long double fr;
            fr = ((rem*1.0)/(i.second.first*1.0))*i.second.second;
            ans += fr;
            break;
        }
        //cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}
