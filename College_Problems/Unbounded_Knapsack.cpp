#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,w;
    cin>>n>>w;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];


    int dp[w+1] = {-1};

    dp[0] = 0;
    for(int i=1; i<=w; i++)
    {
        int maxx = -1e9;
        for(int j=0; j<n; j++)
        {
            if(wt[j] <= i)
                maxx = max(maxx,val[j] + dp[i-wt[j]]);
        }

        if(maxx == -1e9)
            dp[i] = 0;
        else
            dp[i] = maxx;

    }

    //for(int i=0; i<=w; i++)
      //  cout<<dp[i]<<" ";

    cout<<dp[w]<<"\n";
    return 0;
}
