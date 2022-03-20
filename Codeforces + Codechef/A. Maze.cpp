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

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
            cout<<j;
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}

void display(map<lli,vector<pair<lli,lli>>> g)
{
    cout<<"\n-------------------\n";
    for(auto i:g)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<" {"<<j.first<<","<<j.second<<"} ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
}

void erase_it(lli i,lli j,map<lli,vector<pair<lli,lli>>> &g,vector<vector<char>> &x,  vector<vector<lli>> &y,lli n,lli m)
{
    cout<<"Erasing {"<<i<<","<<j<<"} \n";
    lli cur_c = y[i][j];
    y[i][j] = 0;
    x[i][j] = 'X';
    pair<lli,lli> pp = {i,j};
    auto ptr = find(g[cur_c].begin(),g[cur_c].end(),pp);
    g[cur_c].erase(ptr);

    if( i-1 >=0 && x[i-1][j] == '.' )
    {
        lli prev = y[i-1][j];
        pp = {i-1,j};
        ptr = find(g[prev].begin(),g[prev].end(),pp);
        g[prev].erase(ptr);
        y[i-1][j]--;
        g[y[i-1][j]].push_back({i-1,j});
    }
    else if( i+1 < n && x[i+1][j] == '.')
    {
        lli prev = y[i+1][j];
        pp = {i+1,j};
        ptr = find(g[prev].begin(),g[prev].end(),pp);
        g[prev].erase(ptr);
        y[i+1][j]--;
        g[y[i+1][j]].push_back({i+1,j});
    }
    else if( j-1 >= 0 && x[i][j-1] == '.' )
    {
        lli prev = y[i][j-1];
        pp = {i,j-1};
        ptr = find(g[prev].begin(),g[prev].end(),pp);
        g[prev].erase(ptr);
        y[i][j-1]--;
        g[y[i][j-1]].push_back({i,j-1});
    }
    else if( j+1 < m && x[i][j+1] == '.')
    {
        lli prev = y[i][j+1];
        pp = {i,j+1};
        ptr = find(g[prev].begin(),g[prev].end(),pp);
        g[prev].erase(ptr);
        y[i][j+1]--;
        g[y[i][j+1]].push_back({i,j+1});
    }
}

int main()
{
    //GO_FAST
    lli n,m,k;
    cin>>n>>m>>k;

    vector<vector<char>> x(n,vector<char> (m));
    vector<vector<lli>> y(n,vector<lli> (m));
    map<lli,vector<pair<lli,lli>>> g;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>x[i][j];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            lli c=0;
            if(x[i][j] == '.')
            {
                if(i-1>=0 && x[i-1][j] == '.')
                    c++;
                if( i+1 < n && x[i+1][j] == '.')
                    c++;
                if( j-1>=0 && x[i][j-1] == '.')
                    c++;
                if( j+1 < m && x[i][j+1] == '.')
                    c++;
                y[i][j] = c;
                g[c].push_back({i,j});
            }
            else
                y[i][j] = 0;
        }
    }

    Vec_2d_printer(x);
    Vec_2d_printer(y);
    display(g);
    lli i = 1;
    while(i <= 4)
    {
        while( g[i].size() != 0 )
        {
           erase_it(g[i][0].first,g[i][0].second,g,x,y,n,m);
           k--;
           display(g);
           if(k == 0)
            goto l;
        }

        i++;
    }

    l:
    Vec_2d_printer(x);
    return 0;
}

