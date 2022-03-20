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

lli min_moves[1001];


lli calc_moves(lli a,lli d)
{
    min_moves[a] = min(min_moves[a],d);
    for(int x=1; x<=a; x++)
    {
        lli next = a + a/x;
        if(next <= 1000 && min_moves[next] > d + 1 )
            calc_moves(next,d + 1);
    }
}

int knapSack(lli W, lli wt[], lli val[], lli n)
{
    // making and initializing dp array
    lli dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++)
    {
        for (int w = W; w >= 0; w--)
        {

            if (wt[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}


int main()
{
    GO_FAST
    for(int i=0; i<=1000; i++)
        min_moves[i] = inf;

    min_moves[1] = 0;

    calc_moves(2,1);

    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        lli b[n];
        lli c[n];
        lli sum=0;
        for(int i=0; i<n; i++)
            cin>>b[i];

        for(int i=0; i<n; i++)
        {
            cin>>c[i];
            sum += c[i];
        }

        lli w[n];
        lli s=0;

        for(int i=0; i<n; i++)
        {
            w[i] = min_moves[b[i]];
            s += w[i];
        }

        if(s <= k)
            cout<<sum<<"\n";
        else
            cout<<knapSack(k,w,c,n)<<"\n";
        t--;
    }
    return 0;
}
