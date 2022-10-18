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

//remember to use endl instead of \n for interactive problems.




int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli a[n+1];
        lli s=0;
        map<lli,vector<lli>> g;
        map<lli,lli> e;
        map<lli,lli> o;
        vector<pair<lli,lli>> v;
        for(lli i=1; i<=n; i++)
        {
            cin>>a[i];
            s += a[i];
        }

        for(lli i=0; i<m; i++)
        {
            lli x,y;
            cin>>x>>y;
            v.push_back({x,y});
            g[x].push_back(y);
            g[y].push_back(x);
        }

        if(m%2 == 0)
            cout<<0<<"\n";
        else
        {
            lli ans = s;
            for(lli i=1; i<=n; i++)
            {
                if(g[i].size()%2 == 0)
                    e[i] = 1;
                else
                    o[i] = 1;
            }

            for(auto i:o)
                ans = min(a[i.first],ans);

            for(auto i:v)
            {
                if( e[i.first] && e[i.second])
                    ans = min(ans,a[i.first] + a[i.second]);

            }
            cout<<ans<<"\n";
        }
        t--;
    }
    return 0;
}

