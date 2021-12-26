#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
lli n,W;
cin>>n>>W;
int wt[n],val[n];

for(int i=0;i<n;i++)
        cin>>wt[i]>>val[i];
lli dp[n+1][W+1];

for(int i=0;i<=n;i++)
    dp[i][0] = 0;

for(int i=0;i<=W;i++)
    dp[0][i] = 0;

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=W;j++)
    {
            if(wt[i-1] <= j)
                {
                    if(val[i-1] + dp[i-1][(j - wt[i-1])] >= (dp[i-1][j])) //lelenge isko
                            dp[i][j] = val[i-1] + dp[i-1][(j - wt[i-1])];
                    else
                        dp[i][j] = dp[i-1][j];    //nhi lenge
                }
            else
                dp[i][j] = dp[i-1][j];  //nhi lenge
    }
}

/*
for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        cout<<dp[i][j]<<" ";
    cout<<"\n";
    }
*/
cout<<dp[n][W]<<"\n";
return 0;
}
