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
    int t;
    cin>>t;
    while(t)
    {
        lli n,x;
        cin>>n>>x;
        lli a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        lli dp[4][n];
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[2][0] = 0;
        dp[3][0] = 0;
        for(int i=1;i<n;i++)
        {
            lli xa = ((a[i-1])^(a[i]));
            lli xb = ((a[i-1])^(a[i] + x));
            lli xc = ((a[i-1] + x)^(a[i]));
            lli xd = ((a[i-1] + x)^(a[i] + x));
            dp[0][i] = max(dp[0][i-1],dp[2][i-1]) + xa;
            dp[1][i] = max(dp[0][i-1],dp[2][i-1]) + xb;
            dp[2][i] = max(dp[1][i-1],dp[3][i-1]) + xc;
            dp[3][i] = max(dp[1][i-1],dp[3][i-1]) + xd;
        }

        array_2d_printer(dp,4,n);

        lli ans = max(max(dp[0][n-1],dp[1][n-1]),max(dp[2][n-1],dp[3][n-1]));
        cout<<ans<<"\n";

        t--;
    }
    return 0;
}

