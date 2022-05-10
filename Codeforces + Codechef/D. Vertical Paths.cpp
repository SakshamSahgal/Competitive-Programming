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

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}

bool vis[200002];

lli c=0;
map<lli,vector<lli>> ans;
void dfs(lli v,vector<vector<lli>> &g)
{
   // cout<<v<<" , "<<c<<"\n";
    ans[c].push_back(v);
    vis[v] = 1;

    for(int i=0; i<g[v].size(); i++)
    {
        if(!vis[g[v][i]])
        {
            dfs(g[v][i],g);
            if(i != g[v].size() - 1)
                c++;
        }

    }

}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli p[n+1];
        vector<vector<lli>> g(n+1);
        lli root = 1;
        for(int i=1; i<=n; i++)
        {
            cin>>p[i];
            if(p[i] != i)
                g[p[i]].push_back(i);
            else
                root = i;
        }

        //Vec_2d_printer(g);
        dfs(root,g);
        memset(vis,0, sizeof(vis));
        c=0;
        cout<<ans.size()<<"\n";
        for(auto i:ans)
        {
            cout<<i.second.size()<<"\n";
            for(auto j:i.second)
                cout<<j<<" ";
            cout<<"\n";
        }
        cout<<"\n";
        ans.clear();
        t--;
    }


    return 0;
}
