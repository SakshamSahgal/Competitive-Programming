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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

int main()
{
    GO_FAST
    lli n,q;
    cin>>n>>q;

    lli a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n,greater<lli>());
    map<lli,lli> f;
    vector<pair<lli,lli>> querries(q);

    for(int i=0;i<q;i++)
    {
        lli l,r;
        cin>>l>>r;
        querries[i].first = l;
        querries[i].second = r;
        f[l]++;
        f[r+1]--;
    }

    lli sum = 0;
    vector<pair<lli,lli>> v;
    for(int i=1;i<=n;i++)
    {
        sum += f[i];
      //  cout<<sum<<" ";
        v.push_back({sum,i});
    }

    sort(v.begin(),v.end(),greater<pair<lli,lli>>());

    lli b[n];
    for(int i=0;i<v.size();i++)
        b[v[i].second-1] = a[i];

   // cout<<"\n";
    vector<lli> ps(n);
    sum = 0;

    for(int i=0;i<n;i++)
    {
        sum += b[i];
        //cout<<b[i]<<" ";
        ps[i] = sum;
    }

    lli ans=0;

    for(auto i:querries)
        ans += sum_btw(ps,i.first-1,i.second-1);

    cout<<ans<<"\n";


    return 0;
}
