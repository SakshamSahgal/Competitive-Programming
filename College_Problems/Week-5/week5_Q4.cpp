#include<iostream>
using namespace std;


int dp[100][100];
int Knapsack(int i,int w,int n,int max_wt,int val[],int wt[])
{
    if(w > max_wt)
        return (-1e8);

    if(i == n)
        return 0;

    if(dp[i][w] != -1)
        return dp[i][w];

    int take = val[i] + Knapsack(i+1,w + wt[i],n,max_wt,val,wt);
    int not_take = Knapsack(i+1,w,n,max_wt,val,wt);
    dp[i][w] = max(take,not_take);
    return dp[i][w];
}

int main()
{
    int n,w;
    cin>>n>>w;
    int val[n];
    int wt[n];

    for(int i=0;i<n;i++)
        cin>>wt[i]>>val[i];

    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            dp[i][j] = -1;

    cout<<Knapsack(0,0,n,w,val,wt);
    return 0;
}

