#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;

//unweighted Graph
class Graphs
{
    int V;
    vector <int> *Adj_list;
public:
    Graphs(int vert)
    {
        V=vert;
        Adj_list = new vector<int>[V];
    }
    void Add_Edge(int x,int y)
    {
        Adj_list[x].push_back(y);
        //Adj_list[y].push_back(x); //undirected
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
                cout<<Adj_list[i][j]<<" ";

            cout<<"\n";
        }
    }
    int return_vertex(int i,int j)
    {
        return (Adj_list[i][j]);
    }
    void override_Edge(int i,int j,int x)
    {
        Adj_list[i][j] = x;
    }
};
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    Graphs g1(7);
    g1.Add_Edge(1,2);
    g1.Add_Edge(1,4);
    g1.Add_Edge(1,6);
    g1.Add_Edge(2,4);
    g1.Add_Edge(2,1);
    g1.Add_Edge(3,4);
    g1.Add_Edge(4,2);
    g1.Add_Edge(4,3);
    g1.Add_Edge(5,6);
    g1.Add_Edge(6,1);
    g1.Add_Edge(6,5);
    g1.Display();
    g1.override_Edge(1,0,5);
    g1.override_Edge(1,1,5);
    g1.override_Edge(1,2,5);
    g1.Display();
    return 0;
}

