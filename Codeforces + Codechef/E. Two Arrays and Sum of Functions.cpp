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

void vector_printer( vector<lli> v)
{
    //cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    //cout<<"\n------------------------\n";
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
    vector<lli> a(n);
    vector<lli> b(n);

    vector<pair<lli,lli>> c;
    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0; i<n; i++)
        cin>>b[i];

    lli modd = 998244353;
    for(lli i=0; i<n; i++)
    {
        lli xx = (i+1)*(n-i)*a[i];
        c.push_back({xx,i});
    }


    sort(c.begin(),c.end());
    sort(b.begin(),b.end(),greater<lli>());

    lli ans=0;
    for(int i=0; i<n; i++)
        ans = ( ans + ( (c[i].first%modd) * (b[i]%modd) )%modd )%modd;



    cout<<ans<<"\n";
    return 0;
}

