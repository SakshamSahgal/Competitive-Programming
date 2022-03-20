#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
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


void Dijkstra(vector<vector<pair<lli,lli>>> &g,vector<lli> &max_dist ,lli n,lli st)
{
    for(int i=0;i<=n;i++)
        max_dist.push_back((-inf));

    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>> pq; //{distance,vertex} //max heap

    max_dist[st] = 0;
    pq.push({0,st});
    while(!pq.empty())
    {
        lli cur_ver = pq.top().second;
        lli cur_dist = pq.top().first;
        pq.pop();
        for(auto neighbour:g[cur_ver])  //neighbour.first -> neighbour vertex && neighbour.second -> edge weight
        {
            if( max_dist[neighbour.first] < cur_dist + neighbour.second )
            {
                max_dist[neighbour.first] = cur_dist + neighbour.second;
                pq.push({cur_dist + neighbour.second,neighbour.first});
            }
        }
    }

    line_printer(20);
    for(int i=1;i<=n;i++)
       cout<<max_dist[i]<<" ";
    line_printer(20);
}

void display(vector<vector<pair<lli,lli>>> &g,lli n)
{
    cout<<"\n-------------------\n";
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"-> ";
        for(auto j:g[i])
            cout<<" {"<<j.first<<" "<<j.second<<"} ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
}

lli max_negative(vector<vector<pair<lli,lli>>> &g,lli n)
{
    lli maxx_neg = inf;
    for(lli i=1;i<=n;i++)
    {
        for(auto j:g[i])
            if(j.second < 0)
                maxx_neg = min(maxx_neg,j.second);
    }
    return maxx_neg;
}

void update_weights(vector<vector<pair<lli,lli>>> &g,lli maxx_neg,lli n)
{
    for(lli i=1;i<=n;i++)
    {
        for(auto &&j:g[i])
            j.second -= maxx_neg;
    }
}

int main()
{
    //GO_FAST

        lli n,m;
        cin>>n>>m;
        lli h[n+1];
        vector<vector<pair<lli,lli>>> g(n+1);

        for(int i=1;i<=n;i++)
            cin>>h[i];

        for(int i=0;i<m;i++)
        {
            lli x,y;
            cin>>x>>y;
            lli wt = (h[x] - h[y]);
            if(h[x] >= h[y])
            {
                g[x].push_back({y,wt});
                g[y].push_back({x,(-2*wt)});
            }
            else
            {
                g[x].push_back({y,2*wt});
                g[y].push_back({x,-wt});
            }
        }

        display(g,n);
        vector<lli> max_dist;
        lli maxx_neg = max_negative(g,n);
        cout<<"Maxx neg = "<<maxx_neg<<"\n";
        update_weights(g,maxx_neg,n);
        display(g,n);
        Dijkstra(g,max_dist,n,1);

        lli maxx = -inf;

        for(int i=1;i<=n;i++)
            maxx = max(max_dist[i],maxx);

        cout<<maxx<<"\n";
    return 0;
}
