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

const int mod = 1e9+7;


int main()
{
    GO_FAST
    int n,x;
    cin>>n>>x;
    int c[n];
    vector<lli> dp(x+1,0);
    dp[0] = 1;
    for(int i=0; i<n; i++)
        cin>>c[i];

    for(int i=1; i<=x; i++)
    {
        for(int j=0; j<n; j++)
        {
            if( i - c[j] >= 0 )
                dp[i] = ( dp[i] + dp[i - c[j]])%mod;
        }
    }
    cout<<dp[x]<<"\n";
    return 0;
}
