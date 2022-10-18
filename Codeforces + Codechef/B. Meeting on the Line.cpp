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



bool poss(lli mid,lli a[],lli tm[],lli n,pll &ans)
{
    lli l=-inf;
    lli h=inf;
    for(int i=0;i<n;i++)
    {
        pair<lli,lli> z = {a[i] - (mid-tm[i]),a[i] + (mid-tm[i])};
        l = max(z.first,l);
        h = min(z.second,h);
    }

    if(l<=h)
    {
        ans = {l,h};
        return 1;
    }
    else
        return 0;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli x[n];
        lli tm[n];
        lli maxx = 0;
        for(int i=0;i<n;i++)
            cin>>x[i];
        for(int i=0;i<n;i++)
        {
            cin>>tm[i];
            maxx = max(tm[i],maxx);
        }

        lli l=maxx;
        lli h=1e9;
        ld ans;
        while(l<=h)
        {
            lli mid = (l+h)/2;
            pair<lli,lli> tha;
            if(poss(mid,x,tm,n,tha))
            {
                ans = (ld)(tha.first+tha.second)/2.0;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        cout<<setprecision(20)<<ans<<"\n";
        t--;
    }
    return 0;
}

