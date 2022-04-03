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
    //GO_FAST
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
    lli t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli dp[n][n];
        for(lli i=0; i<n; i++)
            cin>>a[i];

        for(lli i=0; i<n; i++)
        {
            for(lli j=0; j<n; j++)
                dp[i][j] = -inf;
        }

        for(lli i=0; i<n; i++)
        {
            for(lli j=i; j<n; j++)
            {
                if(i == 0)
                {
                    if(j == 0)
                        dp[i][j] = a[j];
                    else
                        dp[i][j] = max(a[j],a[j-1]);
                }
                else
                {
                    lli z = (i+1)*a[j] + dp[i-1][j-1];
                    dp[i][j] = max(z,dp[i][j-1]);
                }
            }
        }

        //array_2d_printer(dp,n,n);

        lli maxx = -inf;

        for(lli i=0; i<n; i++)
        {
            for(lli j=0; j<n; j++)
                maxx = max(dp[i][j],maxx);
        }

        cout<<maxx<<"\n";

        t--;
    }
    return 0;
}

