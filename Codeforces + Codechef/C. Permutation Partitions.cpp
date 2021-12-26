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


bool sort_dec(pair<lli,lli> a,pair<lli,lli> b)
{
    return (a.first > b.first);
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
    lli n,k;
    cin>>n>>k;
    vector<pair<lli,lli>> index; //value index

    for(int i=0; i<n; i++)
    {
        lli x;
        cin>>x;
        index.push_back({x,i+1});
    }

    lli mod = 998244353;
    sort(index.begin(),index.end(),sort_dec);
    lli sum=0;
    lli ans=1;
    //pair_printer(index);
    vector<lli> ii;

    for(int i=0; i<k; i++)
    {
        sum+=index[i].first;
        ii.push_back(index[i].second);
    }

    sort(ii.begin(),ii.end());

    for(int i=0;i<ii.size()-1;i++)
        ans = ((ans%mod)*(ii[i+1] - ii[i])%mod)%mod;

    cout<<sum<<" "<<ans;
    return 0;
}
