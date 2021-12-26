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

bool my_comparator(pair<lli,lli> a,pair<lli,lli> b)
{
    return (a.second < b.second);
}

void pair_printer(vector<pair<lli,lli>> v)
{
cout<<"\n------------pair------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n-------------------------------\n";
}

int main()
{
    //GO_FAST
    lli n,d;
    cin>>n>>d;
    vector<pair<lli,lli>> a(n);

    for(lli i=0; i<n; i++)
        cin>>a[i].first>>a[i].second;

    sort(a.begin(),a.end(),my_comparator);
    //pair_printer(a);
    lli x = INT_MIN;
    lli ans=0;
    for(int i=0;i<n;i++)
    {
        if(x + d - 1 < a[i].first)
        {
            ans++;
            x = a[i].second;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
