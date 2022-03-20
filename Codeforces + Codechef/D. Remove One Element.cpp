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

lli maxx = 1;

vector<pair<lli,lli>> sequences(vector<lli> &v)
{
    vector<pair<lli,lli>> seq;
    lli i=0;
    lli n = v.size();
    while(i < n)
    {
        lli c = 1;
        lli j = i;

        while(j+1< n && v[j] < v[j+1])
        {
            c++;
            j++;
        }

        seq.push_back({i,j});
        maxx = max(maxx,(j-i+1));
        i = j + 1;
    }
    return seq;
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
    GO_FAST

    lli n;
    cin>>n;
    vector<lli> v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    vector<pair<lli,lli>> vv = sequences(v);

    //pair_printer(vv);

    for(int i=0; i<vv.size()-1; i++)
    {
        lli sz1 = vv[i].second - vv[i].first + 1;
        lli sz2 = vv[i+1].second - vv[i+1].first + 1;

        if( (vv[i].second != 0) && v[(vv[i].second - 1)] < v[vv[i+1].first] )
            maxx = max(maxx,sz1 - 1 + sz2);
        if(  (vv[i+1].first != n-1) && v[vv[i].second] < v[ vv[i+1].first + 1 ] )
            maxx = max(maxx,sz1 + sz2 - 1);
    }

    cout<<maxx<<"\n";


    return 0;
}
