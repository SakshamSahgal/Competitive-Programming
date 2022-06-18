#include<iostream>
using namespace std;

class Knapsack_Recursive
{
    public:
    int dp[100][100]; //wt,n
    int *wt;
    int *val;
    int n;
    int w;
    int knapsack(int i,int rem_wt)
    {
        if(i == n)
            return 0;

        //cout<<"at "<<i<<" , "<<rem_wt<<" my_wt = "<<wt[i]<<" my val = "<<val[i]<<" n = "<<n<<"\n";


        if(dp[rem_wt][i] != -1)
            return dp[rem_wt][i];

        int take = -1e5;
        int not_take;


        if(rem_wt >= wt[i])
            take = val[i] + knapsack(i+1,rem_wt-wt[i]);

        not_take = knapsack(i+1,rem_wt);
        return dp[rem_wt][i] = max(take,not_take);
    }

    Knapsack_Recursive()
    {
        cin>>n>>w;
        wt = new int[n];
        val = new int[n];

        for(int i=0;i<=w;i++)
            for(int j=0;j<=n;j++)
                dp[i][j] = -1;

        for(int i=0;i<n;i++)
            cin>>wt[i];
        for(int i=0;i<n;i++)
            cin>>val[i];
        cout<<"best value recursive = "<<knapsack(0,w)<<"\n";
    }
};

class Knapsack_iterative
{
    public :
    int n,w;
    int dp[100][100]; //n , wt
    int *wt;
    int *val;

    void knapsack()
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    int take= -1e9;
                    if(wt[i-1] <= j)
                        take = val[i-1] + dp[i-1][j - wt[i-1]];
                    int not_take = dp[i-1][j];
                    dp[i][j] = max(take,not_take);
                }
            }
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
    }

    Knapsack_iterative()
    {
        cin>>n>>w;
        wt = new int[n];
        val = new int[n];

        for(int i=0;i<=n;i++)
            for(int j=0;j<=w;j++)
                dp[i][j] = -1;

        for(int i=0;i<n;i++)
            cin>>wt[i];
        for(int i=0;i<n;i++)
            cin>>val[i];
        knapsack();
        cout<<"Best ans iterative = "<<dp[n][w]<<"\n";
    }

};

int main()
{
    Knapsack_Recursive k;
    Knapsack_iterative k2;
    return 0;
}
