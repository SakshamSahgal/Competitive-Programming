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

//remember to use endl instead of \n for interactive problems.
vector<lli> vis(300005,0);
vector<lli> euler_tour;
vector<lli> first_occ(300005,-1);
vector<lli> last_occ(300005,-1);
vector<lli> noc(300005,-1);

void dfs(lli v,lli pr,map<lli,vector<lli>> &g)
{
    euler_tour.push_back(v);
    vis[v] = 1;
    auto ptr = find(g[v].begin(),g[v].end(),pr);
    if(ptr != g[v].end())
        g[v].erase(ptr);

    for(auto i:g[v])
    {
        if(!vis[i])
        {
            dfs(i,v,g);
            euler_tour.push_back(v);
        }
    }
}

void display(map<lli,vector<lli>> g)
{
    cout<<"\n-------------------\n";
    for(auto i:g)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

lli fn(lli v,map<lli,vector<lli>> &g)
{
    if(g[v].size() == 0)
        return 0;
    else if(g[v].size() == 1)
        return noc[g[v][0]];
    else
    {
        lli Right = noc[g[v][1]];
        lli Left = noc[g[v][0]];
        return max( Right + fn(g[v][0],g),Left + fn(g[v][1],g));
    }
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        map<lli,vector<lli>> g;
        for(int i=0;i<n-1;i++)
        {
            lli a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        //display(g);
        dfs(1,-1,g);
        //display(g);

        //vector_printer(euler_tour);

        for(int i=0;i<euler_tour.size();i++)
        {
            if(first_occ[euler_tour[i]] == -1)
                first_occ[euler_tour[i]] = i;
            last_occ[euler_tour[i]] = i;
        }

        for(int i=1;i<=n;i++)
            noc[i] = (last_occ[i] - first_occ[i] + 1)/2;

      //  for(int i=1;i<=n;i++)
          //  cout<<"noc = "<<i<<" = "<<noc[i]<<"\n";

        cout<<fn(1,g)<<"\n";

        for(int i=0;i<=n;i++)
        {
            vis[i] = 0;
            first_occ[i]=-1;
            last_occ[i]=-1;
            noc[i] = -1;
        }
        euler_tour.clear();
        t--;
    }
    return 0;
}
