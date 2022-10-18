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

void display_graph(vector<vector<lli>>v)
{
    line_printer(20);
    for(int i=0;i<v.size();i++)
    {
        cout<<i<<" -> ";
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
    line_printer(20);
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    lli c=1;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        n = unique(a, a + n) - a;
        lli m;
        cin>>m;
        lli b[m];
        map<lli,vector<lli>> g;
        for(int i=0; i<m; i++)
        {
            cin>>b[i];
            g[b[i]].push_back(i);
        }

        vector<vector<lli>> dp(n);
        vector<vector<lli>> dp2(n);

        for(int i=0;i<n;i++)
        {
            for(auto j:g[a[i]])
            {
                dp[i].push_back(j);
                dp2[i].push_back(0);
            }

        }

        for(int i=dp.size()-2;i>=0;i--)
        {
            for(int j=0;j<dp[i].size();j++)
            {
                lli abs_diff = inf;
                lli aage_index=0;
                for(int k=0;k<dp[i+1].size();k++)
                {
                    if( abs(dp[i][j]-dp[i+1][k]) +  dp2[i+1][k] < abs_diff )
                    {
                        abs_diff = abs(dp[i][j]-dp[i+1][k]) +  dp2[i+1][k] ;
                    }
                }
                dp2[i][j] = abs_diff;
            }
        }

        //display_graph(dp);
        //display_graph(dp2);
        lli ans=inf;
        if(n == 1)
            ans = 0;
        else
        {
            //lli dp[]
            for(int i=0;i<dp[0].size();i++)
                ans = min(ans,dp2[0][i]);

        }


        cout<<"Case #"<<(c++)<<": "<<ans<<"\n";

        t--;
    }
    return 0;
}
