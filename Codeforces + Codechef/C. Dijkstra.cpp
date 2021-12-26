#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
class Graphs
{
    int V;
    vector <pair<int,int>> *Adj_list;

public:
    Graphs(int vert)
    {
        V = vert;
        Adj_list =  new vector <pair<int,int>>[V];
    }

    void Add_Edge(int x,int y,int l)
    {
        Adj_list[x].push_back(make_pair(y,l));
        Adj_list[y].push_back(make_pair(x,l)); //undirected
    }

    int Edge_Size(int i)
    {
        return Adj_list[i].size();
    }

    void Display()
    {
        cout<<"\n";
        for(int i=0; i<V; i++)
        {
            cout<<i<<"-> ";
            for(int j=0; j<Adj_list[i].size(); j++)
                cout<<" ("<<Adj_list[i][j].first<<" "<<Adj_list[i][j].second<<")";
            cout<<"\n";
        }
    }

    int return_vertex(int i,int j)
    {
        return (Adj_list[i][j].first);
    }

    int return_weight(int i,int j)
    {
        return (Adj_list[i][j].second);
    }
};
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int v1,v2,w;
    Graphs g(n+1);
    for(int i=0; i<m; i++)
    {
        cin>>v1>>v2>>w;
        g.Add_Edge(v1,v2,w);
    }
     g.Display();
    int visited=0;
    multimap<int,int> distance;
   for(int i=0;i<=n;i++)
       distance[1000001] = i;
    distance[0] = 0;
    int done[n+1] = {0};
    int mini=INT_MAX;
    int next_vertex;
h:
    cout<<"Visited = "<<visited<<"\n";
    done[visited] = 1;
   // mini = INT_MAX;
    bool vertex_remaining=0;


    for(int j=0; j<g.Edge_Size(visited); j++)
    {
        vertex_remaining = 0;
        if(done[g.return_vertex(visited,j)] != 1)
        {
            vertex_remaining = 1;
            cout<<"Comparing "<<distance[visited] <<"+"<< g.return_weight(visited,j)<<" < "<<distance[g.return_vertex(visited,j)]<<"\n";
            if(distance[visited] + g.return_weight(visited,j) < distance[g.return_vertex(visited,j)])
            {
                distance[g.return_vertex(visited,j)] = (distance[visited] + g.return_weight(visited,j));
            }

            if(distance[g.return_vertex(visited,j)] < mini)
            {
                mini = distance[g.return_vertex(visited,j)];
                next_vertex = g.return_vertex(visited,j);
            }
        }
    }

    if(vertex_remaining == 1)
    {
        cout<<"NEXT Vertex = "<<next_vertex<<"\n";
        visited = next_vertex;
        goto h;
    }
    else
        {

        cout<<"ENDED \n";
        cout<<"\n Distance aarray = \n";
        for(int i=1;i<=n;i++)
        cout<<distance[i]<<" ";
        cout<<"\n";
        }







    return 0;
}
