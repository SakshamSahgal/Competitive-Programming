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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

lli common(pair<lli,lli> p1,pair<lli,lli> p2)
{
    if(p1.first > p2.first)
        swap(p1,p2);

    if(p2.first > p1.second)
        return 0;
    else
        return (min(p1.second,p2.second) - p2.first + 1);
}

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

int main()
{
    //GO_FAST

    lli n;
    cin>>n;
    vector<pair<lli,lli>> v;
    v.push_back({0,0});

    for(int i=0; i<n; i++)
    {
        lli x,y;
        cin>>x>>y;
        if(!(x == 0 && y == 0))
            v.push_back({x,y});
    }

    lli ans=1;
    for(int i=0; i<n-1; i++)
    {
        u = min(v[i+1].first,v[i].second);
        l = max(v[i].first,v[i].second);

        if(i == 0)
            ans += l;
        else
        {
            if(u>=l)
                ans +=(u-l+1);
        }

    }

    cout<<ans<<"\n";

    return 0;
}

