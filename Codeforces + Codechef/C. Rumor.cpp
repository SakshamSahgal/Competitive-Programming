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
using namespace std;

class Disjoint_set
{
    lli *parent;
    lli sz;
    public:
    Disjoint_set(lli n)
    {
        sz = n+1;
        parent = new lli[n+1];

        for(int i=1;i<=n;i++)
            parent[i] = -1;
    }

    lli Get_parent(lli x)
    {
        if(parent[x] < 0)
            return x;
        else
        {
            int abs_p = Get_parent(parent[x]);
            if(abs_p != x)
                parent[x] = abs_p; //path compression
            return abs_p;
        }

    }

    void Union(lli a,lli b)
    {
        lli pa = Get_parent(a);
        lli pb = Get_parent(b);
        //cout<<"Parent of a = "<<pa<<" Parent of b = "<<pb<<"\n";
        if(pa != pb)
        {
            lli spa = abs(parent[pa]);
            lli spb = abs(parent[pb]);

            if(spa >= spb) //parent pa
            {
                parent[pb] = pa;
                parent[pa] -= spb;
            }
            else //parent pb
            {
                parent[pa] = pb;
                parent[pb] -= spa;
            }
        }
    }

    void Display()
    {
        cout<<"\n-----------------\n";
        for(int i=1; i<sz; i++)
            cout<<parent[i]<<" ";
        cout<<"\n-----------------\n";
    }

    vector<lli> parents()
    {
        vector<lli> p;
        for(int i=1;i<sz;i++)
        {
            if(parent[i] < 0)
                p.push_back(i);
        }
        return p;
    }
};

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

bool vis[100001] = {0};

map<lli,vector<lli>> g;
lli mini = INT_MAX;
lli c[100001];
void DFS(lli v)
{
    if(vis[v] == 0)
    {
        vis[v] = 1;
        //cout<<v<<"\n";
        mini = min(c[v],mini);
        for(auto i:g[v])
        {
            if(!vis[i])
                DFS(i);
        }
    }
    else
        return;

}

int main()
{
    GO_FAST
    lli n,m;
    cin>>n>>m;
    Disjoint_set d(n);


    for(int i=1;i<=n;i++)
        cin>>c[i];

    for(int i=1;i<=m;i++)
    {
        lli x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        d.Union(x,y);
    }
    //d.Display();
    vector<lli> pp = d.parents();
    //vector_printer(pp);
    lli ans = 0;
    for(auto i:pp)
    {
        //cout<<"\n----------\n";
        DFS(i);
        ans += mini;
        //cout<<"\n minimum = "<<mini<<"\n";
        mini = INT_MAX;
        //cout<<"\n----------\n";
    }
    cout<<ans<<"\n";
    return 0;
}
