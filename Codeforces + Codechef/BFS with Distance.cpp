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
using namespace std;


bool marked[100000] = {0}; //0->not visited

void Display(map<lli,vector<lli>> g)
{
    cout<<"\n----------------------\n";

    for(auto i:g)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n----------------------\n";
}

map<lli,vector<lli>> g;

map<lli,lli> dist;

void BFS(int st)
{

    queue<int> nodes;

    nodes.push(st);

    while( nodes.empty() == 0)
    {
        int v = nodes.front();
        nodes.pop();
        if(marked[v] == 0)
        {
            cout<<v<<" ";
            marked[v] = 1;
            for(int i=0; i < g[v].size(); i++ )
            {
                if( marked[g[v][i]] == 0)
                    nodes.push(g[v][i]);
            }
        }
    }
}



void BFS_with_distance(lli st)
{
    queue<lli> nodes;
    nodes.push(st);
    while(!nodes.empty())
    {
        int v = nodes.front();
        nodes.pop();
        if(!marked[v])
        {
            cout<<v<<" ";
            marked[v] = 1;
            for(int i=0; i<g[v].size(); i++)
            {
                nodes.push(g[v][i]);
                if( dist[g[v][i]] > dist[v] + 1)
                    dist[g[v][i]] = dist[v] + 1;
            }
        }
    }
}

int main()
{

    lli n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        lli x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    Display(g);

   // cout<<"\n------------------------------\n";
   // cout<<"Normal BFS\n";

   // BFS(1);
  //  cout<<"\n------------------------------\n";

    cout<<"BFS with Distance : \n";

    for(int i=1; i<=n; i++)
        dist[i] = INT_MAX;

    dist[1] = 0;

    BFS_with_distance(1);
    cout<<"\n";
    for(auto i:dist)
        cout<<i.first<<" "<<i.second<<"\n";
    cout<<"\n------------------------------\n";
    return 0;
}

