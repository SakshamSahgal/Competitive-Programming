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

vector<lli> euler_tour;

void dfs(lli v,vector<bool> &vis,vector<vector<pll>> &g)
{
    vis[v] = 1;
    euler_tour.push_back(v);
    for(auto neig:g[v])
    {
        if(!vis[neig.first])
        {
            dfs(neig.first,vis,g);
            euler_tour.push_back(v);
        }
    }
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    vector<vector<pll>> g(n+1);
    vector<bool> vis(n+1,0);
    for(int i=0; i<n-1; i++)
    {
        lli x,y,t;
        cin>>x>>y>>t;
        g[x].push_back({y,t});
        g[y].push_back({x,t});
    }
    dfs(1,vis,g);
    vector_printer(euler_tour);



    return 0;
}

