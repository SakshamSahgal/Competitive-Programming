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

void dfs(int v,vector<vector<lli>> &g,int p,lli &ed)
{
    for(auto i:g[v])
    {
        if(i != p)
            dfs(i,g,v,ed);
    }

    if(ed == -1)
        ed = v;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    vector<vector<lli>> g(n+1);
    for(int i=0; i<n-1; i++)
    {
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    lli c=0;
    lli root=0;
    for(int i=1; i<=n; i++)
    {
        if(g[i].size() > 2)
        {
            c++;
            root = i;
        }
    }

    if(c > 1)
        cout<<"No\n";
    else
    {
        if(root == 0)
            root = 1;

        vector<vector<lli>> ans;

        for(auto i:g[root])
        {
            vector<lli> th;
            lli ed=-1;
            th.push_back(root);
            dfs(i,g,root,ed);
            th.push_back(ed);
            ans.push_back(th);
        }

        cout<<"Yes\n";
        cout<<ans.size()<<"\n";
        for(auto i:ans)
        {
            for(auto j:i)
                cout<<j<<" ";
            cout<<"\n";
        }
    }

    return 0;
}

