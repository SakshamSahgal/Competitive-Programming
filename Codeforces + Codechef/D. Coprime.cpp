#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    vector<pair<lli,lli>> v;
    for(lli i=1; i<=1000; i++)
    {
        for(lli j=1; j<=1000; j++)
        {
            if(__gcd(i,j) == 1)
                v.push_back({i,j});
        }
    }



    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        map<lli,lli> mx;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            mx[a[i]] = i+1;
        }
        lli ans=-1;
        for(auto i:v)
        {
            if(mx[i.first] != 0 && mx[i.second] != 0)
                 ans = max(ans,mx[i.first] + mx[i.second]);
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

