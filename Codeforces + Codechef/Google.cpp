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





int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli a[n][m];
        vector<vector<map<lli,lli>>> dp(n,vector<map<lli,lli>>(m));
        for(lli i=0; i<n; i++)
        {
            for(lli j=0; j<m; j++)
                cin>>a[i][j];
        }

        for(lli i=0; i<n; i++)
        {
            for(lli j=0; j<m; j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j][a[i][j]]++;
                else if(i == 0)
                {
                    for(auto k:dp[i][j-1])
                    {
                        lli no = k.first;
                        lli f = k.second;
                        dp[i][j][no+a[i][j]] += f;
                    }
                }
                else if(j == 0)
                {
                    for(auto k:dp[i-1][j])
                    {
                        lli no = k.first;
                        lli f = k.second;
                        dp[i][j][no+a[i][j]] += f;
                    }
                }
                else
                {
                    for(auto k:dp[i][j-1])
                    {
                        lli no = k.first;
                        lli f = k.second;
                        dp[i][j][no+a[i][j]] += f;
                    }
                    for(auto k:dp[i-1][j])
                    {
                        lli no = k.first;
                        lli f = k.second;
                        dp[i][j][no+a[i][j]] += f;
                    }
                }
            }
        }

        lli k;
        cin>>k;

        lli c=0;
        for(auto i:dp[n-1][m-1])
        {
            if(i.first%k == 0)
                c+=i.second;
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}

