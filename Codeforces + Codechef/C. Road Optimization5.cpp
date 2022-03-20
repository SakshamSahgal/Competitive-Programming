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

lli dp[501][501];

lli calc_dp(lli i,lli k,vector<pair<lli,lli>> &v,lli n)
{
    //cout<<" { "<<i<<" , "<<k<<" } \n";
    if(i == n)
    {
        dp[i][k] = 0;
        return 0;
    }
    else if(dp[i][k] != -1)
        return dp[i][k];
    else
    {
        lli best_ans = INT_MAX;
        for(int j=i+1;j<=min((i+k+1),n);j++)
           best_ans = min(best_ans,(v[j].first - v[i].first)*(v[i].second) + calc_dp(j,k - j + i + 1,v,n));
        dp[i][k] = best_ans;
        return best_ans;
    }

}

int main()
{
    //GO_FAST
    lli n,l,k;
    cin>>n>>l>>k;
    vector<pair<lli,lli>> v(n+1);

    for(int i=0;i<n;i++)
        cin>>v[i].first;
    for(int i=0;i<n;i++)
        cin>>v[i].second;

    v[n].first = l;
    v[n].second = 0;

    if(n == 1)
    cout<<(l*v[0].second)<<"\n";
    else
    {
        for(int i=0;i<501;i++)
            for(int j=0;j<501;j++)
                dp[i][j] = -1;

        cout<<calc_dp(0,k,v,n)<<"\n";
        /*
        cout<<"\n-----------------\n";
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n-----------------\n"; */
    }
    return 0;
}
