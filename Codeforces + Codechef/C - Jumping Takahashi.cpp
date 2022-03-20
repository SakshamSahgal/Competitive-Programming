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



int main()
{
    //GO_FAST

    lli n,x;
    cin>>n>>x;
    lli a[n+1];
    lli b[n+1];

    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];

    bool dp[n+1][x+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(dp[i-1][j] == 1)
            {
                if(j + a[i] <= x)
                    dp[i][(j + a[i])] = 1;
                if(j + b[i] <= x)
                    dp[i][(j + b[i])] = 1;
            }
        }
    }
    /*
    line_printer(20);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
    line_printer(20); */

    if(dp[n][x])
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
