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

bool vis[1000005] = {0};
void dfs(lli v,vector<vector<lli>> &g,lli &tot,lli n)
{
    cout<<v<<" ";
    lli other;
    lli fn=0;
    lli sn=0;
    vis[v] = 1;
    for(auto i:g[v])
    {
        fn++;
        sn += g[i].size() - 1;
        if(!vis[i])
            dfs(i,g,tot,n);
    }

   lli x = fn + sn + 1;
    cout<<"other v = "<<v<<"x = "<<x<<"\n";
   lli to_sub = fast_Power((lli)2,x,mod) - 1 - x;
   tot = (tot%mod - to_sub%mod)%mod;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,c;
    cin>>n>>c;
    vector<vector<lli>> g(n+1);
    for(lli i=1; i<n; i++)
    {
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    lli tot = fast_Power(n,c,mod);

    set<lli> z;

    for(int i=1;i<=n;i++)
        z.push_back(i);

    while(z.size())
    {
        lli ff = *z.begin();
        lli x=0;

        for(auto i:g[ff])
        {
            for(auto )
        }
    }

    cout<<tot<<"\n";
    return 0;
}

