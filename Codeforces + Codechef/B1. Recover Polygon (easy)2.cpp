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

pair<lli,lli> get_ij(vector<vector<pair<lli,lli>>> &dp,lli i,lli j,lli n)
{
    pair<lli,lli> p;
    if(i < n && j < n )
        return dp[i][j];
    else
        return {0,0};
}


int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    vector<string> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<vector<pair<lli,lli>>> dp(n,vector<pair<lli,lli>>(n));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(v[i][j] == '4')
            {
                lli cr = min(get_ij(dp,i+1,j,n).first , get_ij(dp,i,j+1,n).first-1);
                lli cc = min(get_ij(dp,i+1,j,n).second -1, get_ij(dp,i,j+1,n).second);
                if(cr <= 0)
                    dp[i][j].first = 1;
                else
                    dp[i][j].first = cr+1;
                if(cc <= 0)
                    dp[i][j].second = 1;
                else
                    dp[i][j].second = cc+1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<"{"<<dp[i][j].first<<","<<dp[i][j].second<<"} ";
        cout<<"\n";
    }

    return 0;
}
