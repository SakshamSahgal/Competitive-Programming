#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

pair<lli,lli> smallest_factor(pair<lli,lli> p)
{
    //cout<<"aaiya = "<<p.first<<" "<<p.second<<"\n";
    pair<lli,lli> x;

    if(p.first == 0 || p.second == 0)
    {
        if(p.first == 0 && p.second != 0)
        {
            x.first = 0;
            if(p.second > 0)
                x.second = 1;
            else
                x.second = -1;
        }
        else if(p.second == 0 && p.first != 0)
        {
            if(p.first > 0)
                x.first = 1;
            else
                x.first = -1;
            x.second = 0;
        }
        else
        {
            x.first = 0;
            x.second = 0;
        }
    }
    else
    {
            lli gcd = max(__gcd(abs(p.first),abs(p.second)),(lli)1);
            x.first = p.first/gcd;
            x.second = p.second/gcd;
    }

    //cout<<"gaya = "<<x.first<<" "<<x.second<<"\n";

    return x;
}

int main()
{
    GO_FAST
    lli n;
    cin>>n;
    vector<pair<lli,lli>> p;
    set<pair<lli,lli>> ans;
   // cout<<smallest_factor({-12,-2}).first<<" "<<smallest_factor({-12,-2}).second<<"\n";

    for(int i=0; i<n; i++)
    {
        lli x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    for(int i=0; i<p.size(); i++)
    {
        for(int j=0; j<p.size(); j++)
        {
            if(i != j)
            {
                lli x = ( p[j].first  - p[i].first );
                lli y = ( p[j].second - p[i].second );
                pair<lli,lli> ee = smallest_factor({x,y});
                // cout<<"from "<<p[i].first<<" "<<p[i].second<<" to "<<p[j].first<<" "<<p[j].second<<" need = "<<x<<" "<<y<<" reduces to = "<<ee.first<<" "<<ee.second<<"\n";
                ans.insert({ee.first,ee.second});
            }
        }
    }
    cout<<ans.size()<<"\n";
    // for(auto i:ans)
    //   cout<<i.first<<" "<<i.second<<"\n";

    return 0;
}
