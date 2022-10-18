#include<bits/stdc++.h>
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

lli mod = 1e9+7;



lli calc_dp(lli i,lli j,lli s,lli a[],lli n,vector<vector<lli>> &dp)
{
    if(i < 1 || i > n)
        return 0;

    if(j == 0)
    {
        if(i == s)
            return 1;
        else
            return 0;
    }

    if( dp[i][j] != -1 )
        return dp[i][j];

    lli peeche = calc_dp(i - a[j-1],j-1,s,a,n,dp)%mod;
    lli aage = calc_dp(i + a[j-1],j-1,s,a,n,dp)%mod;
    dp[i][j] = (aage+peeche)%mod;
    return (aage+peeche);
}


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m,s;
        cin>>n>>m>>s;
        lli a[m];

        for(int i=0; i<m; i++)
            cin>>a[i];

        vector<vector<lli>> dp(n+1,vector<lli> (m+1,-1)); //cur dog , cur pass

        for(lli i=1;i<=n;i++)
            calc_dp(i,m,s,a,n,dp);

        for(lli i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
        }

        for(lli i=1; i<=n; i++)
        {


        }
        cout<<"\n";
        t--;
    }
    return 0;
}

