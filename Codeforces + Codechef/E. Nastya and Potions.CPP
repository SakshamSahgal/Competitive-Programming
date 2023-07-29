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

lli calcDP(lli x,vector<vector<lli>> &ways,vector<lli> &dp,lli c[])
{
    //cout<<" calc for "<<x<<"\n";
    if(dp[x] != inf)
        return dp[x];

    lli s=0;
    for(auto i:ways[x])
        s += calcDP(i,ways,dp,c);
    if(s < c[x])
        return dp[x] = s;
    else
        return dp[x] = c[x];
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
        lli n,k;
        cin>>n>>k;
        lli c[n],have[k];

        vector<lli> dp(n,inf);

        for(int i=0; i<n; i++)
            cin>>c[i];

        for(int i=0; i<k; i++)
        {
            cin>>have[i];
            dp[have[i]-1]=0; //already have
        }

        vector<vector<lli>> ways(n);
        for(lli i=0; i<n; i++)
        {
            lli sz;
            cin>>sz;
            if(sz == 0 && dp[i] != 0)
                dp[i] = c[i];

            for(int j=0; j<sz; j++)
            {
                lli x;
                cin>>x;
                ways[i].push_back(x-1);
            }
        }
        /*
        line_printer(10)
        for(auto i:ways)
        {
            for(auto j:i)
                cout<<j<<" ";
            cout<<"\n";
        }
        line_printer(10)
        */
        for(int i=0; i<n; i++)
            dp[i] = calcDP(i,ways,dp,c);

        for(auto i:dp)
            cout<<i<<" ";
        cout<<"\n";

        t--;
    }
    return 0;
}

