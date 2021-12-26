#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
class Graph_map
{
    map<int,vector<int>> m;
public:
    bool vertex_exist(int x)
    {
        auto ptr = m.find(x);
        if(ptr != m.end() )
            return 1;
        else
            return 0;
    }

    void Add_Edge(int x,int y)
    {
        m[x].push_back(y);
        //m[y].push_back(x); //uncomment if undirected graph
    }

    int No_of_Edges_with_this_node(int x)
    {

        auto ptr = m.find(x);
        if(ptr != m.end() )
        {
            return ptr->second.size();
        }
        else
            return 0;
    }

    void display()
    {
        cout<<"\n---------------------------------------------\n";
        for(auto map_iterator = m.begin(); map_iterator!=m.end(); map_iterator++)
        {
            cout<<map_iterator->first<<" -> ";
            for(auto vector_iterator = map_iterator->second.begin(); vector_iterator != map_iterator->second.end(); vector_iterator++)
            {
                cout<<*vector_iterator<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n---------------------------------------------\n";
    }

    int return_vertex(int x,int y)
    {
        auto ptr = m.find(x);
        if(ptr != m.end() )
        {
            if(y < ptr->second.size())
                return *(ptr->second.begin()+y);
            else
                return -1;
        }
        else
            return -1;
    }
    int No_of_Nodes()
    {
        return m.size();
    }

    void Delete_Edge(int x,int y)
    {
        auto map_iterator = m.find(x);
        if(map_iterator != m.end())
        {
            if(y < map_iterator->second.size())
            {
                auto vector_iterator = map_iterator->second.begin() + y;
                map_iterator->second.erase(vector_iterator);
            }
        }
    }

    void Delete_vertex(int x)
    {
        auto map_iterator = m.find(x);
        if(map_iterator != m.end())
            m.erase(map_iterator);
    }

    auto return_graph_begin()
    {
        return m.begin();
    }
    auto return_graph_end()
    {
        return m.begin();
    }

};
void vector_printer( vector<lli> v)
{
    //cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    //cout<<"\n------------------------\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        Graph_map g;
        lli a[n];
        lli b[n];

        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=0; i<n; i++)
            cin>>b[i];

        for(int i=0; i<n; i++)
            g.Add_Edge( (a[0]+b[i])%n,i);

        //g.display();

        if(g.No_of_Edges_with_this_node(g.return_graph_begin()->first) == 1)
        {
            for(int i=0; i<n; i++)
                cout<<(a[i] + b[ (g.return_vertex(g.return_graph_begin()->first,0) + i )%n] )%n<<" ";

        }
        else
        {
            vector<lli> v1;
            vector<lli> v2;
            for(int i=0; i<n; i++)
            {
                //cout<<(a[i] + b[ (g.return_vertex(g.return_graph_begin()->first,0) + i )%n] )%n<<" ";
                v1.push_back((a[i] + b[ (g.return_vertex(g.return_graph_begin()->first,0) + i )%n] )%n);
            }

            //cout<<"\n";

            for(int i=0; i<n; i++)
            {
                //cout<<(a[i] + b[ (g.return_vertex(g.return_graph_begin()->first,1) + i )%n] )%n<<" ";
                v2.push_back((a[i] + b[ (g.return_vertex(g.return_graph_begin()->first,1) + i )%n] )%n);
            }

        if(v1<v2)
           vector_printer(v1);
        else
        vector_printer(v2);

        }
        cout<<"\n";
        t--;
    }
    return 0;
}

