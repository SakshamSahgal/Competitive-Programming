#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
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

void Dijkstra(vector<vector<pair<lli,lli>>> &g,vector<lli> &min_dist,lli n,lli src,vector<lli> &dest)
{

    for(int i=0; i<=n; i++)
        min_dist[i] = inf;

    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> pq; //{distance,vertex} //min heap

    min_dist[src] = 0;
    pq.push({0,src});

    while(!pq.empty())
    {
        lli cur = pq.top().second;
        lli dist = pq.top().first;
        pq.pop();
        for(auto neighbour:g[cur])
        {
            if(min_dist[neighbour.first] > dist + neighbour.second )
            {
                min_dist[neighbour.first] = dist + neighbour.second;
                dest[neighbour.first] = cur;
                pq.push({dist + neighbour.second,neighbour.first});
            }
        }
    }

    /*
    line_printer(20);
    for(int i=1;i<=n;i++)
        cout<<"Min distance of "<<src<<" from "<<i<<" = "<<min_dist[i]<<"\n";
    line_printer(20);
    */
}

void display(vector<vector<pair<lli,lli>>> g)
{
    cout<<"\n-------------------\n";
    for(int i=0;i<g.size();i++)
    {
        cout<<i<<"-> ";
        for(int j=0;j < g[i].size();j++)
            cout<<" {"<<g[i][j].first<<" "<<g[i][j].second<<"} ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
}

int main()
{
    GO_FAST
    lli n,m;
    cin>>n>>m;
    vector<lli> min_dist(n+1);
    vector<vector<pair<lli,lli>>> g(n+1);
    vector<lli> dest(n+1);
    for(int i=0; i<m; i++)
    {
        lli x,y,d;
        cin>>x>>y>>d;
        g[x].push_back({y,d});
        g[y].push_back({x,d});
    }

    //display(g);

    for(int i=1;i<=n;i++)
        dest[i] = -1;

    Dijkstra(g,min_dist,n,1,dest);


    lli cur = n;
    vector<lli> ans;
    ans.push_back(cur);
    while(cur != 1)
    {
        cur = dest[cur];
        if(cur != -1)
            ans.push_back(cur);
        else
        {
            cout<<"-1\n";
            goto l;
        }
    }

    for(auto i=ans.rbegin();i!=ans.rend();i++)
        cout<<(*i)<<" ";
    l:
    return 0;
}

