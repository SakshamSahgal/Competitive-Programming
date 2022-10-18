#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
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

bool vis[200001];
vector<lli> colors(200001,-1);
set<lli> rem_col;

void DFS(lli v,lli p,vector<vector<lli>> &g)
{
    vis[v] = 1;
    //cout<<v<<" "<<p<<"\n";

    if(rem_col.count(colors[v]))
        rem_col.erase(rem_col.find(colors[v]));

    if(p != -1 && rem_col.count(colors[p]))
        rem_col.erase(rem_col.find(colors[p]));

    auto ptr = rem_col.begin();
    for(auto i:g[v])
    {
        if(!vis[i])
        {
            colors[i] = *ptr;
            ptr++;
        }
    }

    rem_col.insert(colors[v]);
    rem_col.insert(colors[p]);

    for(auto i:g[v])
    {
        if(!vis[i])
            DFS(i,v,g);
    }
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;

    for(lli i=1; i<=n; i++)
        rem_col.insert(i);

    lli a[n];
    vector<vector<lli>> g(n+1);
    for(int i=0; i<n-1; i++)
    {
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    colors[1]=1;
    DFS(1,-1,g);
    set<lli> ans;
    for(int i=1;i<=n;i++)
        ans.insert(colors[i]);
    cout<<ans.size()<<"\n";
    for(int i=1;i<=n;i++)
        cout<<colors[i]<<" ";
    return 0;
}
