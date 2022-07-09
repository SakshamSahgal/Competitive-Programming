#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
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

int main()
{
    // GO_FAST
    // freopen("input.txt", "r", stdin);
    // freopen("myout.txt", "w", stdout);
    int t;
    cin >> t;
    while (t)
    {
        lli n, x;
        cin >> n >> x;
        lli a[n];
        lli mini = inf;
        lli maxx = -inf;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mini = min(a[i],mini);
            maxx = max(a[i],maxx);
        }

        lli s = 0;
        for (int i = 0; i < n - 1; i++)
            s += abs(a[i + 1] - a[i]);

        lli ans = s;
        if(mini > 1 )
            ans += min( 2*(mini-1) , min(a[n-1],a[0]) - 1);
        if(maxx < x)
            ans += min(2*(x-maxx),x - max(a[n-1],a[0]));
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}