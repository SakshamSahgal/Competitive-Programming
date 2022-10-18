#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.

lli dfs(lli v,vector<bool> &vis,vector<vector<lli>> &g,map<lli,lli> &f,lli d)
{
    //cout<<v<<" ";
    vis[v] = 1;
    lli s=0;
    for(auto i:g[v])
    {
        if(!vis[i])
            s += dfs(i,vis,g,f,d+1);
    }
    //cout<<"at "<<v<<"got "<<s<<"\n";
    if(f[v] != -1)
    {
        f[v] = d;
        return s + 1;
    }
    else
    {
        if(s)
            f[v] = d;
        else
            f[v] = -1;
        return s;
    }
}



int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,k,x,y;
        cin>>n>>k>>x>>y;
        lli a[k];
        map<lli,lli> f;
        for(lli i=1;i<=n;i++)
            f[i] = -1;
        for(lli i=0;i<k;i++)
        {
            cin>>a[i];
            f[a[i]] = 1;
        }
        f[x] = 1;
        f[y] = 1;
        vector<vector<lli>> g(n+1);
        lli c=0;
        vector<pair<lli,lli>> edges;
        for(lli i=0;i<n-1;i++)
        {
            lli a,b;
            cin>>a>>b;
            edges.push_back({a,b});
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bool> vis(n+1,0);
        dfs(x,vis,g,f,0);

        for(lli i=1;i<=n;i++)
            vis[i] = 0;
            //cout<<"i = "<<i<<" "<<f[i]<<"\n";

        for(auto i:edges)
        {
            if(f[i.first] != -1 && f[i.second] != -1)
               c++;
        }
        lli ans=0;
        ans = 2*c - f[y];
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
