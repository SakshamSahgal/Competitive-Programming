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
        // cout<<"Parent of a = "<<pa<<" Parent of b = "<<pb<<"\n";
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
        //else
        //cout<<"Cycle Detected\n";
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
        for(int i=0; i<sz; i++)
        {
            if(parent[i] < 0)
                c++;
        }
        return c;
    }
};

void display(map<char,vector<char>> g)
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

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    Disjoint_set d(26);
    for(int i=0; i<n; i++)
    {
        if(s1[i] != s2[i])
            d.Union( (s1[i]-'a') , (s2[i] - 'a') );
    }

   // for(int i=0;i<26;i++)
     //   cout<<d.parent[i]<<" ";

    map<char,vector<char>> g; //parent,children


    for(int i=0;i<26;i++)
    {
        if(d.parent[i] >=  0) //wanted children
            g[  d.Get_parent(i) + 'a' ].push_back(i + 'a');
    }

    //display(g);

    lli ans=0;
    for(auto i:g)
        ans += i.second.size();

    cout<<ans<<"\n";

    for(auto i:g)
    {
        cout<<i.first<<" "<<i.second[0]<<"\n";
        for(int j=0;j<i.second.size() - 1;j++)
            cout<<i.second[j]<<" "<<i.second[j+1]<<"\n";
    }

    return 0;
}
