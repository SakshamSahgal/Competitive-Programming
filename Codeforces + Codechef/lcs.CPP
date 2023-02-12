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




lli lps(vector<vector<lli>> &dp,string &a, string &b, lli n1, lli n2)
{
    if (n1 == 0 || n2 == 0)
        return 0;
    if (dp[n1][n2] != -1)
        return dp[n1][n2];
    if (a[n1 - 1] == b[n2 - 1])
        return dp[n1][n2] = 1 + lps(dp,a, b, n1 - 1, n2 - 1);
    else
        return dp[n1][n2] = max(lps(dp,a, b, n1 - 1, n2),lps(dp,a, b, n1, n2 - 1));
}

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
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s1;
        cin>>s1;
        vector<vector<lli>> dp(n+1,vector<lli>(n+1,-1));
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        lli ans = lps(dp,s2, s1, n, n);
        ans = ans/2;
        //Vec_2d_printer(dp);
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
