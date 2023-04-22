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

lli modd = 998244353;


lli mod(lli a,lli b)
{
    lli ret = a % b;
    if (ret < 0)
        ret += b;
    return ret;
}

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l>r)
        return 0;
    if(l == 0)
        return mod(ps[r],modd);
    else
        return mod((mod(ps[r],modd) - mod(ps[l-1],modd)),modd);
}


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);


    lli n,m,k;
    cin>>n>>m>>k;
    vector<vector<lli>> dp(m,vector<lli>(n,1));

    for(int i=n-2; i>=0; i--) //cols
    {
        vector<lli> ps(m,0);

        for(int j=0; j<m; j++)
            ps[j] = (j == 0) ? mod(dp[j][i+1],modd) : mod( (mod(ps[j-1],modd) + mod(dp[j][i+1],modd)),modd);

        for(int j=0; j<m; j++) //rows
        {

            lli l = j+1-k;
            lli r = j+1+k;
            //cout<<l<<" "<<r<<" \n";
            dp[j][i] = 0;
            if(l>=1)
                dp[j][i] = mod((mod(dp[j][i],modd) + mod(sum_btw(ps,0,l-1),modd)),modd);
            if(r<=m)
                dp[j][i] = mod((mod(dp[j][i],modd) + mod(sum_btw(ps,r-1,m-1),modd)),modd);
            if(k == 0)
                dp[j][i] = mod((mod(dp[j][i],modd) - mod(dp[j][i+1],modd) ),modd);
        }
    }

    lli ans=0;
    for(lli i=0; i<m; i++)
        ans = mod((mod(ans,modd) + mod(dp[i][0],modd)),modd);

    cout<<ans<<"\n";

    return 0;
}

