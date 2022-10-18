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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,m;
    cin>>n>>m;
    lli dp1[n][m]; //max to reach from 1,1 to i,j
    lli dp2[n][m]; //max to reach from i,j to n-1,m-1
    lli dp3[n][m]; //max to reach from n-1,1 to i,j
    lli dp4[n][m]; //max to reach from i,j to 1,m
    lli a[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>a[i][j];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i == 0 && j == 0)
                dp1[i][j] = a[i][j];
            else if(i == 0)
                dp1[i][j] = a[i][j] + dp1[i][j-1];
            else if(j == 0)
                dp1[i][j] = a[i][j] + dp1[i-1][j];
            else
                dp1[i][j] = a[i][j] + max(dp1[i][j-1],dp1[i-1][j]);
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i == n-1 && j == m-1)
              dp2[i][j] = a[i][j];
            else if(i == n-1)
                dp2[i][j] = a[i][j] + dp2[i][j+1];
            else if(j == m-1)
                dp2[i][j] = a[i][j] + dp2[i+1][j];
            else
                dp2[i][j] = a[i][j] + max(dp2[i][j+1],dp2[i+1][j]);
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(i == n-1 && j == 0)
              dp3[i][j] = a[i][j];
            else if(i == n-1)
                dp3[i][j] = a[i][j] + dp3[i][j-1];
            else if(j == 0)
                dp3[i][j] = a[i][j] + dp3[i+1][j];
            else
                dp3[i][j] = a[i][j] + max(dp3[i][j-1],dp3[i+1][j]);

        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i == 0 && j == m-1)
              dp4[i][j] = a[i][j];
            else if(i == 0)
                dp4[i][j] = a[i][j] + dp4[i][j+1];
            else if(j == m-1)
                dp4[i][j] = a[i][j] + dp4[i-1][j];
            else
                dp4[i][j] = a[i][j] + max(dp4[i][j+1],dp4[i-1][j]);
        }
    }

    //array_2d_printer(dp1,n,m);
    //array_2d_printer(dp2,n,m);
    //array_2d_printer(dp3,n,m);
    //array_2d_printer(dp4,n,m);

    lli ans=-inf;
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            lli aa = dp1[i-1][j] + dp4[i][j+1] + dp2[i+1][j] + dp3[i][j-1];
            lli bb = dp4[i-1][j] + dp2[i][j+1] + dp3[i+1][j] + dp1[i][j-1];
            ans = max(ans,max(aa,bb));
        }

    }
    cout<<ans<<"\n";
    return 0;
}
