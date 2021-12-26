#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
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
    int n,m,k,u,v,l;
    cin>>n>>m>>k;
    int a[k];
    int b[n+1];
    int mini = INT_MAX;
    bool found=0;
    if(k!=0 && k!=n)
    {
        Graphs g1(n+1);
        for(int i=0; i<m; i++)
        {
            cin>>u>>v>>l;
            g1.Add_Edge(u,v,l);
        }

        for(int i=0; i<k; i++)
            {
            cin>>a[i];
            b[a[i]] = 1;
            }


        //g1.Display();
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<g1.Edge_Size(a[i]); j++)
            {
                if( b[g1.return_vertex(a[i],j)] != 1 )
                {
                    found = 1;
                    if(g1.return_weight(a[i],j)<mini)
                        mini = g1.return_weight(a[i],j);
                }

            }

        }
        if(found == 1)
            cout<<mini<<"\n";
        else
            cout<<"-1\n";
    }
    else
        cout<<"-1\n";



    //g1.Add_Edge(1,2,5);
    //g1.Add_Edge(1,2,3);
    //g1.Add_Edge(2,3,4);
    //g1.Add_Edge(1,4,10);
    //g1.Display();
    return 0;
}
