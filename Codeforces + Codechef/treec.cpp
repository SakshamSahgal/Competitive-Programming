#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
lli mod = 1e9 + 7;
//remember to use endl instead of \n for interactive problems.
lli fast_Power(lli a,lli b,lli n)
{
    lli res = 1;
    while(b>0)
    {
        if((b&1) != 0) //b is odd
            res = ((res%n)*(a%n))%n;

        a = ((a%n)*(a%n))%n;
        b = b>>1; //b = b/2
    }
    return res;
}



lli vis[1000005] = {0};

void dfs(lli node, lli va,vector<vector<lli>> &g,vector<lli> &hh)
{
    vis[node] = 1;
    int start = va;
    if (node == 1)
        start = va - 1;
    else
        start = va - 2;

    for(auto i : g[node])
    {
        if (vis[i] == 0)
        {
            hh[i] = start;
            dfs(i,va,g,hh);
            start--;
        }
    }
    return;
}


int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,k;
    cin>>n>>k;
    vector<lli> hh(n+1,1);
    vector<vector<lli>> g(n+1);
    for (lli i = 0; i < n - 1; i++)
    {
        lli x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (lli i = 1;i<=n;i++)
    {
        if(i == 1)
             hh[1] = k;

        if(!vis[i])
            dfs(i,k,g,hh);
    }
    lli ans = 1;
    for (lli i = 1; i <= n; i++)
    {
        ans *= hh[i];
        ans %= mod;
    }
    cout << ans << endl;
}
