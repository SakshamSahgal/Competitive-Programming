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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;
        if(s[n-1] == s[0])
            cout<<1<<"\n";
        else
        {
            lli dp[n];
            lli dp0[n];
            lli dp1[n];
            for(int i=0; i<n; i++)
            {
                dp0[i] = inf;
                dp1[i] = inf;
            }

            if(s[n-2] == '0')
                dp0[n-2] = 1;
            else
                dp1[n-2] = 1;

            dp[n-2] = 1;

            for(lli i=n-3; i>=0; i--)
            {
                if(s[i] == '0')
                {
                    lli a = 1 + dp[i+1];
                    lli b = 1 + dp0[i+1];
                    if(s[n-1] == '0')
                        dp[i] = 1;
                    else
                        dp[i] = min(a,b);

                    dp0[i] = min(dp[i],dp0[i+1]);
                    dp1[i] = dp1[i+1];
                }
                else
                {
                    lli a = 1 + dp[i+1];
                    lli b = 1 + dp1[i+1];
                    if(s[n-1] == '1')
                        dp[i] = 1;
                    else
                        dp[i] = min(a,b);
                    dp[i] = min(a,b);
                    dp1[i] = min(dp[i],dp1[i+1]);
                    dp0[i] = dp0[i+1];
                }

            }

            //array_printer(dp,n);
            //array_printer(dp0,n);
            //array_printer(dp1,n);
            cout<<dp[0]<<"\n";
        }

        t--;
    }
    return 0;
}

