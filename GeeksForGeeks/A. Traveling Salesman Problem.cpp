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
        lli n;
        cin>>n;
        lli mxu=-inf;
        lli mxd=-inf;
        lli mxr=-inf;
        lli mxl=-inf;

        for(int i=0; i<n; i++)
        {
            lli x,y;
            cin>>x>>y;
            if(x == 0)
            {
                if(y>0)
                    mxu = max(mxu,abs(y));
                else
                    mxd = max(mxd,abs(y));
            }
            else
            {
                if(x>0)
                    mxr = max(mxr,abs(x));
                else
                    mxl = max(mxl,abs(x));
            }
        }

        lli ans=0;

        if(mxu != -inf)
            ans += 2*mxu;
        if(mxd != -inf)
            ans += 2*mxd;
        if(mxr != -inf)
            ans += 2*mxr;
        if(mxl != -inf)
            ans += 2*mxl;
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
