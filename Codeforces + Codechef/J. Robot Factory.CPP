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

struct Fact
{
    bool up;
    bool down;
    bool left;
    bool right;
    int no;
};

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
        //  cout<<"Cycle Detected\n";
    }

    void Display()
    {
        cout<<"\n-----------------\n";
        for(int i=0; i<sz; i++)
            cout<<parent[i]<<" ";
        cout<<"\n-----------------\n";
    }
};



lli p_to_id(lli i,lli j,lli n,lli m)
{
    return (i*m + j + 1);
}

Fact convert_it(lli n)
{
    vector<lli> bin;

    Fact x;

    x.no = n;

    while(n != 0)
    {
        bin.insert(bin.begin(),(n%2));
        n/=2;
    }

    if(bin.size() < 4)
    {
        lli noz = 4 - bin.size();

        for(lli i=1; i<=noz; i++)
            bin.insert(bin.begin(),0);
    }

    x.up = !(bin[0]);
    x.right = !(bin[1]);
    x.down = !(bin[2]);
    x.left = !(bin[3]);

    return x;
}


int main()
{
    //GO_FAST
    lli n,m;
    cin>>n>>m;
    Disjoint_set d(m*n + 1);
    Fact a[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            lli x;
            cin>>x;
            a[i][j] = convert_it(x);
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
           // cout<<"("<<a[i][j].up<<" "<<a[i][j].right<<" "<<a[i][j].down<<" "<<a[i][j].left<<") ";
            if(a[i][j].up == 1)
                d.Union(p_to_id(i,j,n,m),p_to_id(i-1,j,n,m));
            if(a[i][j].right == 1)
                d.Union(p_to_id(i,j,n,m),p_to_id(i,j+1,n,m));
            if(a[i][j].down == 1)
                d.Union(p_to_id(i,j,n,m),p_to_id(i+1,j,n,m));
            if(a[i][j].left == 1)
                d.Union(p_to_id(i,j,n,m),p_to_id(i,j-1,n,m));
        }
        //cout<<"\n";
    }

    //Display(g);


    //d.Display();
    vector<lli> ans;
    for(int i=1;i<=(n*m);i++)
    {
        if(d.parent[i] < 0)
            ans.push_back(abs(d.parent[i]));
    }

    sort(ans.begin(),ans.end(),greater<int>());

    for(auto i:ans)
        cout<<i<<" ";

    return 0;
}
