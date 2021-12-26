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

lli mod = 1000000007;
lli dp[1000001];


int main()
{
    GO_FAST
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    lli n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(i-j>=0)
                dp[i] = (dp[i] + dp[i-j])%mod;
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
