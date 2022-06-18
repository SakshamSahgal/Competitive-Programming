#include<bits/stdc++.h>
using namespace std;



int main()
{

    int n,amount;
    cin>>n>>amount;
    vector<int> coins(n);

    for(int i=0;i<n;i++)
        cin>>coins[i];

    vector<int> dp(amount+1);
    dp[0] = 0;

    for(int i=1; i<=amount; i++)
    {
        int mini = 1e9;
        for(int j=0; j<n; j++)
        {
            if(coins[j] <= i && dp[i - coins[j]] != -1)
                mini = min(1 + dp[i - coins[j]],mini);
        }

        if(mini == 1e9)
            dp[i] = -1;
        else
            dp[i] = mini;
    }

    // for(int i=0;i<=amount;i++)
    //   cout<<dp[i]<<" ";
    cout<< dp[amount];
    return 0;
}
