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

lli depth[1000] = {0};
void DFS(lli v,lli p,vector<vector<lli>> &g,vector<bool> &vis,lli d)
{
    cout<<"at "<<v<<" parent "<<p<<"\n";
    vis[v] = 1;
    depth[v] = d;
    for(auto i:g[v])
    {
        if(!vis[i])
            DFS(i,v,g,vis,d+1);
        else
        {
            if(i != p && p != -1)
            {
                lli len = depth[v]  - depth[i] + 1;
                cout<<"Cycle Completed ending at "<<i<<" from "<<v<<" len = "<<len<<"\n";

            }

        }
    }
}


int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    vector<vector<lli>> g(n+1);
    vector<bool> vis(n+1,0);
    for(lli i=1; i<=n; i++) //edges
    {
        lli x;
        cin>>x;
        g[i].push_back(x);
        g[x].push_back(i);
    }

    for(lli i=1; i<=n; i++)
    {
        if(!vis[i])
            DFS(i,-1,g,vis,0);
    }

    return 0;
}

