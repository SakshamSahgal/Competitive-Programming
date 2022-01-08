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

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        map<lli,vector<pair<lli,lli>>> g;
        map<pair<lli,lli>,lli> ans;

        for(int i=0;i<n;i++)
        {
            lli l,r;
            cin>>l>>r;
            g[r-l+1].push_back({l,r});
        }
        lli done[n+1] = {0};
        map<pair<lli,lli>,lli> aa;
        for(auto i:g)
        {
            for(auto j:i.second)
            {
                for(lli k=j.first;k<=j.second;k++)
                {
                    if(done[k] == 0)
                    {
                        done[k] = 1;
                        aa[j] = k;
                        break;
                    }
                }
            }
        }

        for(auto i:aa)
            cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<"\n";

        t--;
    }
    return 0;
}
