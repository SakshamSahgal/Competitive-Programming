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
    int t;
    cin>>t;
    while(t)
    {
        lli n,m,k;
        cin>>n>>m>>k;
        set<pll> z;
        while(k--)
        {
            lli x,y;
            cin>>x>>y;
            z.insert({x,y});
        }

        lli i=1;
        lli j=1;
        lli ans=0;
        while(1)
        {
            auto ptr = z.lower_bound({i,j});
            if(ptr == z.end())
            {
                ans += n - i;
                ans += m - j;
                break;
            }
            else
            {
                pll to = *ptr;
                ans += to.first - i;
                ans += to.second - j;
                z.erase(ptr);
                i = to.first+1;
                j = to.second+1;
                ans++;
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

