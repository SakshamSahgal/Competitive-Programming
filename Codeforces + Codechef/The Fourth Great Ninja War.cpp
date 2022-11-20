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
typedef pair<lli,lli> pll;

lli numberOfPaths(vector<vector<lli>> &grid,lli k)
{
    lli m=grid.size(),n=grid[0].size();
    vector<vector<vector<lli> > > dp(m, vector<vector<lli> > (n, vector<lli>(k,0)));
    vector<lli>v(k,0);
    lli mod=1e9+7;
    for(lli i=m-1; i>=0; i--)
    {
        for(lli j=n-1; j>=0; j--)
        {
            lli rem=grid[i][j]%k;
            if(i==m-1 and j==n-1)
            {
                dp[i][j][rem]=1;
                continue ;
            }
            auto right=(j==n-1?v:dp[i][j+1]);
            auto down=(i==m-1?v:dp[i+1][j]);

            for(lli r=0; r<k; r++)
            {
                lli nrem=rem+r;
                nrem%=k;
                dp[i][j][nrem]+=right[r];
                dp[i][j][nrem]+=down[r];
                dp[i][j][nrem]%=mod;
            }
        }
    }
    return dp[0][0][0]%mod;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli ans;
    lli n,m,k;
    cin>>n>>m>>k;
    vector<vector<lli>> grid(m,vector<lli>(n,0));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>grid[i][j];

    cout<<numberOfPaths(grid,k)<<"\n";
    return 0;
}
