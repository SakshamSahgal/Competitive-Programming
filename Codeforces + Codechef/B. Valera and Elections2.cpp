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

vector<lli> cur_prob;
set<lli> ans;
void dfs(lli v,vector<bool> &vis,vector<vector<pll>> &g)
{
    vis[v] = 1;
    for(auto nei:g[v])
    {
        if( !vis[nei.first] )
        {
            if(nei.second == 2)
            {
                cur_prob.push_back(nei.first);
                ans.insert(nei.first);
                if(cur_prob.size() >= 2)
                {
                    auto ptr = ans.find(cur_prob[cur_prob.size()-2]);
                    if(ptr != ans.end())
                        ans.erase(ptr);

                }
            }
            dfs(nei.first,vis,g);
            if(cur_prob.size() >= 1 && cur_prob[cur_prob.size()-1] == nei.first)
                cur_prob.pop_back();
        }
    }
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
    cout<<ans.size()<<"\n";
    for(auto i:ans)
        cout<<i<<" ";
    cout<<"\n";

    return 0;
}

