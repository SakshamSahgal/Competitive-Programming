#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;

//Weighted Graph
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
    Graphs g1(6);
    g1.Add_Edge(1,2,5);
    g1.Add_Edge(1,2,3);
    g1.Add_Edge(2,3,4);
    g1.Add_Edge(1,4,10);
    g1.Display();
    return 0;
}
