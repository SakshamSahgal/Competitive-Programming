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

//remember to use endl instead of \n for interactive problems.

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}


int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n+2] = {0};
        map<lli,pair<lli,lli>> g;
        for(lli i=1;i<=n;i++)
        {
            lli x,y;
            cin>>x>>y;
            g[i] = {x,y};
            a[x]++;
            a[y+1]--;
        }

        lli s=0;

        for(lli i=1;i<=n;i++)
        {
            s += a[i];
            a[i] = s;
        }

        lli ans=0;
        vector<lli> anss;
        for(lli i=1;i<=n;i++)
        {
            if( a[i] == n-1 && !( g[i].first <= i && i <= g[i].second ) )
            {
                ans++;
                anss.push_back(i);
            }
        }
        cout<<ans<<"\n";
        for(auto i:anss)
            cout<<i<<"\n";
        cout<<"\n";
        t--;
    }
    return 0;
}

