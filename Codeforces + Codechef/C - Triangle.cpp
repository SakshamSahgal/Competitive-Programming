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
    lli n;
    cin>>n;
    vector<pair<lli,lli>> v;

    for(int i=0; i<n; i++)
    {
        lli x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(i != j && j != k)
                {
                    if( v[j].first - v[i].first != 0)
                    {
                        long double m = ( v[j].second - v[i].second )/(v[j].first - v[i].first);

                        if(v[k].second - m*v[k].first != v[i].second - (v[i].first) * m)
                        {
                            cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n";
                        }
                    }
                }
            }
        }
    }
    return 0;
}
