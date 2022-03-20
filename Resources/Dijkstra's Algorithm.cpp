#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

void display(map<lli,vector<pair<lli,lli>>> g)
{
    cout<<"\n-------------------\n";
    for(auto i:g)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<" {"<<j.first<<" "<<j.second<<"} ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
}


void Dijkstra(map<lli,vector<pair<lli,lli>>> &g,vector<lli> &min_dist ,lli n,lli st)
{
    for(int i=0;i<=n;i++)
        min_dist.push_back(inf);

    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> pq; //{distance,vertex} //min heap

    min_dist[st] = 0;
    pq.push({0,st});

    while(!pq.empty())
    {
        lli cur_ver = pq.top().second;
        lli cur_dist = pq.top().first;
        pq.pop();
        for(auto neighbour:g[cur_ver])  //neighbour.first -> neighbour vertex && neighbour.second -> edge weight
        {
            if( min_dist[neighbour.first] > cur_dist + neighbour.second)
            {
                min_dist[neighbour.first] = cur_dist + neighbour.second;
                pq.push({cur_dist + neighbour.second,neighbour.first});
            }
        }
    }

    line_printer(20);
    for(int i=1;i<=n;i++)
        cout<<min_dist[i]<<" ";
    line_printer(20);
}


int main()
{
    //GO_FAST

    /*

    1
    5 6
    1 2 2
    1 4 1
    4 3 3
    2 3 4
    2 5 5
    3 5 1

    */
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        map<lli,vector<pair<lli,lli>>> g;
        for(int i=0; i<m; i++)
        {
            lli x,y,d;
            cin>>x>>y>>d;
            g[x].push_back({y,d});
            g[y].push_back({x,d});
        }
        display(g);
        vector<lli> min_distance;
        Dijkstra(g,min_distance,n,1);
        t--;
    }
    return 0;
}

