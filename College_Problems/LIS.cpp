#include<iostream>
using namespace std;

int dp[1000][1000];

int longest_increasing_subsequence(int id,int prev_id,int n,int a[])
{
    //cout<<"at = "<<id<<"\n";
    if(id == n)
        return 0;

    int take=-1e5;
    int not_take;

    if( dp[prev_id + 1][id] != -1)
        return dp[prev_id+1][id];

    if(prev_id == -1 || a[prev_id] < a[id])
        take = 1 + longest_increasing_subsequence(id+1,id,n,a);

    not_take = longest_increasing_subsequence(id+1,prev_id,n,a);

    dp[prev_id+1][id] = max(take,not_take);
    return max(take,not_take);
}

int main()
{
    for(int i=0; i<1000; i++)
        for(int j=0; j<1000; j++)
            dp[i][j] = -1;

    int a[] = {3,5,6,2,5,4,19,5,6,7,12};
    cout<<longest_increasing_subsequence(0,-1,11,a);
    return 0;
}
