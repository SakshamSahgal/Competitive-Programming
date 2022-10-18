#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

class Disjoint_set
{
public:
    lli *parent;
    lli sz; //no of vertex + 1 (if vertices start from 1)

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
        cout<<"Parent of a = "<<pa<<" Parent of b = "<<pb<<"\n";
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
            cout<<"Cycle Detected\n";
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
    cout<<"enter no of vertexes = ";
    lli n;
    cin>>n;
    Disjoint_set d(n);
    d.Display();

    for(lli i=0; i<n; i++)
    {
        lli x,y;
        cin>>x>>y;
        d.Union(x,y);
        d.Display();
    }
    return 0;
}
