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
        //else
           // cout<<"Cycle Detected\n";
    }

    void Display()
    {
        cout<<"\n-----------------\n";
        for(int i=0; i<sz; i++)
            cout<<parent[i]<<" ";
        cout<<"\n-----------------\n";
    }

    lli No_of_Disjoint_Set(vector<lli> &d)
    {
        lli c=0;
        for(auto i:d)
        {
                if(parent[i] < 0)
                    c++;
        }
        return c;
    }
};

lli pair_to_no(int i,int j,int m)
{
    return ( i*m + 1 + j);
}

int main()
{
    //GO_FAST
    int n,m;
    cin>>n>>m;
    char a[n][m];
    vector<lli> dots;
    Disjoint_set d(n*m + 1);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j] == '.')
                dots.push_back(pair_to_no(i,j,m));
        }

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j] == '.')
                {
                    if(i-1 >= 0 && a[i-1][j] == '.')
                        d.Union(pair_to_no(i,j,m),pair_to_no(i-1,j,m));
                    if( i+1 < n && a[i+1][j] == '.')
                        d.Union(pair_to_no(i,j,m),pair_to_no(i+1,j,m));
                    if(j-1 >= 0 && a[i][j-1] == '.')
                        d.Union(pair_to_no(i,j,m),pair_to_no(i,j-1,m));
                    if( j+1 < m && a[i][j+1] == '.')
                        d.Union(pair_to_no(i,j,m),pair_to_no(i,j+1,m));
                }
            }
        }
    //d.Display();
    //cout<<"\n";
    cout<<d.No_of_Disjoint_Set(dots);


    return 0;
}
