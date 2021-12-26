#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
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
        m[y].push_back(x); //uncomment if undirected graph
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

    int return_edge_index(int x,int f)
    {
        auto map_pointer = m.find(x);
        auto ptr = find(map_pointer->second.begin(),map_pointer->second.end(),f);

        if(ptr == (map_pointer->second.end()))
            return -1;
        else
            return (ptr - map_pointer->second.begin());
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

    auto return_begin()
    {
        return m.begin();
    }
    auto return_end()
    {
        return m.end();
    }
};

set<int> alive;

int process(Graph_map g,int n)
{
    int c=1;
    bool only_smaller = 1;
    alive.insert(n);
    for(int i=1; i<n; i++)
    {
        only_smaller = 1;
        if(g.vertex_exist(i) == 1)
        {
            for(int j=0; j<g.No_of_Edges_with_this_node(i); j++)
            {
                if(g.return_vertex(i,j) > i)
                {
                    only_smaller = 0;
                    break;
                }
            }

            if(only_smaller == 1)
            {
                //only smaller friends
                alive.insert(i);
                c++;
            }

        }
        else
        {
            // no friends
            alive.insert(i);
            c++;
        }

    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    Graph_map g;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        g.Add_Edge(u,v);
    }

    //g.display();
    process(g,n);
    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        int temp;
        cin>>temp;

        if(temp == 1)
        {
            int u,v;
            cin>>u>>v;
            g.Add_Edge(u,v);
            auto ptr = alive.find(min(u,v));
            if(ptr != alive.end())
                alive.erase(ptr);
           // g.display();
        }
        else if(temp == 2)
        {
            int u,v;
            cin>>u>>v;

            g.Delete_Edge(u,g.return_edge_index(u,v));
            g.Delete_Edge(v,g.return_edge_index(v,u));

            bool hez_dead=0;

            for(int j=0; j < g.No_of_Edges_with_this_node(min(u,v)); j++)
            {
                if(g.return_vertex(min(u,v),j) > min(u,v))
                {
                    hez_dead = 1;
                    break;
                    //hez ded
                }
            }

            if(hez_dead == 0)
                alive.insert(min(u,v));

           // g.display();

        }
        else
            cout<<(alive.size())<<"\n";

    }
    return 0;
}


