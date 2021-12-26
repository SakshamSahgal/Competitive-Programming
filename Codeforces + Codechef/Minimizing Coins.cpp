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

vector<lli> dp(1000001,1e9);

int main()
{
    GO_FAST
    lli n,x;
    cin>>n>>x;
    lli c[n];
    dp[0] = 0;
    for(int i=0; i<n; i++)
        cin>>c[i];
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
            if( (i - c[j]) >= 0)
            dp[i] = min(dp[i],dp[i - c[j]] + 1);
    }
    if(dp[x] == 1e9)
        cout<<-1;
    else
        cout<<dp[x]<<"\n";
    return 0;
}
