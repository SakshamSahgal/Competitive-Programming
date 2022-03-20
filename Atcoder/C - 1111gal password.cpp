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


int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    lli ans=0;

    lli last_dp[10][1];
    for(lli j=0; j<n; j++)
    {
        lli this_dp[10][1];

        for(lli i=1; i<=9; i++)
        {
            if(j == 0)
                last_dp[i][0] = 1;
            else
            {
                if(i == 1)
                    this_dp[i][0] = (last_dp[i][0]%mod + last_dp[i+1][0]%mod)%mod;
                else if(i == 9)
                   this_dp[i][0] = (last_dp[i-1][0]%mod + last_dp[i][0]%mod)%mod;
                else
                   this_dp[i][0] = (last_dp[i-1][0]%mod + last_dp[i][0]%mod+ last_dp[i+1][0]%mod)%mod;
            }
        }

        if(j != 0)
         for(int i=1;i<=9;i++)
            last_dp[i][0] = this_dp[i][0];

    }

    for(int i=1;i<=9;i++)
        ans = (ans%mod  + last_dp[i][0]%mod)%mod;

    cout<<ans<<"\n";
    return 0;
}

