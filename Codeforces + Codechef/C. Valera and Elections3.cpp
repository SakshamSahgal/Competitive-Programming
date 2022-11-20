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
vector<lli> par(1e5+1,-1);
void dfs(lli v,lli p,vector<bool> &vis,vector<vector<pll>> &g,vector<bool> &poss)
{
    vis[v] = 1;
    par[v] = p;
    euler_tour.push_back(v);
    for(auto neig:g[v])
    {
        if(!vis[neig.first])
        {
            if(neig.second == 2)
                poss[(neig.first)] = 1;
            dfs(neig.first,v,vis,g,poss);
            euler_tour.push_back(v);
        }
    }
}

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l <= r)
    {
        if(l == 0)
            return ps[r];
        else
            return (ps[r] - ps[l-1]);
    }
    else
        return 0;
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
    vector<bool> poss(n+1,0);
    vector<lli> ans;
    for(int i=0; i<n-1; i++)
    {
        lli x,y,t;
        cin>>x>>y>>t;
        g[x].push_back({y,t});
        g[y].push_back({x,t});
    }
    dfs(1,-1,vis,g,poss);
    vector<lli> et_b(euler_tour.size(),0);
    vector<lli> ps(euler_tour.size(),0);
    for(int i=0; i<euler_tour.size(); i++)
        et_b[i] = poss[euler_tour[i]];


    vector<pll> st_ed(n+1, {-1,-1});



    for(int i=0; i < euler_tour.size(); i++)
    {
        ps[i] = (i == 0) ? et_b[i] : et_b[i] + ps[i-1];
        if(st_ed[euler_tour[i]].first == -1)
            st_ed[euler_tour[i]].first = i;
        st_ed[euler_tour[i]].second = i;
    }
    /*
    cout<<"Euler tour = ";
    vector_printer(euler_tour);
    cout<<"BEubool = ";
    vector_printer(et_b);
    cout<<"st ed = ";
    for(auto i:st_ed)
        cout<<i.first<<" "<<i.second<<"\n";
    cout<<"Poss = ";

    for(auto i:poss)
        cout<<i<<" ";
    */

    for(int i=1; i<=n; i++)
    {
        if(poss[i])
        {
            //cout<<"trying = "<<i<<"\n";
            bool can=1;
            for(auto chld:g[i])
            {
                if(chld.first != par[i])
                {
                    lli st = st_ed[chld.first].first;
                    lli ed = st_ed[chld.first].second;
                    if(sum_btw(ps,st,ed) > 0)
                    {
                        can = 0;
                        break;
                    }
                }
            }
            if(can)
                ans.push_back(i);
        }
    }

    cout<<ans.size()<<"\n";
    for(auto i:ans)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}

