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
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        vector<pair<lli,lli>> p;
        for(int i=0;i<n;i++)
        {
            lli x;
            cin>>x;
            p.push_back({x,i});
        }

        sort(p.begin(),p.end());

      // for(auto i:p)
          // cout<<i.first<<" "<<i.second<<"\n";

        lli x[2];
        x[0] = p[p.size()-1].second;
        x[1] = p[0].second;

        sort(x,x+2);
        int ans1 = x[1] + 1;
        int ans2 = n - x[0];
        int ans3 = x[0] + 1 + n - x[1];
        cout<<min(min(ans1,ans2),ans3)<<"\n";
        t--;
    }
    return 0;
}
