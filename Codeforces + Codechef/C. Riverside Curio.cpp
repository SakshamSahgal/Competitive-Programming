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



int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    lli a[n];
    lli dp[n];
    dp[0] = 0;
    for(lli i=0; i<n; i++)
        cin>>a[i];
    lli ans=0;
    for(int i=1; i<n; i++)
    {
        lli x;
        if(i+1 < n)
            x = max((max(dp[i-1],a[i+1] - 1) - a[i]),(lli)0);
        else
            x = max((dp[i-1] - a[i]),(lli)0);
        dp[i] = a[i] + x;
        ans += x;
    }
    array_printer(dp,n);
    cout<<ans<<"\n";

    return 0;
}
