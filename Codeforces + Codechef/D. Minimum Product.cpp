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
        lli a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        lli ans=0;
        lli csa = a-x;
        lli csb = b-y;
        if(max(x,y) <= min(a,b) && max(a,b) - min(a,b) <= n)
        {

        }
        else
        {
            if(a >= b)
            {
                b -= min(csb,n);
                n -= min(csb,n);
                if(n > 0)
                    a -= min(csa,n);
            }
            else
            {
                a -= min(csa,n);
                n -= min(csa,n);
                if(n > 0)
                    b -= min(csb,n);
            }
            ans = a*b;
        }

        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

