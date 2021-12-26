#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//cout.tie(NULL);
    lli h,w;
    cin>>h>>w;
    lli n;
    cin>>n;
    vector<lli> r;
    vector<lli> c;
    map<lli,lli> row;
    map<lli,lli> col;
    vector<pair<lli,lli>> v;
    for(lli i=0; i<n; i++)
    {
        lli x,y;
        cin>>x>>y;
        v.push_back({x,y});

        if( row[x] == 0 )
        {
            r.push_back(x);
            row[x] = x;
        }

        if(col[y] == 0)
        {
           c.push_back(y);
           col[y] = y;
        }
    }
    sort(r.begin(),r.end());
    sort(c.begin(),c.end());

    for(lli i=0; i<n; i++)
    {
        auto ptrr = lower_bound(r.begin(),r.end(),v[i].first);
        auto ptrc = lower_bound(c.begin(),c.end(),v[i].second);
        lli ri = (ptrr - r.begin());
        lli ci = (ptrc - c.begin());
        cout<<ri+1<<" "<<ci+1<<"\n";
    }

    return 0;
}


