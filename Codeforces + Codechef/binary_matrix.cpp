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

//remember to use endl instead of \n for interactive problems.

void printer(vector<vector<pair<lli,lli>>> &x)
{
    line_printer(20);
    for(int i=0; i<x.size(); i++)
    {
        for(int j=0; j<x[i].size(); j++)
            cout<<"["<<x[i][j].first<<" "<<x[i][j].second<<"] ";
        cout<<"\n";
    }
    line_printer(20);
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<string> z(n);
        vector<vector<pair<lli,lli>>> dp(n,vector<pair<lli,lli>>(n));

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>z[i][j];

        for(int i=0; i<n; i++)
        {
            if(z[i][0] == '1')
            {
                if(i == 0)
                    dp[i][0] = {1,1};
                else
                    dp[i][0] = {1,dp[i-1][0].second + 1};
            }
            else
                dp[i][0] = {0,0};
        }

        for(int j=0; j<n; j++)
        {
            if(z[0][j] == '1')
            {
                if(j == 0)
                    dp[0][j] = {1,1};
                else
                    dp[0][j] = {dp[0][j-1].first + 1,1};
            }
            else
                dp[0][j] = {0,0};
        }

        //printer(dp);
        lli ans = -inf;

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(z[i][j] == '1')
                {
                    lli w1 = dp[i][j-1].first;
                    lli h1 = dp[i][j-1].second;
                    lli w2 = dp[i-1][j].first;
                    lli h2 = dp[i-1][j].second;
                    lli w3 = dp[i-1][j-1].first;
                    lli h3 = dp[i-1][j-1].second;
                    if(w1 > w3 || h2 > h3)
                    {
                        if((1+w1)*h1 > (1+h2)*w2)
                            dp[i][j] = {1+w1,h1};
                        else
                            dp[i][j] = {w2,1+h2};
                    }
                    else
                        dp[i][j] = {1+w1,1+h2};
                }
                else
                    dp[i][j] = {0,0};

            }
        }

        printer(dp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                ans = max(ans,(dp[i][j].first*dp[i][j].second));
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

