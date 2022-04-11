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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;


lli Knapsack(lli i,lli w,vector<vector<lli>> &dp,vector<lli> &wt,vector<lli> &val)
{
    lli n = val.size();
    lli max_wt = dp[0].size() - 1;
    if(w > max_wt)
        return -inf;
    if(i == n)
        return 0;

    if(dp[i][w] != -1)
        return dp[i][w];

    lli take = val[i] + Knapsack(i+1,w + wt[i],dp,wt,val);
    lli not_take = Knapsack(i+1,w,dp,wt,val);
    dp[i][w] = max(take,not_take);
    return dp[i][w];
}

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    /*
    1
    6 15
    6 5 6 6 3 7
    5 6 4 6 5 2 */

    int t;
    cin>>t;
    while(t)
    {
        lli n, mx_wt ; //no of items , max weight of bag
        cin>>n>>mx_wt;
        vector<lli> wt(n);
        vector<lli> val(n);
        for(lli i=0; i<n; i++)
            cin>>wt[i];
        for(lli i=0; i<n; i++)
            cin>>val[i];
        vector<vector<lli>> dp(n,vector<lli>(mx_wt+1,-1)); //[n X mx_wt] //-1->default value
        Vec_2d_printer(dp);
        lli best_ans = Knapsack(0,0,dp,wt,val);
        Vec_2d_printer(dp);
        cout<<"best ans = "<<best_ans<<"\n";
        t--;
    }
    return 0;
}

