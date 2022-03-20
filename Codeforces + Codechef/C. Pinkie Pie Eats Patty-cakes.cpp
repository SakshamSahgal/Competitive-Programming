#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;

#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        map<lli,lli> f;
        for(int i=0; i<n; i++) //O(nlogn)
        {
            cin>>a[i];
            f[a[i]]++;
        }

        vector<pair<lli,lli>> v;

        for(auto i:f)
            v.push_back({i.second,i.first}); //O(n)

        sort(v.begin(),v.end(),greater<pair<lli,lli>>()); //O(nlogn)

        pair_printer(v);

        lli b[n];
        lli idx = 0;

        while(idx != n) //O(n)
        {
            for(auto &&i:v)
            {
                if(i.first != 0)
                {
                    //cout<<i.second<<" ";
                    b[idx++] = i.second;
                    i.first--;
                }
            }
        }

        array_printer(b,n);
        map<lli,vector<lli>> g;

        for(int i=0; i<n; i++) //O(n)
            g[b[i]].push_back(i);

        //O(n)
        lli ans = inf;
        for(auto i:g)
        {
            if(i.second.size() > 1)
            {
                lli mini_dist = inf;
                for(int j=0; j<i.second.size()-1; j++)
                    mini_dist = min(mini_dist,i.second[j+1]-i.second[j] - 1);
                ans = min(mini_dist,ans);
            }
        }

        cout<<ans<<"\n";

        t--;
    }
    return 0;
}

