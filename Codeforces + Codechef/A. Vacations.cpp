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
    lli dp[3][n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=n-1; i>=0; i--)
    {
        if(i == n-1)
        {
            dp[0][i] = 1;
            dp[1][i] = 0;
            dp[2][i] = 0;

            if(a[i]== 2)
                dp[1][i] = INT_MAX;
            else if(a[i] == 1)
                dp[2][i] = INT_MAX;
            else if(a[i] == 0)
            {
                dp[1][i] = INT_MAX;
                dp[2][i] = INT_MAX;
            }

        }
        else
        {
            dp[0][i] = 1 + min(dp[0][i+1],min(dp[1][i+1],dp[2][i+1]));
            dp[1][i] = min(dp[0][i+1],dp[2][i+1]);
            dp[2][i] = min(dp[0][i+1],dp[1][i+1]);
            if(a[i] == 1)
                dp[2][i] = INT_MAX;
            else if(a[i] == 2)
                dp[1][i] = INT_MAX;
            else if(a[i] == 0)
            {
                dp[1][i] = INT_MAX;
                dp[2][i] = INT_MAX;
            }
        }
    }
    /*
    cout<<"\n-----------------------\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dp[i][j] == INT_MAX)
                cout<<"- ";
            else
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n-----------------------\n"; */
    cout<<min(dp[0][0],min(dp[1][0],dp[2][0]))<<"\n";
    return 0;
}
