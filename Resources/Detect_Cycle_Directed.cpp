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

class Cycle_Detection_directed //(V + E)
{
public:
    bool *vis;
    bool *dfs_vis;
    lli sz; //[no of vertex (for 0 based vertex)] [no of vertex + 1 (for 1 based vetex)]
    map<lli, vector<lli>> g;
    Cycle_Detection_directed(lli n, map<lli, vector<lli>> &gg)
    {
        sz = n;
        vis = new bool[sz];
        dfs_vis = new bool[sz];
        g = gg;
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            dfs_vis[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                cout << "Checking for " << i << "\n";
                if (dfs(i))
                {
                    cout << "Cycle detected (1/0) - " << 1 << "\n";
                    break;
                }
            }
        }
    }

    bool dfs(lli x)
    {
        vis[x] = 1;
        dfs_vis[x] = 1;
        for (auto i : g[x])
        {
            //vis == 1 && dfs_vis == 1 (cycle)
            //vis == 0 && dfs_vis == 1 (not poss)
            //vis == 1 && dfs_vis == 0 (no cycle)
            //vis == 0 && dfs_vis == 0 (explores more)
            
            if(vis[i] && dfs_vis[i])
                return 1;
            else if(!vis[i] && !dfs_vis[i])
                if(dfs(i)) return 1;
        }
        dfs_vis[x] = 0;
        return 0;
    }
};

int
main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    map<lli,vector<lli>> g;
    lli n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    Cycle_Detection_directed d(n,g);
    
    return 0;
}