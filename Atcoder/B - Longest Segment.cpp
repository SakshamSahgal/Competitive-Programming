#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

long double dist(pair<lli,lli> p1,pair<lli,lli> p2)
{
    lli x1 = p1.first;
    lli y1 = p1.second;
    lli x2 = p2.first;
    lli y2 = p2.second;
    return sqrtl( powl(x2-x1,2) + powl(y2 - y1,2) );
}

int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    vector<pair<lli,lli>> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;

    long double max_dist = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i != j)
             max_dist = max(max_dist,dist(v[i],v[j]));
        }

    }
    cout<<setprecision(12)<<max_dist<<"\n";
    return 0;
}
