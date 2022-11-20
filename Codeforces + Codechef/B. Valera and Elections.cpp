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
typedef pair<lli,lli> pll;



lli dfs(lli v,vector<bool> &vis,vector<vector<pll>> &g)
{
    //cout<<v<<" ";
    vis[v] = 1;
    lli neeche=0;
    lli got=0;
    for(auto i:g[v])
    {
        if(!vis[i.first])
        {
            if(i.second == 2)
                neeche++;
            lli gt = dfs(i.first,vis,g);
            got += gt;
        }
    }
    return max(neeche,got);
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    vector<bool> vis(n+1,0);
    vector<vector<pll>> g(n+1);
    for(int i=0;i<n-1;i++)
    {
        lli a,b,t;
        cin>>a>>b>>t;
        g[a].push_back({b,t});
        g[b].push_back({a,t});
    }
    cout<<dfs(1,vis,g)<<"\n";
    return 0;
}

