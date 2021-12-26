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

struct rects
{
    pair<lli,lli> a;
    pair<lli,lli> b;
    pair<lli,lli> c;
    pair<lli,lli> d;
};


int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    vector<pair<lli,lli>> points(n);
    vector<rects> ans;
    map<pair<lli,lli>,lli> x;
    for(lli i=0; i<n; i++)
    {
        cin>>points[i].first>>points[i].second;
        x[points[i]] = 1;
    }



    for(lli i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if( (points[i].first < points[j].first &&  points[i].second < points[j].second) )
            {
                pair<lli,lli> ii = points[i];
                pair<lli,lli> jj = points[j];
                pair<lli,lli> aa = {points[i].first,points[j].second};
                pair<lli,lli> bb = {points[j].first,points[i].second};
                if( x[aa] == 1 && x[bb] == 1)
                    ans.push_back({ii,jj,aa,bb});
            }
        }
    }
    cout<<ans.size()<<"\n";
    //for(auto i:ans)
       // cout<<"("<<i.a.first<<" "<<i.a.second<<") ("<<i.b.first<<" "<<i.b.second<<") ("<<i.c.first<<" "<<i.c.second<<") ("<<i.d.first<<" "<<i.d.second<<")\n";
    return 0;
}
