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


bool all_map_same_size(vector<map<lli,vector<lli>>> &x)
{
    lli same = x[0].size();
    for(int i=0; i<x.size(); i++)
    {
        if( x[i].size() != same )
            return 0;
    }
    return 1;
}

bool all_vector_same(vector<map<lli,vector<lli>>> &x)
{
    //cout<<"trying\n";
    vector<vector<vector<lli>>> vv;
    for(lli i=0; i<x.size(); i++) //n
    {
        vector<vector<lli>> tt;
        for(auto j:x[i]) //m
            tt.push_back(j.second); //n-> m = 1
        vv.push_back(tt);
    }
    /*
    for(int i=0; i<vv.size(); i++)
    {
        line_printer(20);
        for(int j=0; j<vv[i].size(); j++)
        {
            for(auto k:vv[i][j])
                cout<<k<<" ";
            cout<<"\n";
        }
        line_printer(20);
    } */

    for(lli j=0; j<vv[0].size(); j++) //rows->m cols->n
    {
        vector<lli> temp = vv[0][j];
        for(lli i=0; i<vv.size(); i++) //rows->n cols->m
            if(temp != vv[i][j])
                return 0;
    }
    return 1;
}

int main()
{
    //GO_FAST

    lli n,m;
    cin>>n>>m;
    vector<vector<lli>> g(n,vector<lli>(m));
    vector<map<lli,vector<lli>>> rows(n);
    vector<map<lli,vector<lli>>> cols(m);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>g[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            rows[i][g[i][j]].push_back(j);

    for(int j=0; j<m; j++)
        for(int i=0; i<n; i++)
            cols[j][g[i][j]].push_back(i);
    /*
    cout<<"Rows-\n";
    for(int i=0; i<n; i++)
        display(rows[i]);
    cout<<"Cols-\n";
    for(int i=0; i<m; i++)
        display(cols[i]); */

    if( all_map_same_size(rows) && all_map_same_size(cols) && all_vector_same(rows) && all_vector_same(cols) )
    {
        //cout<<"Possible\n";
        vector<pair<char,pair<lli,lli>>> moves;
        lli ans=0;
        if(n <= m)
        {
            lli xx[n];
            for(lli i=0; i<n; i++)
            {
                lli mini = inf;
                for(lli j=0; j<m; j++)
                    mini = min(mini,g[i][j]);

                xx[i] = mini;
                if(mini != 0)
                {
                    moves.push_back({'R',{mini,i+1}});
                    ans += mini;
                }

            }

            for(lli j=0; j<m; j++)
            {
                lli to_add=0;
                if(xx[0] != g[0][j])
                {
                    to_add = g[0][j] - xx[0];
                    moves.push_back({'C',{to_add,j+1}});
                    ans += to_add;
                }
            }

        }
        else
        {
            lli xx[m];
            for(lli j=0; j<m; j++)
            {
                lli mini = inf;
                for(lli i=0; i<n; i++)
                    mini = min(mini,g[i][j]);
                xx[j] = mini;
                if(mini != 0)
                {
                    ans += mini;
                    moves.push_back({'C',{mini,j+1}});
                }
            }
            for(lli i=0; i<n; i++)
            {
                lli to_add = 0;
                if(xx[0] != g[i][0])
                {
                    to_add = g[i][0] - xx[0];
                    ans += to_add;
                    moves.push_back({'R',{to_add,i+1}});
                }
            }
        }
        cout<<ans<<"\n";
        for(auto i:moves)
        {
            // cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<"\n";
            for(int j=0; j<i.second.first; j++)
            {
                if(i.first == 'R')
                    cout<<"row "<<i.second.second<<"\n";
                else
                    cout<<"col "<<i.second.second<<"\n";
            }
        }

    }
    else
        cout<<"-1\n";


    return 0;
}

