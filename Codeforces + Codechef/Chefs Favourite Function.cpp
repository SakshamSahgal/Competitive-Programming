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

lli gpo2(lli l,lli r)
{
    lli z=1;
    while(z <= r)
        z = z*2;
    z = z/2;
    if(z < l)
        return -1;
    else
        return z;
}

lli f(lli x)
{
    if(x == 1)
        return 0;

    if(x%2 == 0)
        return 1 + f(x/2);
    else
        return f(x/2);
}

lli g(lli x)
{
    if(x == 1)
        return 1;
    if(x%2 == 0)
        return 2*g(x/2) + 1;
    else
        return 2*g(x/2);
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;

    // for(lli i=1;i<=256;i++)
    //  cout<<" i = "<<i<<" "<<f(i)<<"+"<<g(i)<<" = "<<f(i) + g(i)<<"\n";

    while(t)
    {
        lli l,r;
        cin>>l>>r;
        lli gp = gpo2(l,r);
        lli ans;
        if(gp != -1)
            ans = f(gp) + g(gp);
        else
        {
            ans = f(l) + g(l);
            for(lli i=l+1; i<=min(r,l+256); i++)
                ans = max(ans,f(i) + g(i));
        }
            cout<<ans<<"\n";

        t--;
    }
    return 0;
}

