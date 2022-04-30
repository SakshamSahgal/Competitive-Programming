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

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

        lli n,w;
        cin>>n>>w;
        lli val[n];
        lli wt[n];

        for(int i=0;i<n;i++)
            cin>>val[i];

        for(int i=0;i<n;i++)
            cin>>wt[i];

        vector<vector<lli>> dp(n+1,vector<lli>(w+1,0));

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if( wt[i-1] <= j)
                    dp[i][j] = max(dp[i-1][j],val[i-1] + dp[i-1][j - wt[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        //Vec_2d_printer(dp);
        cout<<dp[n][w]<<"\n";
    return 0;
}
