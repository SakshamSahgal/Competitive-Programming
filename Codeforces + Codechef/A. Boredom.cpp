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
using namespace std;

int main()
{
    GO_FAST

    lli n;
    cin>>n;
    lli a[n];
    map<lli,lli> f;
    lli maxx = 0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        maxx = max(a[i],maxx);
        f[a[i]]++;
    }
   // cout<<"maxx = "<<maxx<<"\n";

    lli dp[2][maxx+1];

    memset(dp[0],0, sizeof(dp[0]));
    memset(dp[1],0, sizeof(dp[1]));

    for(int i=1; i<= maxx; i++)
    {
        if(f[i] == 0)
        {
            dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
            dp[1][i] = dp[0][i];
        }
        else
        {
            dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
            dp[1][i] = f[i]*i + dp[0][i-1];
        }
    }

    /*
    for(int i=0; i<2; i++)
    {
        for(int j=1; j<=maxx; j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    } */

    cout<<max(dp[0][maxx],dp[1][maxx])<<"\n";

    return 0;
}
