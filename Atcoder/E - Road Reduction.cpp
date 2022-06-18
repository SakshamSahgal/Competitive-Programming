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



bool not_taking = 0;

class Disjoint_set
{
public:
    lli *parent;
    lli sz;

    Disjoint_set(lli sizze)
    {
        sz = sizze;
        parent = new lli[sz];
        for(int i=0; i<sz; i++)
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
            lli size_a = abs(parent[pa]);
            lli size_b = abs(parent[pb]);
            if(size_a >= size_b)
            {
                parent[pa] += parent[pb];
                parent[pb] = pa;
            }
            else
            {
                parent[pb] += parent[pa];
                parent[pa] = pb;
            }
        }
        else
            not_taking = 1;
    }

    void Display()
    {
        cout<<"\n-----------------\n";
        for(int i=0; i<sz; i++)
            cout<<parent[i]<<" ";
        cout<<"\n-----------------\n";
    }

    lli No_of_Disjoint_Set()
    {
        lli c=0;
        for(int i=0;i<sz;i++)
        {
            if(parent[i] < 0)
                c++;
        }
        return c;
    }
};

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,m;
    cin>>n>>m;
    vector<pair<pair<lli,lli>,lli>> ed; //a,b,w
    vector<pair<lli,lli>> edges; //wt,index
    for(int i=0;i<m;i++)
    {
        lli a,b,w;
        cin>>a>>b>>w;
        ed.push_back({{a,b},w});
        edges.push_back({w,i});
    }
    sort(edges.begin(),edges.end());


    Disjoint_set d(200001);
    vector<lli> ans;
    for(int i=0;i<edges.size();i++)
    {
        not_taking = 0;
        int id = edges[i].second;
        d.Union(ed[id].first.first,ed[id].first.second);
        if(!not_taking)
            ans.push_back(id);
    }

    for(auto i:ans)
        cout<<i+1<<" ";

    return 0;
}
