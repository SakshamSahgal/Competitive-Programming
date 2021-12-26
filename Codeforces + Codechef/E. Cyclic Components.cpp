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
    unordered_map<int,vector<int>> m;
public:
    bool vertex_exist(int x)
    {
        auto ptr = m.find(x);
        if(ptr != m.end() )
            return 1;
        else
            return 0;
    }

    void Add_Edge(int x,int y,bool is_directed)
    {
        m[x].push_back(y);
        if(is_directed == 0)
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

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    Graph_map g;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        g.Add_Edge(x,y,0);
    }
    //g.display();
    Graph_map temp;
    for(auto i = g.return_begin(); i!= g.return_end(); i++)
    {
        if(g.No_of_Edges_with_this_node(i->first) == 2)
        {
            temp.Add_Edge(i->first,g.return_vertex(i->first,0),1);
            temp.Add_Edge(i->first,g.return_vertex(i->first,1),1);
        }
    }

    if(temp.No_of_Nodes() < 3)
        cout<<"0\n";
    else
    {
       // temp.display();
        int c=0;
k:
        int last_visited = -1;
        int starting = -1;
        int next = -1;
        auto i = temp.return_begin();

h:
        if(temp.No_of_Nodes() != 0)
        {
            if(starting == -1)
            {

                starting = i->first;
                last_visited = starting;
                next = temp.return_vertex(i->first,0);
                //cout<<"starting = "<<starting<<" next = "<<next<<"\n";
                temp.Delete_vertex(starting);
                goto h;
            }
            else
            {
                if(temp.vertex_exist(next) == 0)
                {
                    //cout<<"not a circle\n";
                    goto k;
                }
                else
                {
                    if(temp.return_vertex(next,0) == last_visited)
                    {
                        //cout<<"found "<<next<<" ";
                        last_visited = next;
                        next = temp.return_vertex(next,1);
                       // cout<<" next = "<<next<<"\n";
                        if(next == starting)
                        {
                           // cout<<"circle complete\n";
                            temp.Delete_vertex(last_visited);
                            c++;
                            goto k;
                        }
                        else
                            temp.Delete_vertex(last_visited);
                    }
                    else
                    {
                        //cout<<"found "<<next<<" ";
                        last_visited = next;
                        next = temp.return_vertex(next,0);
                        //cout<<" next = "<<next<<"\n";
                        if(next == starting)
                        {
                           // cout<<"circle complete\n";
                            temp.Delete_vertex(last_visited);
                            c++;
                            goto k;
                        }
                        else
                            temp.Delete_vertex(last_visited);
                    }
                    goto h;
                }
            }

        }
        else
        cout<<c<<"\n";


        // temp.display();
    }


    return 0;
}

