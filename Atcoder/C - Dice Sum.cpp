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
lli mod = 998244353;
lli dp[50][2501];
lli fun(lli i,lli rem,lli n,lli m)
{
    //cout<<"i = "<<i<<" rem = "<<rem<<"\n";
    if(i == n)
    {
        if(rem >= 0)
            return 1;
        else
            return 0;
    }

    if(dp[i][rem] != -1)
        return dp[i][rem];

    lli s=0;
    for(int j=1; j<=min(rem,m); j++)
        s = (s%mod + (fun(i+1,rem - j,n,m))%mod)%mod;

    dp[i][rem] = s;
    return dp[i][rem];
}


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    for(int i=0;i<50;i++)
        for(int j=0;j<2501;j++)
            dp[i][j] = -1;

    lli n,m,k;
    cin>>n>>m>>k;
    cout<<fun(0,k,n,m);
    return 0;
}
