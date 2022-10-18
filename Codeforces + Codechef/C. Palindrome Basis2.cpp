#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
lli mod = 1000000007;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.

bool is_palendrome(lli n)
{
    vector<lli> v;
    while(n != 0)
    {
        v.push_back((n%10));
        n/=10;
    }

    for(int i=0;i<v.size()/2;i++)
    {
        if(v[i] != v[v.size()-i-1])
            return 0;
    }
    return 1;
}

lli calc_dp(lli i,vector<lli> &pal,lli cur_sum,lli n,vector<vector<lli>> &dp)
{
    if(cur_sum == n)
        return 1;
    else
    {
        if(i == pal.size())
            return 0;
        lli c=0;
        if(dp[i][cur_sum] != -1)
            return dp[i][cur_sum];

        for(int j=i;j<pal.size();j++)
        {
            if(cur_sum + pal[j] <= n)
                c = (c%mod + calc_dp(j,pal,cur_sum+pal[j],n,dp)%mod)%mod;
            else
                break;
        }
        dp[i][cur_sum] = c;
        return c;
    }
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    vector<lli> pal;
    for(lli i=1;i<=40000;i++)
    {
        if(is_palendrome(i))
            pal.push_back(i);
    }
    //cout<<pal.size()<<"\n";
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli c=0;
        vector<vector<lli>> dp(pal.size(),vector<lli>(n,-1));
        cout<<calc_dp(0,pal,0,n,dp)<<"\n";
        t--;
    }
    return 0;
}
