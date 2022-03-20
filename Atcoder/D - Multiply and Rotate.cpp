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

lli no_of_dig(lli n)
{
    lli d=0;
    while(n!=0)
    {
        d++;
        n/=10;
    }
    return d;
}

lli convert(lli x)
{
    lli d = no_of_dig(x);
    lli y = (x%10)*pow(10,d-1) + (x/10);
    return y;
}

lli dp[1000001];


void recursion(lli x,lli dist,lli a,lli n)
{
    //cout<<x<<"\n";
    dp[x] = min(dist,dp[x]);
    if(  x*a < (10*n) )
    {
        if(  (x*a) <= 1000000 && dp[(x*a)] > dist + 1 )
            recursion((x*a),dist+1,a,n);
    }

    if(x >= 10 && x%10 != 0)
    {
        lli cc = convert(x);

        if(  cc <= 1000000 && dp[cc] > dist + 1 )
            recursion(cc,dist+1,a,n);
    }
}

int main()
{
    GO_FAST
    lli a,n;
    cin>>a>>n;

    for(lli i=1; i<=(1e6); i++)
        dp[i] = INT_MAX;

    recursion(1,0,a,n);


    if(dp[n] == INT_MAX)
        cout<<"-1\n";
    else
        cout<<dp[n]<<"\n";

    return 0;
}
