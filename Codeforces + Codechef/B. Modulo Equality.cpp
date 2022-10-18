#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

lli req_x(lli a,lli b,lli m)
{
    if(a == b)
        return 0;
    else
    {
        if(b > a)
            return b-a;
        else
            return (b-a+m);
    }
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,m;
    cin>>n>>m;
    lli b[n];
    lli a[n];
    map<lli,lli> nf1;
    map<lli,lli> nf2;
    map<lli,set<lli>> fn;
    lli ans = -inf;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        nf1[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
         cin>>b[i];
         nf2[b[i]]++;
    }

    for(auto i:nf2)
        fn[i.second].insert(i.first);

    for(auto i:nf1)
    {
        auto ptr = fn[i.second].lower_bound(i.first);
        lli z;
        if(ptr == fn[i.second].end())
        {
            z = *(fn[i.second].begin());
            fn[i.second].erase(fn[i.second].begin());
        }
        else
        {
            z = *ptr;
            fn[i.second].erase(ptr);
        }

        ans = max(ans,req_x(i.first,z,m));
    }
    cout<<ans<<"\n";
    return 0;
}

