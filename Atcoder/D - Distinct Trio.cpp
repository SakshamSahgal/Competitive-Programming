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

vector<pair<lli,lli>> consequetive_freq(lli a[],lli n)
{
    int i=0;
    vector<pair<lli,lli>> v;
    while(i < n)
    {
        int j = i;
        int f = 1;
        while(j+1 < n && a[j+1] == a[i])
        {
            f++;
            j++;
        }
        v.push_back({a[i],f});
        i = j+1;
    }
    return v;
}



int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    lli a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);

    vector<pair<lli,lli>> v = consequetive_freq(a,n);

    //for(auto i:v)
       // cout<<i.first<<" "<<i.second<<"\n";

    vector<lli> ps(n);
    vector<lli> ss(n);

    for(int i=0;i<v.size();i++)
        ps[i] = (i == 0) ? v[i].second : ps[i-1] + v[i].second;


    for(int i=v.size()-1;i>=0;i--)
        ss[i] = (i == v.size()-1) ? v[i].second : v[i].second + ss[i+1];

    lli ans=0;
    for(lli i=1;i<v.size()-1;i++)
        ans += ((ps[i-1])*(v[i].second))*(ss[i+1]);

    cout<<ans<<"\n";
    return 0;
}
