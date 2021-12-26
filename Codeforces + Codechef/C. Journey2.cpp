#include <bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

map<lli,vector<lli>> g;
bool vis[100001] = {0};
long double ans = 0.0 ;

void DFS(lli v,lli d,long double prob)
{
    vis[v] = 1;

    if(g[v].size() == 0)
    {
         cout<<v<<" leaf distance = "<<d<<" prob = "<<prob<<"\n";
        ans += prob*d;
    }
    else
    {
       cout<<v<<" not a leaf prob of this node = "<<prob<<"\n";
        for(auto i:g[v])
        {
            if(vis[i] == 0)
               DFS(i,d+1,prob/(1.0*max((long double)g[v].size(),(long double)1.0)));
        }
    }
}

int main()
{
    GO_FAST
    lli n;
    cin>>n;
    for(int i=1; i<=n-1; i++)
    {
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    DFS(1,0,1.0);
    cout << fixed << setprecision(9)<<ans<<"\n";
    return 0;
}
