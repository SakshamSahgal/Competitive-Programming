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

lli ans = 0;


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    lli a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    lli ls[n];
    lli hs[n];
    lli sum=0;
    ls[0] = 0;
    hs[0] = 0;
    for(lli i=1;i<n;i++)
    {
        ls[i] = max(a[i],ls[i-1]);
        hs[i] = min(i,hs[i-1] + 1);
    }

    //array_printer(ls,n);
    //array_printer(hs,n);

    lli dp[n];
    dp[n-1] = ls[n-1] - a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        lli c1 = a[i+1] + dp[i+1] - a[i];
        lli c2 = a[i+1] + dp[i+1] - a[i] - 1;
        lli lpx = ls[i] - a[i];
        if(c1 < 0 )
            dp[i] = lpx;
        else if(c1 == 0)
            dp[i] = max(lpx,(lli)0);
        else
            dp[i] = max(lpx,c2);

    }

    for(int i=0;i<n;i++)
        sum += dp[i];

    //array_printer(dp,n);
    cout<<sum<<"\n";
    return 0;
}

