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




void Multisource_BFS(queue<lli> nodes,map<lli,vector<lli>> &g,vector<lli> &vis,map<lli,lli> &dist)
{
    while(!nodes.empty())
    {
        lli v = nodes.front();
        nodes.pop();
        if(!vis[v])
        {
            //cout<<v<<" ";
            vis[v] = 1;
            for(auto i:g[v])
            {
                if(!vis[i])
                {
                    nodes.push(i);
                    if(dist[i] > dist[v] + 1)
                        dist[i] = dist[v] + 1;
                }
            }
        }
    }
}

void initialize_dist(lli n,map<lli,lli> &dist)
{
    for(int i=1; i<=n; i++)
        dist[i] = INT_MAX;
}

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

void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i:x)
        cout<<i.first<<" "<<i.second<<"\n";
    cout<<"\n----------------------\n";
}

void BFS(lli st,map<lli,vector<lli>> &g,vector<lli> &vis , map<lli,lli> &my_dist)
{
    my_dist[st] = 0;
    queue<lli> nodes;
    nodes.push(st);
    while(!nodes.empty())
    {
        lli v = nodes.front();
        nodes.pop();
        if(!vis[v])
        {
            //cout<<v<<" ";
            vis[v] = 1;
            for(auto i:g[v])
            {
                if(!vis[i])
                {
                    nodes.push(i);
                    if(my_dist[i] > my_dist[v] + 1)
                        my_dist[i] = my_dist[v] + 1;
                }
            }
        }
    }
}

void initialize_vis(vector<lli> &vis)
{
    for(int i=0; i<vis.size(); i++)
        vis[i] = 0;
}

bool check_for_leafs(map<lli,vector<lli>> &g,map<lli,lli> my_dist , map<lli,lli> dist)
{
    for(auto i:g)
    {
        if(i.second.size() == 1 && i.first != 1)
        {
           // cout<<"Checking for "<<i.first<<"\n";
            if(my_dist[i.first] < dist[i.first])
                return 1;
        }
    }

    return 0;

}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;

        vector<lli> vis(n+1); //vis vector
        map<lli,lli> dist; //to store min distance from any friend
        map<lli,vector<lli>> g; //graph
        queue<lli> q;
        map<lli,lli> my_dist;
        initialize_vis(vis); //reset vis
        initialize_dist(n,dist); // (reset dist to max) total nodes , dist map
        initialize_dist(n,my_dist); //(reset dist to max)

        lli x[k];

        for(int i=0; i<k; i++)
        {
            cin>>x[i];
            q.push(x[i]);
            dist[x[i]] = 0;
        }

        for(int i=1; i<=(n-1); i++)
        {
            lli x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        //Display(g);

        Multisource_BFS(q,g,vis,dist); //to calc min dist from any friend for each node
        //cout<<"\ndistance from nearest friend : \n";
        //Map_printer(dist);
        initialize_vis(vis); //reset vis
        BFS(1,g,vis,my_dist);
        //cout<<"\nmy distance : \n";
       // Map_printer(my_dist);


        if(check_for_leafs(g,my_dist,dist) == 1)
            cout<<"YES\n";
        else
            cout<<"NO\n";



        t--;
    }
    return 0;
}
