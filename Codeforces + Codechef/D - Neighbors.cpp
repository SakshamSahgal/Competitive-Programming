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



bool check_cycle(lli cur,vector<vector<lli>> &g,vector<bool> &vis,lli par)
{
    vis[cur] = 1;
    bool got=0;
    for(auto neighbour:g[cur])
    {
        if(neighbour != par && vis[neighbour])
            return 1;
        else
        {
            if(!vis[neighbour])
                got = got|check_cycle(neighbour,g,vis,cur);
        }
    }
    return got;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,m;
    cin>>n>>m;
    vector<vector<lli>> g(n+1);
    vector<bool> vis(n+1,0);

    while(m--)
    {
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool fail=0;

    for(auto i:g)
    {
        if(i.size() > 2)
        {
            fail=1;
            break;
        }
    }

    if(!fail)
    {
        for(lli i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                if(check_cycle(i,g,vis,-1))
                {
                    fail=1;
                    break;
                }
            }
        }
    }


    if(fail)
        cout<<"No\n";
    else
        cout<<"Yes\n";

    return 0;
}

