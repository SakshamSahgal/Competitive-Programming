#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;


lli Dijkstra(map<lli,vector<pair<lli,lli>>> &g,lli st,lli ed)  //nlog(n) + log(n)
{
    map<lli,lli> minDist;

    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> pq; //{distance,vertex} //min heap

    minDist[st] = 0;
    pq.push({0,st});

    while(!pq.empty())
    {
        lli cur_ver = pq.top().second;
        lli cur_dist = pq.top().first;
        pq.pop();
        for(auto neighbour:g[cur_ver])  //neighbour.first -> neighbour vertex && neighbour.second -> edge weight
        {
            if(minDist.count(neighbour.first))
            {
                if( minDist[neighbour.first] > cur_dist + neighbour.second)
                {
                    minDist[neighbour.first] = cur_dist + neighbour.second;
                    pq.push({cur_dist + neighbour.second,neighbour.first});
                }
            }
            else
            {
                minDist[neighbour.first] = cur_dist + neighbour.second;
                pq.push({cur_dist + neighbour.second,neighbour.first});
            }

        }
    }

    return minDist[ed];
}

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

int main()
{
    GO_FAST

    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    /*

1
5 6 1 5
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
        lli n,m,st,ed;
        cin>>n>>m>>st>>ed;
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
        cout<<"min Dist btw "<<st<<" "<<ed<<" = "<<Dijkstra(g,st,ed)<<"\n";
        t--;
    }
    return 0;
}

