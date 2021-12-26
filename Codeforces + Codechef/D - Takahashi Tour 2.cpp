#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stack>
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

    void sort_edges()
    {
        for(auto i=m.begin(); i!=m.end(); i++)
            sort(i->second.begin(),i->second.end(),greater<int>());
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
};

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    bool v[n+1];
    int st = 1;
    Graph_map g;
    for(int i=0; i<(n-1); i++)
    {
        int x,y;
        cin>>x>>y;
        g.Add_Edge(x,y);
    }
    g.sort_edges();
    g.display();
    g.DFS(2,n);
    return 0;
}


