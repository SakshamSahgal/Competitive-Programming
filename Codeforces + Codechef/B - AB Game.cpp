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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,a,b;
    cin>>n>>a>>b;
    lli ans = 0;
    if(n < a)
        ans = 0;
    else
    {
        lli z;
        if(a > b)
        {
            z = (n - n%a)/a;
            lli last = (n - n%a);
            if( (n - last) >= b-1)
                ans += z*b;
            else
            {
                ans += (z-1)*b;
                ans += (n-last+1);
            }
        }
        else
            ans = n-a+1;
    }
    cout<<ans<<"\n";

    return 0;
}

