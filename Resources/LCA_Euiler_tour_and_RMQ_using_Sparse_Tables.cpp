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


void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

class LCA_RMQ //(range minimum querry)
{
public :
    vector<lli> path;
    bool *vis; //size->no of vertex+1
    lli *level; //size->no of vertex+1
    lli *last_occ_in_euler_tour; //size->no of vertex+1
    lli *level_array_for_rmq; //size->

    class Sparce_Table
{
public :
    vector<vector<lli>> table;
    vector<vector<lli>> table_index;
    lli rows;
    lli col;
    void Build_Table(lli a[],lli n) //n is size of array
    {
        rows = ((lli)(log2(n)) + 1);
        col = n;
        vector<lli> temp(col,0);

        for(int i=0; i<rows; i++)
        {
            table.push_back(temp);
            table_index.push_back(temp);
        }

        for(lli i=0; i<rows; i++)
        {
            for(lli j = 0; j <= n - pow(2,i) ; j++)
            {
                if(i == 0)
                {
                    table[i][j] = a[j];
                    table_index[i][j] = j;
                }
                else
                {
                    lli a = table[i-1][j];
                    lli ai = table_index[i-1][j];
                    lli b = table[i-1][(j+powl(2,i-1))];
                    lli bi = table_index[i-1][(j+powl(2,i-1))];
                    if(a < b)
                    {
                        table[i][j] = a;
                        table_index[i][j] = ai;
                    }
                    else
                    {
                        table[i][j] = b;
                        table_index[i][j] = bi;
                    }
                }
            }
        }
    }

    lli range_minimum(lli l,lli r) //l to r inclusive
    {
        lli length_of_segiment = r-l+1;
        lli row_to_search = (lli)log2(length_of_segiment);
        return min( table[row_to_search][l], table[row_to_search][(lli)(r-powl(2,row_to_search)+1)]);
    }

    lli range_minimum_id(lli l,lli r) //l to r inclusive (gives the first index of minimum no(in case minimum no appears many times))
    {
        lli length_of_segiment = r-l+1;
        lli row_to_search = (lli)log2(length_of_segiment);
        if(   table[row_to_search][l] < table[row_to_search][(lli)(r-powl(2,row_to_search)+1)] )
            return table_index[row_to_search][l];
        else
            return table_index[row_to_search][(lli)(r-powl(2,row_to_search)+1)];
    }
};

    Sparce_Table st;

    LCA_RMQ(lli root,vector<vector<lli>> &g,lli n)
    {
        vis = new bool[n]; //n = no of vertex + 1 if 1 based vertices
        level = new lli[n]; //n = no of vertex + 1 if 1 based vertices
        last_occ_in_euler_tour = new lli[n]; //n = no of vertex + 1 if 1 based vertices

        for(int i=0; i<n; i++)
        {
            vis[i] = 0;
            level[i] = -1;
            last_occ_in_euler_tour[i] = -1;
        }

        Euler_Tour(root,g,0); //calculating euler tour and level of each node

        level_array_for_rmq = new lli[path.size()];

        for(int i=0; i<path.size(); i++)
        {
            level_array_for_rmq[i] = level[path[i]]; //storing the level of each onode in Euler tour
            last_occ_in_euler_tour[path[i]] = i; //finding the last occurrence of each node in Euler tours
        }
        vector_printer(path);
        array_printer(level_array_for_rmq,path.size());
        st.Build_Table(level_array_for_rmq,path.size());
    }


    void Euler_Tour(lli v,vector<vector<lli>> &g,lli d)
    {
        vis[v] = 1;
        path.push_back(v);
        level[v] = d;
        for(auto i:g[v])
        {
            if(!vis[i])
            {
                Euler_Tour(i,g,d+1);
                path.push_back(v);
            }
        }
    }

    void Get_LCA(lli a,lli b)
    {
        lli l = min(last_occ_in_euler_tour[a],last_occ_in_euler_tour[b]);
        lli r = max(last_occ_in_euler_tour[a],last_occ_in_euler_tour[b]);
        cout<<" l ="<<l<<" r = "<<r<<"\n";
        cout<<"LCA OF "<<a<<" and "<<b<<" is = "<<path[st.range_minimum_id(l,r)]<<"\n";
    }
};





int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    vector<vector<lli>> g(n+1); //vertices starting from 1
    for(int i=0; i<n-1; i++)
    {
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    lli a,b;
    cin>>a>>b;
    LCA_RMQ lca(1,g,n+1);
    lca.Get_LCA(a,b);

    return 0;
}
