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

lli dp[100001] = {0};

int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    lli h[2][n];
    lli dp[2][n];
    for(int i=0; i<n; i++)
        cin>>h[0][i];
    for(int i=0; i<n; i++)
        cin>>h[1][i];

    dp[0][n-1] = h[0][n-1];
    dp[1][n-1] = h[1][n-1];
    lli maxx_0 = dp[0][n-1];
    lli maxx_1 = dp[1][n-1];
    for(int i = n-2; i>=0; i--)
    {
        dp[0][i] = h[0][i] + maxx_1;
        dp[1][i] = h[1][i] + maxx_0;
        maxx_0 = max(maxx_0, dp[0][i]);
        maxx_1 = max(maxx_1, dp[1][i]);
    }
    /*
    for(int i=0; i<n; i++)
        cout<<dp[0][i]<<" ";
        cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<dp[1][i]<<" ";
        cout<<"\n";*/
    cout<<max(maxx_0,maxx_1);
    return 0;
}
