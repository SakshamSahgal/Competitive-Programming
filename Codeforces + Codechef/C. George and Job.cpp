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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

        lli n,m,k;
        cin>>n>>m>>k;
        lli a[n];
        lli s=0;
        vector<lli> ps(n);
        for(lli i=0; i<n; i++)
        {
            cin>>a[i];
            s += a[i];
            ps[i] = s;
        }

        lli dp[k][n];

        for(lli i=0; i<k; i++)
        {
            for(lli j=0;j<n;j++)
                dp[i][j] = -inf;
        }

        for(lli i=0;i<k;i++)
        {
            for(lli j=(i+1)*m - 1;j<n;j++)
            {
                if(i == 0)
                {
                    if(j-1 >= 0 )
                        dp[i][j] = max(sum_btw(ps,j-m+1,j),dp[i][j-1]);
                    else
                        dp[i][j] = sum_btw(ps,j-m+1,j);
                }

                else
                    dp[i][j] = max( sum_btw(ps,j-m+1,j) + dp[i-1][j-m],dp[i][j-1]);
            }
        }

        //array_2d_printer(dp,k,n);

        cout<<dp[k-1][n-1]<<"\n";


    return 0;
}

