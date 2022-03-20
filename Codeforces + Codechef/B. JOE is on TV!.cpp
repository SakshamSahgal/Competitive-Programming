#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
+
int main()
{
    //GO_FAST

    lli n;
    cin>>n;
    long double dp[n+1];
    dp[0] = 0.00;
    for(int i=1; i<=n; i++)
        dp[i] = ((1.0/i) + dp[i-1]);

    cout<<std::setprecision(14)<<(dp[n])<<"\n";

    return 0;
}
