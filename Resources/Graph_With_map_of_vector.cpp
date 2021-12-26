#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>
#include<stack>
#include<queue>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

bool marked_DFS[100000] = {0};

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

    void sort_edges_dec()
    {
        for(auto i=m.begin(); i!=m.end(); i++)
            sort(i->second.begin(),i->second.end(),greater<int>());
    }

    void sort_edges_acc()
    {
        for(auto i=m.begin(); i!=m.end(); i++)
            sort(i->second.begin(),i->second.end());
    }


    void DFS(int st_node,int n)
    {
        bool marked[n+1];
        stack<int> st;
        st.push(st_node);
        while(st.size() > 0)
        {
            int v = st.top();
            st.pop();
            if( marked[v] == 0 )
            {
                cout<<v<<" ";
                marked[v] = 1;
            }

            for(int i=0; i < m[v].size(); i++)
            {
                if( marked[ m[v][i] ] == 0 )
                    st.push( m[v][i] );
            }
        }
    }

    void DFS_Recursive(int v)
    {
        cout<<v<<" ";
        marked_DFS[v] = 1;

        for(int i=0; i < m[v].size() ; i++)
        {
            if(marked_DFS[m[v][i]] == 0)
                DFS_Recursive(m[v][i]);
        }
    }

    void BFS(int st,int n)
    {
        bool marked[n+1]= {0};
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
                for(int i=0; i < m[v].size(); i++ )
                {
                    if( marked[m[v][i]] == 0)
                        nodes.push(m[v][i]);
                }
            }
        }
    }

};



int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    Graph_map g;

    g.Add_Edge(1,4);
    g.Add_Edge(1,2);
    g.Add_Edge(4,3);
    g.Add_Edge(2,3);
    g.Add_Edge(3,10);
    g.Add_Edge(3,9);
    g.Add_Edge(2,5);
    g.Add_Edge(2,8);
    g.Add_Edge(5,8);
    g.Add_Edge(5,7);
    g.Add_Edge(8,7);
    g.Add_Edge(5,6);

    g.sort_edges_dec();
    g.display();
    cout<<"DFS === \n";
    g.DFS(1,10);
    cout<<"\nBFS === \n";
    g.sort_edges_acc();
    g.display();
    g.BFS(1,10);


    Graph_map g1;
    g1.Add_Edge(1,2);
    g1.Add_Edge(1,3);
    g1.Add_Edge(2,4);
    g1.Add_Edge(2,5);
    g1.Add_Edge(5,6);
    g1.Add_Edge(3,7);
    g1.display();
    g1.sort_edges_dec();
    cout<<"DFS in graph 2 = \n";
    g1.DFS(1,7);


    g1.sort_edges_acc();
    g1.display();
    cout<<"\nDFS in recursive graph 2 = \n";
    g1.DFS_Recursive(1);
    return 0;
}

