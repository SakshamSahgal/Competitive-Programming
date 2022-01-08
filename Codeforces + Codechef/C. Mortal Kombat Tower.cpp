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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];

        lli dp[2][n] = {0};

        for(int i=n-1; i>=0; i--)
        {
            if(i == n-1)
            {
                dp[0][i] = 0;

                if(a[i] == 0)
                    dp[1][i] = 0;
                else
                    dp[1][i] = 1;
            }
            else if(i == n-2)
            {
                dp[0][i] = 0;
                if( (a[i] == 0 && a[i+1] == 0) || (a[i] == 0 && a[i+1] == 1) )
                    dp[1][i] = 0;
                else
                    dp[1][i] = 1;
            }
            else
            {
                dp[0][i] = min(dp[1][i+1],dp[1][i+2]);
                if(a[i] == 0 && a[i+1] == 0)
                    dp[1][i] = min(dp[0][i+1],dp[0][i+2]);
                else if(a[i] == 0 && a[i+1] == 1)
                    dp[1][i] = min(dp[0][i+1],1 + dp[0][i+2]);
                else if(a[i] == 1 && a[i+1] == 0)
                    dp[1][i] = 1 + min(dp[0][i+1],dp[0][i+2]);
                else
                    dp[1][i] = min(1 + dp[0][i+1],2 + dp[0][i+2]);
            }
        }
        /*
        cout<<"\n------------------------\n";
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n------------------------\n"; */
        cout<<dp[1][0]<<"\n";
        t--;
    }
    return 0;
}
